#include "main.h"

/**
 * print_most_numbers - prints the numbers, from 0 to 9 (except 2 & 4)
 *		   followed by a new line.
 *
 * Return: always 0
 */

void print_most_numbers(void)
{
	short int digit;

	for (digit = 48; digit <= 57; digit++)
	{
		if (digit == 50 || digit == 52)
			continue;
		_putchar(digit);
	}
	_putchar('\n');
}

