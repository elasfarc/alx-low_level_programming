#include <stdio.h>

/**
 * main - entry point for the program
 *	  prints all possible combinations of single-digit numbers.
 *
 * Return: 0
 **/
int main(void)
{
	short int ASCII_ZERO = 48;
	short int ASCII_NINE = 57;
	int i, j;

	i = ASCII_ZERO;
	while (i <= ASCII_NINE)
	{
		j = i + 1;

		while (j <= ASCII_NINE)
		{
			putchar(i);
			putchar(j);
			if (i == ASCII_NINE - 1 && j == ASCII_NINE)
				break;
			putchar(44);  /* comma */
			putchar(32); /* space */

			j++;
		}

		i++;
	}

	putchar('\n');

	return (0);
}
