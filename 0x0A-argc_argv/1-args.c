#include <stdio.h>


/**
* main - prints number of args passed to it, followed by a new line.
* @argc: number of args provided to the program.
* @argv: An array of strings represent the args provided to the program.
*
* Return: always 0
*/
int main(int argc, char **argv __attribute__((unused)))
{
	printf("%d\n", argc);
	return (0);
}
