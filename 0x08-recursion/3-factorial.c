#include "main.h"

/**
 * factorial - returns the factorial of a given number
 * @n: number to get the factorial for
 *
 * Return: always int
 */

int factorial(int n)
{
	return (n < 0
		 ? -1
		 : n <= 1
		 ? 1
		 : n * factorial(n - 1));
}
