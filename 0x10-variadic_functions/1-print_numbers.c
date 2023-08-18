#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

#define IS_NULL(v) (v == NULL)

/**
 * print_numbers - a function that prints numbers followed by a new line.
 * @separator: string to be printed between numbers.
 * @n: the number of integers passed to the function.
 *
 * Return: always void
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;

	if (n <= 0)
		return;

	va_start(ap, n);

	for (i = 0; i < n; i++)
		printf(
				"%d%s",
				va_arg(ap, int),
				(IS_NULL(separator) || (i == n - 1) ? "" : separator)
			);

	printf("\n");

	va_end(ap);
}

