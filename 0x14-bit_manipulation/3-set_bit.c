#include <stddef.h>
#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index.
 * @n: points to the number to be bit manipulated.
 * @index: the index, starting from 0 of the bit to be set.
 *
 * Return: 1 if it worked or -1 if an error occurred.
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	size_t bits = (sizeof(n) * 8) - 1;

	if (index > bits)
		return (-1);

	*n = *n | (1 << index);
	return (1);
}
