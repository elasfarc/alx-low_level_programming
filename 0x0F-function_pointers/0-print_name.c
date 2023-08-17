#include <stddef.h>

/**
 * print_name - a function that prints a name
 * @name: name to be printed.
 * @f: callback function to be called with @name
 *
 * Return: always void
 */
void print_name(char *name, void(*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}

