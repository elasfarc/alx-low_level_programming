#include <stdio.h>
#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	fizz_buzz(1, 100);
	return (0);
}


/**
 * fizz_buzz - print numbers from @n1 till @n2 followed by a nwe line
 *	       if number is multiple of 3 print "Fizz",
 *	       if number is multiple of 5 print "Buzz",
 *	       if number is multiple for both 3 && 5 print "FizzBuzz",
 *	       otherwise print the number as it is.
 *
 * @n1: starting number
 * @n2: ending number
 *
 * Return: always void
 */

void fizz_buzz(int n1, int n2)
{
	short int i;

	for (i = n1; i <= n2; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
			printf("FizzBuzz");
		else if (i % 3 == 0)
			printf("Fizz");
		else if (i % 5 == 0)
			printf("Buzz");
		else
			printf("%d", i);

		putchar(' ');

		if (i == n2)
			putchar('\n');
	}
}
