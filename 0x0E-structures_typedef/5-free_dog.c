#include <stdlib.h>
#include <stddef.h>
#include "dog.h"

/**
 * free_dog - frees memory allocated for a struct dog
 * @d: struct dog to be freed
 */

void free_dog(dog_t *d)
{
	if (d == NULL)
		return;
	free(d->name);
	free(d->owner);
	free(d);
}

