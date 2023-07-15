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
	int i, j, k;

	i = ASCII_ZERO;
	while (i <= ASCII_NINE)
	{
		j = i + 1;

		while (j <= ASCII_NINE)
		{
			k = j + 1;
			while (k <= ASCII_NINE)
			{

				putchar(i);
				putchar(j);
				putchar(k);
				if (i == ASCII_NINE - 2)
					break;
				putchar(44);  /* comma */
				putchar(32); /* space */

				k++;
			}

			j++;
		}

		i++;
	}

	putchar('\n');

	return (0);
}
