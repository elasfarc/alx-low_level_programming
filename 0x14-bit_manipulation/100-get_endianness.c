#include <stddef.h>
#include "main.h"

/**
 * get_endianness - checks the endianness.
 *
 * Return: 0 if big endian, 1 if little endian.
 */

int get_endianness(void)
{
	unsigned int test = 0xFF000000;
	unsigned int *p = &test;
	size_t ms_bit_start = (sizeof(test) * 8) - 1;
	size_t ms_bit_end = ms_bit_start - sizeof(test);

	unsigned short is_big_endian = 1;

	while (ms_bit_start > ms_bit_end)
	{
		if ((test & (1 << ms_bit_start)) !=
				((*(unsigned char *)p) & (1 << ms_bit_start))) {
			is_big_endian = 0;
			break;
		}
		ms_bit_start--;
	}

	return (!is_big_endian);
}

