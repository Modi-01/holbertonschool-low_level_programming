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

#endif /* DOG_H */
