#include <stdio.h>

/**
 * main - entry point for the program
 *	  prints all the numbers of base 16 in lowercase, followed by a new line.
 *
 * Return: 0
 **/
int main(void)
{
	short int n = 48;

	while (n <= 57)
	{
		putchar(n);
		n++;
	}

	n = 97;

	while (n <= 102)
	{
		putchar(n);
		n++;
	}

	putchar('\n');

	return (0);
}
