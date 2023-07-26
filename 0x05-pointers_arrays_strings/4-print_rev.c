#include "main.h"

/**
 * ptint_rev - prints a string in reverse followed by a newline
 * @s: string to be reversed
 *
 * Return: always void
 */
void print_rev(char *s)
{
	short int len = 0, i;
	
	while (s[len] != '\0')
		len++;
	if (len == 0)
		_putchar('\0');

	for (i = len - 1; i >= 0; i--)
		_putchar(s[i]);

	_putchar('\n');
}
