#include "main.h"

/**
 * _puts_recursion - prints a string followed by a newline
 * @s: string to be printed
 *
 * Return: always void
 */

void _puts_recursion(char *s)
{
	_putchar((s[0] == '\0' ? '\n' : s[0]));

	if (*s != '\0')
		_puts_recursion(++s);
}

