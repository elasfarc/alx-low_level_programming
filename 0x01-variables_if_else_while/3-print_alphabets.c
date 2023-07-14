#include <stdio.h>

/**
 * main -  entry point for the program
 *	   prints the alphabet in lowercase and then in uppercase
 *	   followed by a new line.
 *
 * Return: 0
 **/
int main(void)
{
	char letter = 'a';

	while (letter <= 122)
	{
		putchar(letter);
		letter++;
	}
	letter = 'A';
	while (letter <= 90)
	{
		putchar(letter);
		letter++;
	}
	putchar('\n');

	return (0);
}

