#include <stdio.h>

/**
 * main - entry point for the program
 *	  prints the lowercase alphabet in reverse, followed by a new line.
 *
 * Return: 0
 **/
int main(void)
{
	short int n = 122;

	while (n >= 97)
	{
		putchar(n);
		n--;
	}

	putchar('\n');

	return (0);
}
