#include <stddef.h>
#include <limits.h>
#include "main.h"

#define FIRST_ONE_BIT(x) ((x) > 0 ? (x) - 1 : 0)
#define IS_NEGATIVE(n) ((long int)(n) < 0 || (n == UINT_MAX))

unsigned int get_bit(unsigned long int n, unsigned int i);

/**
 * print_binary - prints the binary representation of a number.
 * @n: binary number to be printed.
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	size_t bits = sizeof(unsigned long int) * 4;
	int i, most_left_zero;

	if (IS_NEGATIVE(n))
		most_left_zero = bits;
	else
	{
		for (i = bits - 1; i >= 0; i--)
		{
			if (get_bit(n, i))
				break;
			most_left_zero = i;
		}
	}

	i = FIRST_ONE_BIT(most_left_zero);
	for (; i >= 0; i--)
		_putchar(get_bit(n, i) + '0');
}

/**
* get_bit - returnts the bit at a given index.
* @n: lens of search.
* @i: the index of bit to look at
*
* Return: 1 if the bit at the given index is 1, 0 otherwise.
*/

unsigned int get_bit(unsigned long int n, unsigned int i)
{
	return ((n & (1 << i)) ? 1 : 0);
}
