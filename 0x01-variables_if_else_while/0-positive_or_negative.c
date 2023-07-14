#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - entry point,
 *        generate a random number every time the program is run
 *        prints whether it's positive, negative or ZERO
 *
 * Return: 0
 **/
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	if (n > 0)
		printf("%d is positive\n", n);
	else if (n < 0)
		printf("%d is negative\n", n);
	else
		printf("%d is zero\n", n);

	return (0);
}

