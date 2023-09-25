#include <stdlib.h>
#include <stddef.h>

/**
 * _calloc - Allocate and initialize a block of memory for an array.
 * @nmemb: The number of elements to allocate.
 * @size: The size of each element in bytes.
 *
 * Return: A pointer to the allocated and initialized memory block,
 * or NULL on failure.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	void *arr = NULL;

	if (nmemb == 0 || size == 0)
		return (NULL);

	arr = malloc(size * nmemb);
	if (!arr)
		return (NULL);

	for (i = 0; i < nmemb * size; i++)
		((char *)arr)[i] = 0x0;

	return (arr);
}
