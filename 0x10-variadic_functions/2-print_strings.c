#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

#define IS_NULL(v) ((v) == NULL)

/**
 * print_strings - print strings followed by a new line.
 * @separator: the string to be printed between strings.
 * @n: number of strings passed to the function.
 *
 * Return: always void
 */

void print_strings(const char *separator, unsigned int n, ...)
{
	va_list ap;
	unsigned int i;
	char *str;

	va_start(ap, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(ap, char *);

		printf(
				"%s%s%s",
				(IS_NULL(str) ? "(nil)" : str),
				(IS_NULL(separator) || (i == n - 1) ? "" : separator),
				(i == n - 1 ? "\n" : "")
			);

	}

	va_end(ap);
}

