#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - entry point for the program
 *	  generate a random number every time the program is run
 *	  prints if the last digit in the number is > 5, == 0 or < 6
 *
 * Return: 0
 **/
int main(void)
{
	int n;
	char *str = "Last digit of";

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	if (n % 10 > 5)
		printf("%s %d is %d and is greater than 5\n", str, n, n % 10);
	else if (n % 10 == 0)
		printf("%s %d is %d and is 0\n", str, n, n % 10);
	else
		printf("%s %d is %d and is less than 6 and not 0\n", str, n, n % 10);

	return (0);
}

