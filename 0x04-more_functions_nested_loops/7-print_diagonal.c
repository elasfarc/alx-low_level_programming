#include "main.h"

/**
 * print_diagonal - draws a diagonal line on the terminal
 * @n: the number of times the character \ should be printe
 *
 * Return: void
 */

void print_diagonal(int n)
{
	short int spaces = 0;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}
	for ( ; n > 0; n--)
	{
		short int i = 0;

		while (spaces > i)
		{
			_putchar(' ');
			i++;
		}
		_putchar('\\');
		_putchar('\n');
		spaces++;
	}
}
