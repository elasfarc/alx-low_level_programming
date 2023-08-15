#include <stdlib.h>
#include <stddef.h>
#include "dog.h"

char *_strcpy(char *);
int _strlen(char *);

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


	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	dog->name = malloc(sizeof(char) * (_strlen(name + 1)));
	if (dog->name == NULL)
	{
		free(dog->name);
		free(dog);
	}
	dog->name = name_cp;

	dog->owner = malloc(sizeof(char) * (_strlen(owner) + 1));
	if (dog->owner == NULL)
	{
		free(dog->owner);
		free(dog->name);
		free(dog);
	}
	dog->owner = owner_cp;

	dog->age = age;

	return (dog);

}

/**
 * _strlen - determine the length of a given string
 * @s: string
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * _strcpy - copy a strinig
 * @s: string to be copied
 *
 * Return: a pointer to the newly copied string
 */

char *_strcpy(char *s)
{
	short i = 0, len;
	char *copied;

	len = _strlen(s);

	copied = malloc((sizeof(char) * len) + 1);

	if (copied == NULL)
	{
		free(copied);
		return (NULL);
	}

	while (i < len)
	{
		copied[i] = s[i];
		i++;
	}

	copied[len] = '\0';

	return (copied);

}
