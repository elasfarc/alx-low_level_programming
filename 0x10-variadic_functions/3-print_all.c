#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

#define IS_NULL(x) ((x) == NULL)

/**
 * print_all - prints anything
 * @format: a list of types of arguments passed to the function
 *		c: char, i: int, f: float, s: char *
 *
 * Return: always void
 */

void print_all(const char * const format, ...)
{
	va_list ap;
	short i = 0;
	char *str, c

	va_start(ap, format);

	if (format == NULL)
	{
		printf("\n");
		return;
	}
	while (*(format + i) != '\0')
	{
		c = format[i];
		switch (c)
		{
			case 'c':
				printf("%c", va_arg(ap, int));
				break;
			case 'i':
				printf("%d", va_arg(ap, int));
				break;
			case 'f':
				printf("%f", va_arg(ap, double));
				break;
			case 's':
				str = va_arg(ap, char *);
				if (str == NULL)
					str = "(nil)";
				printf("%s", str);
				break;
		}
		if (
				(format[i + 1] != '\0') &&
				(c == 'c' || c == 'i' || c == 'f' || c == 's'))
			printf(" ,");
		i++;
	}
	printf("\n");
}

