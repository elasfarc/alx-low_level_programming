#include <stdio.h>
#include "lists.h"

/**
 * print_msg - prints a predefined message
 *
 * Returns: void
 */

void __attribute__ ((constructor)) print_msg(void)
{
	char *str;

	str = "You're beat! and yet, you must allow,\n"
		"I bore my house upon my back!\n";
	printf("%s", str);
}


