#include <stdlib.h>
#include <stddef.h>
#include "dog.h"

char *_strcpy(char *);

/**
 * new_dog - a function that creats a new dog
 * @name: name of the dog.
 * @age: age of the dog.
 * @owner: name of the owner of the dog.
 *
 * Return: a pointer to the newly created dog OR NULL
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	char *name_cp, *owner_cp;
	dog_t *dog;

	name_cp = _strcpy(name);
	owner_cp = _strcpy(owner);

	if (name_cp == NULL || owner_cp == NULL)
		return (NULL);

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	dog->name = name_cp;
	dog->owner = owner_cp;
	dog->age = age;

	return (dog);

}

/**
 * _strcpy - copy a strinig
 * @s: string to be copied
 *
 * Return: a pointer to the newly copied string
 */

char *_strcpy(char *s)
{
	short len = 0, i = 0;
	char *copied;

	while (*(s + len) != '\0')
		len++;

	copied = malloc((sizeof(char) * len) + 1);

	if (copied == NULL)
		return (NULL);

	while (i < len)
	{
		copied[i] = s[i];
		i++;
	}

	copied[len] = '\0';

	return (copied);

}
