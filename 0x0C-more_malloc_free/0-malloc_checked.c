#include <stdlib.h>
/**
 * malloc_checked - Allocate memory using malloc and check for
 * allocation success.
 * @b: The number of bytes to allocate.
 *
 * Return: A pointer to the allocated memory if successful.
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	if (!ptr)
		exit(98);
	return (ptr);
}
