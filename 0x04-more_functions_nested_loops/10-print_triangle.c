#include "main.h"

/**
 * print_triangle - prints a triangle, followed by a new line.
 * @size: is the size of the triangle.
 *
 * Return: always void
 */
void print_triangle(int size)
{
	short int i, j, triangles, spaces = size - 1;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = size; i > 0; i--)
	{
		for (j = spaces; j > 0; j--)
			_putchar(' ');
		for (triangles = size - spaces; triangles > 0; triangles--)
			_putchar('#');
		_putchar('\n');
		spaces--;
	}
}
