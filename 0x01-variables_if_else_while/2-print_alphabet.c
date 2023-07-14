#include <stdio.h>

/**
 * main -  entry point for the program
 *	   prints the alphabet in lowercase, followed by a new line.
 *
 * Return: 0
 **/
int main(void)
{
	char letter = 'a';

	while (letter != 123)
	{
		putchar(letter);
		letter += 1;
	}
	putchar('\n');

	return (0);
}

