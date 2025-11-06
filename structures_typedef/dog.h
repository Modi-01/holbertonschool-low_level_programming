#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a dog's basic info
 * @name: pointer to the dog's name
 * @age: dog's age
 * @owner: pointer to the owner's name
 *
 * Description: Defines a new type struct dog to store
 * the basic information about a dog.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/* New type definition for struct dog */
typedef struct dog dog_t;

/**
 * init_dog - initializes a variable of type struct dog
 * @d: pointer to struct dog to initialize
 * @name: pointer to name
 * @age: dog's age
 * @owner: pointer to owner's name
 */
void init_dog(struct dog *d, char *name, float age, char *owner);

/**
 * print_dog - prints a struct dog
 * @d: pointer to struct dog to print
 *
 * Description: Prints the name, age, and owner of a dog.
 * If any element is NULL, it prints (nil) instead.
 * If d is NULL, the function prints nothing.
 */
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif /* DOG_H */
