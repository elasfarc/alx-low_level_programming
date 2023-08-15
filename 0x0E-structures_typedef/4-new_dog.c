#include <stdlib.h>
#include <stddef.h>
#include "dog.h"

char *_strcpy(char *, char *);
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
	dog_t *dog;


	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	dog->name = malloc(sizeof(char) * (_strlen((name) + 1)));
	if (dog->name == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}
	dog->name = _strcpy(name, dog->name);

	dog->owner = malloc(sizeof(char) * (_strlen(owner) + 1));
	if (dog->owner == NULL)
	{
		free(dog->owner);
		free(dog->name);
		free(dog);
		return (NULL);
	}
	dog->owner = _strcpy(owner, dog->owner);

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
 * @copied: str to be copied
 *
 * Return: a pointer to the newly copied string
 */

char *_strcpy(char *s, char *copied)
{
	short i = 0, len;

	len = _strlen(s);

	while (i < len)
	{
		copied[i] = s[i];
		i++;
	}

	copied[len] = '\0';

	return (copied);

}
