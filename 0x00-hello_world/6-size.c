#include <stdio.h>

/**
 * main - entry point,
 * prints the size of various types on the computer it's compiled and run on
 *
 * Return: 0
 **/
int main(void)
{
	char c;
	int num;
	long lnum;
	long long llnum;
	float fnum;

	printf("Size of a char: %lu byte(s)\n", (unsigned long)sizeof(c));
	printf("Size of an int: %lu byte(s)\n", (unsigned long)sizeof(num));
	printf("Size of a long int: %lu byte(s)\n", (unsigned long)sizeof(lnum));
	printf("Size of a long long int: %lu byte(s)\n",
			(unsigned long)sizeof(llnum));
	printf("Size of a float: %lu byte(s)\n", (unsigned long)sizeof(fnum));
	return (0);
}

