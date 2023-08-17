#include <stddef.h>

#define IS_ZERO_LEN(x) ((x) <= 0)

/**
 * int_index - a function that searches for an integer in a list
 * @array: list of integers.
 * @size: size of the array.
 * @cmp: a compare callback.
 *
 * Return: (-1) if no element matches
 *		otherwise the index of the first element
 *		`cmp` does not return 0
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || IS_ZERO_LEN(size))
		return (-1);
	for (i = 0; i < size; i++)
		if (cmp(array[i]) != 0)
			return (i);
	return (-1);
}
