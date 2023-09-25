#include <stdio.h>

/**
* main - prints its name, followed by a new line.
* @argc: number of args provided to the program.
* @argv: An array of strings represent the args provided to the program.
*
* Return: always 0
*/
int main(int argc __attribute__((unused)), char **argv)
{
	printf("%s\n", argv[0]);
	return (0);
}
