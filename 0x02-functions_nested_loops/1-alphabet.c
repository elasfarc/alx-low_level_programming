#include "main.h"

/**
 * print_alphabet - prints the alphabet in lowercase
 *		    followed by a newline
 *
 * Return: void
 */

void print_alphabet(void)
{
	short int letter = 97;

	while (letter <= 122)
	{
		_putchar(letter);
		letter++;
	}

	_putchar('\n');

}
