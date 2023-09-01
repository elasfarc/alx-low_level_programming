#include <stddef.h>
#include "main.h"

/**
 * flip_bits - returns the number of bits needed
 *		to flip to get from one number to another.
 * @n: first number.
 * @m: second numbe.
 *
 * Return: number of bits needed to be changed.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int bits = (sizeof(n) * 8) - 1;
	unsigned int changed = 0, b1, b2;

	while (bits >= 0)
	{
		b1 = n & (1UL << bits) ? 1 : 0;
		b2 = m & (1UL << bits) ? 1 : 0;
		if (b1 != b2)
			changed++;
		bits--;
	}

	return (changed);
}

