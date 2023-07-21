#include <stdio.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	fizz_buzz();
	return (0);
}


/**
 * fizz_buzz - print numbers from @n1 till @n2 followed by a nwe line
 *	       if number is multiple of 3 print "Fizz",
 *	       if number is multiple of 5 print "Buzz",
 *	       if number is multiple for both 3 && 5 print "FizzBuzz",
 *	       otherwise print the number as it is.
 *
 * @n1  starting number
 * @n2  ending number
 *
 * Return: always void
 */

void fizz_buzz(void)
{
	short int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			if (i % 3 == 0)
				printf("Fizz");
			if (i % 5 == 0)
				printf("Buzz");
		}
		else
		{
			printf("%d", i);
		}

		putchar(' ');

		if (i == 100)
			putchar('\n');
	}
}
