#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"

/**
 * main - check the code
 * @argc: number of arguments passed to the program including the file name
 * @argv: a string list containing all the arguments passed to the program
 *
 * Return: int
 *		(0) on success
 *		(100) on failure trying to divide by zero
 *		(99) on failure providing a wrong operator
 *		(98) on failure providing wrong number of arguments
 */

int main(int argc, char **argv)
{
	int n1, n2, ans;
	char op;
	short isDivisionByZero;
	int (*operate)(int, int);

	if (argc < 4)
	{
		printf("Error\n");
		return (98);
	}

	operate = get_op_func(argv[2]);

	if (operate == NULL)
	{
		printf("Error\n");
		return (99);
	}

	op = argv[2][0];
	n1 = atoi(argv[1]);
	n2 = atoi(argv[3]);
	isDivisionByZero = (op == '/' || op == '%') && (n2 == 0);

	if (isDivisionByZero)
	{
		printf("Error\n");
		return (100);
	}

	ans = operate(n1, n2);
	printf("%d\n", ans);

	return (0);


}

