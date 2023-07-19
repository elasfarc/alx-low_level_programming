#include "main.h"

/**
 * _abs - computes the absolute value of an integer
 * @i: int to be checked
 *
 * Return: the absolute value of an integer
 */
int _abs(int i)
{
	if (i >= 0)
		return (i);
	else
		return (i * -1);
}
