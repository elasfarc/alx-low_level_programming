#include <stdio.h>
#include <stddef.h>
#include "dog.h"

/**
 * print_dog -  a function that prints a struct dog
 * @d: a point to the struct dog to be printed.
 *
 * Return: always void
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;
	printf("Name: %s\n", (d->name == NULL ? "(nil)" : d->name));
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", (d->owner == NULL ? "(nil)" : d->owner));
}

