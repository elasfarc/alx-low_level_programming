#include <stdio.h>

/**
 * main -  entry point for the program
 *	   prints the alphabet in lowercase (except q and e),
 *	   followed by a new line.
 *
 * Return: 0
 **/
int main(void)
{
	char letter = 'a';

	while (letter <= 123)
	{
		if (letter == 'e' || letter == 'q')
		{
			letter += 1;
			continue;
		}
		putchar(letter);
		letter += 1;
	}
	putchar('\n');

	return (0);
}

