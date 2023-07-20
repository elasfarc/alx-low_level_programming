#include "main.h"

/**
 * print_square - prints a square, followed by a new line.
 * @size: size of the square
 *
 * Return: always void
 */

void print_square(int size)
{
	short i, j;

	for (i = size; i > 0; i--)
	{
		for (j = size; j > 0; j--)
			_putchar('#');
		_putchar('\n');
	}
}
