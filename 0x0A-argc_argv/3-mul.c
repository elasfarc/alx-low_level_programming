#include <stdio.h>

#define ZERO_ASCII (48)


int _pow(int base, int power);
int extract_num(char *ascii);

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Description: This is the main function of the program.
 * It takes two command-lin arguments, extracts integers from them,
 * multiplies them, and prints the result.
 *
 * Return: 0 if successful, or an error code if the number of arguments
 * is not 3.
 */
int main(int argc, char **argv)
{
	int n1, n2;

	if (argc == 3)
	{
		n1 = extract_num(argv[1]);
		n2 = extract_num(argv[2]);
		printf("%d\n", n1 * n2);
	}
	else
		printf("Error\n");
	return (0);
}


/**
 * _pow - Calculate the power of an integer.
 * @base: The base number.
 * @power: The exponent.
 *
 * Description: This function computes the result of base raised to the power.
 *
 * Return: The calculated result.
 */
int _pow(int base, int power)
{
	return (power == 0
		 ? 1
		 : base * _pow(base, power - 1));
}

/**
 * extract_num - Extract an integer from a string.
 * @ascii: The input string containing digits.
 *
 * Description: This function extracts an integer from a given string of ASCII
 * characters representing digits.
 *
 * Return: The extracted integer value.
 */
int extract_num(char *ascii)
{
	int i, n = 0, len;

	for (len = 0; ascii[len]; len++)
		;

	for (i = 0; i < len; i++)
		n += (ascii[i] - (ZERO_ASCII)) * _pow(10, len - 1 - i);

	return (n);
}
