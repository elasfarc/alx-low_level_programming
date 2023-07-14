#include <stdio.h>

/**
 * main - entry point for the program
 *	  prints all single digit numbers of base 10 from 0
 *
 * Return: 0
 **/
int main(void)
{
	short int n = 0;

	while (n <= 9)
	{
		printf("%d", n);
		n++;
	}

	putchar('\n');

	return (0);
}
