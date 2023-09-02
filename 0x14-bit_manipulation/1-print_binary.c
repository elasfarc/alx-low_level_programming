#include <stddef.h>
#include "main.h"

int get_bit(unsigned long int n, unsigned int i);

/**
 * print_binary - prints the binary representation of a number.
 * @n: binary number to be printed.
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	size_t bits = (sizeof(n) * 8) - 1;
	unsigned int bit, is_first_one_bit = 0;
	int i;

	for (i = bits; i >= 0; i--)
	{
		bit = get_bit(n, i);

		if (!is_first_one_bit && bit)
			is_first_one_bit = 1;
		if (is_first_one_bit)
			_putchar(bit + '0');
	}

	if (!is_first_one_bit)
		_putchar('0');
}

/**
* get_bit - returnts the bit at a given index.
* @n: lens of search.
* @i: the index of bit to look at
*
* Return: 1 if the bit at the given index is 1, 0 otherwise.
*/

int get_bit(unsigned long int n, unsigned int i)
{
	return ((n & (1UL << i)) ? 1 : 0);
}

