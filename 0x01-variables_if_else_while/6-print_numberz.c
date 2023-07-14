#include <stdio.h>

/**
 * main -  entry point for the program
 *	   prints all single digit numbers of base 10
 *	   starting from 0,
 *	   followed by a new line.
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

	putchar('\n');

	return (0);
}

