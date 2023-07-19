#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @n: number to be processed to get it's last digit
 *
 * Return: the last digit of a number
 */
int print_last_digit(int n)
{
	int last_digit = n > 0 ? n % 10 : -n % 10;

	_putchar('0' + last_digit);
	return (last_digit);
}
