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
	int rndNum;

	srand(time(0));
	rndNum = rand() - RAND_MAX / 2;

	if (rndNum > 0)
		printf("%d is positive\n", rndNum);
	else if (rndNum < 0)
		printf("%d is negative\n", rndNum);
	else
		printf("%d is zero\n", rndNum);

	return (0);
}

