#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a dog struct
 * @name: name of the dog.
 * @age: age of the dog.
 * @owner: name of the owner.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * dog_t - Typedef fot struct dog
 */
typedef struct dog dog_t;

void init_dog(struct dog *, char *, float, char *);
void print_dog(struct dog *);
#endif

