#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

#define SWAP16(x) (((x) >> 8) | ((x) << 8))
#define SWAP32(x) ((((x) >> 24) & 0x000000ff) | \
	(((x) >> 8) & 0x0000ff00) | \
	(((x) << 8) & 0x00ff0000) | \
	(((x) << 24) & 0xff000000))
#define SWAP64(x) ((((x) >> 56) & 0x00000000000000ffUL) | \
	(((x) >> 40) & 0x000000000000ff00UL) | \
	(((x) >> 24) & 0x0000000000ff0000UL) | \
	(((x) >> 8)  & 0x00000000ff000000UL) | \
	(((x) << 8)  & 0x000000ff00000000UL) | \
	(((x) << 24) & 0x0000ff0000000000UL) | \
	(((x) << 40) & 0x00ff000000000000UL) | \
	(((x) << 56) & 0xff00000000000000UL))

/**
 * print_header - prints selected fields from an ELF header
 * @e_ident: ELF identification bytes
 * @e_type: ELF file type (already fixed for endianness)
 * @e_entry: entry point address (already fixed for endianness)
 *
 * Return: void
 */
void print_header(unsigned char *e_ident,
	unsigned short e_type, unsigned long e_entry)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);
		if (i != EI_NIDENT - 1)
			printf(" ");
	}
	printf("\n");

	printf("  Class:                             ");
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("none\n");

	printf("  Data:                              ");
	if (e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("none\n");

	printf("  Version:                           %d",
		e_ident[EI_VERSION]);
	if (e_ident[EI_VERSION] == 1)
		printf(" (current)");
	printf("\n");

	printf("  OS/ABI:                            ");
	if (e_ident[EI_OSABI] == ELFOSABI_SYSV ||
	    e_ident[EI_OSABI] == ELFOSABI_NONE)
		printf("UNIX - System V\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_NETBSD)
		printf("UNIX - NetBSD\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_SOLARIS)
		printf("UNIX - Solaris\n");
	else
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);

	printf("  ABI Version:                       %d\n",
		e_ident[EI_ABIVERSION]);

	printf("  Type:                              ");
	if (e_type == ET_NONE)
		printf("NONE (No file type)\n");
	else if (e_type == ET_REL)
		printf("REL (Relocatable file)\n");
	else if (e_type == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (e_type == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (e_type == ET_CORE)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", e_type);

	printf("  Entry point address:               %#lx\n", e_entry);
}

/**
 * handle_64 - reads and prints ELF64 header
 * @fd: file descriptor
 * @e_ident: ELF identification bytes
 *
 * Return: void
 */
void handle_64(int fd, unsigned char *e_ident)
{
	Elf64_Ehdr h64;
	ssize_t r;
	unsigned short type;
	unsigned long entry;

	r = read(fd, &h64, sizeof(h64));
	if (r != (ssize_t)sizeof(h64))
	{
		printf("Error: Can't read ELF header\n");
		exit(98);
	}

	type = h64.e_type;
	entry = (unsigned long)h64.e_entry;

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		type = SWAP16(type);
		entry = SWAP64(entry);
	}

	print_header(e_ident, type, entry);
}

/**
 * handle_32 - reads and prints ELF32 header
 * @fd: file descriptor
 * @e_ident: ELF identification bytes
 *
 * Return: void
 */
void handle_32(int fd, unsigned char *e_ident)
{
	Elf32_Ehdr h32;
	ssize_t r;
	unsigned short type;
	unsigned long entry;

	r = read(fd, &h32, sizeof(h32));
	if (r != (ssize_t)sizeof(h32))
	{
		printf("Error: Can't read ELF header\n");
		exit(98);
	}

	type = h32.e_type;
	entry = (unsigned long)h32.e_entry;

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		type = SWAP16(type);
		entry = (unsigned long)SWAP32((unsigned int)entry);
	}

	print_header(e_ident, type, entry);
}

/**
 * main - displays information from the ELF header of a file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on error (via exit)
 */
int main(int argc, char **argv)
{
	int fd;
	ssize_t r;
	unsigned char e_ident[EI_NIDENT];

	if (argc != 2)
	{
		printf("Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	r = read(fd, e_ident, EI_NIDENT);
	if (r != EI_NIDENT)
	{
		printf("Error: Can't read ELF header\n");
		close(fd);
		exit(98);
	}

	if (e_ident[EI_MAG0] != ELFMAG0 ||
	    e_ident[EI_MAG1] != ELFMAG1 ||
	    e_ident[EI_MAG2] != ELFMAG2 ||
	    e_ident[EI_MAG3] != ELFMAG3)
	{
		printf("Error: Not an ELF file\n");
		close(fd);
		exit(98);
	}

	if (lseek(fd, 0, SEEK_SET) == -1)
	{
		printf("Error: Can't lseek\n");
		close(fd);
		exit(98);
	}

	if (e_ident[EI_CLASS] == ELFCLASS64)
		handle_64(fd, e_ident);
	else if (e_ident[EI_CLASS] == ELFCLASS32)
		handle_32(fd, e_ident);
	else
	{
		printf("Error: Invalid ELF class\n");
		close(fd);
		exit(98);
	}

	if (close(fd) == -1)
	{
		printf("Error: Can't close file\n");
		exit(98);
	}

	return (0);
}
