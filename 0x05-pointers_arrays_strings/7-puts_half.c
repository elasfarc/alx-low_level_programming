#include "main.h"

/**
 * puts_half - prints the second half of a string,
 *	       followed by a new line.
 * @str: string to be printed
 *
 * Return: always void
 */
void puts_half(char *str)
{
	int len = 0, i;

	while (*(str + len) != '\0')
		len++;
	
	i = (len + 1 ) / 2;
	while (i < len)
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}

