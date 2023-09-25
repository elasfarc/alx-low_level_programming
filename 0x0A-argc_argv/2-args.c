#include <stddef.h>
#include <stdio.h>


/**
* main - prints number of args passed to it, followed by a new line.
* @argc: number of args provided to the program.
* @argv: An array of strings represent the args provided to the program.
*
* Return: always 0
*/
int main(int argc __attribute__((unused)), char **argv)
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
		printf("%s\n", argv[i]);

	return (0);
}
