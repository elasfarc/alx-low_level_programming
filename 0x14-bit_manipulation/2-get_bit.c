#include <stddef.h>
#include "main.h"

/**
* get_bit - returnts the bit at a given index.
* @n: lens of search.
* @index: the index of bit to look at
*
* Return: 1 if the bit at the given index is 1, 0 otherwise.
*/

int get_bit(unsigned long int n, unsigned int index)
{
	size_t bits = (sizeof(n) * 8) - 1;

	if (index > bits)
		return (-1);
	return ((n & (1 << index)) ? 1 : 0);
}

