#include <stddef.h>
#include "main.h"

#define ZERO_ASCII (48)

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: pointing to a string of 0 and 1 chars.
 *
 * Return: the converted number or 0
 *		if b is NULL or there's one or more chars in @b that's not 0 or 1.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int uint = 0, i = 0, blen;
	short bit, valid_binary = 1;

	blen = b ? str_len(b) : 0;

	while (blen && valid_binary)
	{
		bit = b[blen - 1] - ZERO_ASCII;
		valid_binary = bit == 0 || bit == 1;

		uint += bit * (1 << i); /* power of 2 strating from 0 */

		blen--;
		i++;
	}

	return (valid_binary ? uint : 0);
}

/**
 * str_len - return the number of chars in a string
 * @s: points to the strin.
 *
 * Return: length of the @s
 */
unsigned int str_len(const char *s)
{
	unsigned int len = 0;

	while (*(s + len) != '\0')
		len++;

	return (len);
}

