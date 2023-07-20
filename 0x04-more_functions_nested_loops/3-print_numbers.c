#include "main.h"

/**
 * print_numbers - prints the numbers, from 0 to 9, followed by a new line.
 *
 * Return: always 0
 */

void print_numbers(void)
{
	short int digit;

	for (digit = 48; digit <= 57; digit++)
		_putchar(digit);
	_putchar('\n');
}

