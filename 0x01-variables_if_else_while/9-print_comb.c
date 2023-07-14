#include <stdio.h>

/**
 * main - entry point for the program
 *	  prints all possible combinations of single-digit numbers.
 *
 * Return: 0
 **/
int main(void)
{
	short int n = 48;

	while (n <= 57)
	{
		putchar(n);
		if (n != 57 )
		{
			putchar(44);  /* comma */
			putchar(32); /* space */
		}
		n++;
	}

	putchar('\n');

	return (0);
}
