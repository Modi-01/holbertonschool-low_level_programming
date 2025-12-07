#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <stdint.h>

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
 * error_exit - prints an error message to stderr and exits with 98
 * @msg: error message
 *
 * Return: void (does not return)
 */
void error_exit(const char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

/**
 * check_elf - checks that a file is an ELF file
 * @e_ident: pointer to the ELF identification bytes
 *
 * Return: void
 */
void check_elf(unsigned char *e_ident)
{
	if (e_ident[EI_MAG0] != ELFMAG0 ||
	    e_ident[EI_MAG1] != ELFMAG1 ||
	    e_ident[EI_MAG2] != ELFMAG2 ||
	    e_ident[EI_MAG3] != ELFMAG3)
		error_exit("Error: Not an ELF file");
}

/**
 * print_magic - prints the ELF magic bytes
 * @e_ident: pointer to the ELF identification bytes
 *
 * Return: void
 */
void print_magic(unsigned char *e_ident)
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
}

/**
 * print_class_data_version - prints class, data encoding and version
 * @e_ident: pointer to the ELF identification bytes
 *
 * Return: void
 */
void print_class_data_version(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("none\n");
		break;
	}

	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("none\n");
		break;
	}

	printf("  Version:                           %d",
	       e_ident[EI_VERSION]);
	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)");
	printf("\n");
}

/**
 * print_osabi_abiversion - prints OS/ABI and ABI Version
 * @e_ident: pointer to the ELF identification bytes
 *
 * Return: void
 */
void print_osabi_abiversion(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
		break;
	}

	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * print_type_entry - prints the ELF type and entry point address
 * @e_type: ELF type
 * @e_entry: entry point address
 * @e_ident: pointer to the ELF identification bytes
 *
 * Return: void
 */
void print_type_entry(uint16_t e_type, unsigned long int e_entry,
		      unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type = SWAP16(e_type);

	printf("  Type:                              ");
	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (No file type)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
		break;
	}

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		if (e_ident[EI_CLASS] == ELFCLASS32)
			e_entry = SWAP32((uint32_t)e_entry);
		else
			e_entry = SWAP64(e_entry);
	}

	printf("  Entry point address:               %#lx\n", e_entry);
}

/**
 * main - displays the information contained in the ELF header
 *        at the start of an ELF file
 * @argc: number of arguments
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on error (via exit)
 */
int main(int argc, char **argv)
{
	int fd;
	ssize_t r;
	unsigned char ident[EI_NIDENT];

	if (argc != 2)
		error_exit("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error: Can't read file");

	r = read(fd, ident, EI_NIDENT);
	if (r != EI_NIDENT)
	{
		close(fd);
		error_exit("Error: Can't read ELF header");
	}

	check_elf(ident);

	if (lseek(fd, 0, SEEK_SET) == -1)
	{
		close(fd);
		error_exit("Error: Can't lseek");
	}

	if (ident[EI_CLASS] == ELFCLASS64)
	{
		Elf64_Ehdr h64;

		r = read(fd, &h64, sizeof(h64));
		if (r != (ssize_t)sizeof(h64))
		{
			close(fd);
			error_exit("Error: Can't read ELF header");
		}
		print_magic(h64.e_ident);
		print_class_data_version(h64.e_ident);
		print_osabi_abiversion(h64.e_ident);
		print_type_entry(h64.e_type, (unsigned long)h64.e_entry,
				 h64.e_ident);
	}
	else if (ident[EI_CLASS] == ELFCLASS32)
	{
		Elf32_Ehdr h32;

		r = read(fd, &h32, sizeof(h32));
		if (r != (ssize_t)sizeof(h32))
		{
			close(fd);
			error_exit("Error: Can't read ELF header");
		}
		print_magic(h32.e_ident);
		print_class_data_version(h32.e_ident);
		print_osabi_abiversion(h32.e_ident);
		print_type_entry(h32.e_type, (unsigned long)h32.e_entry,
				 h32.e_ident);
	}
	else
	{
		close(fd);
		error_exit("Error: Unknown ELF class");
	}

	close(fd);
	return (0);
}
