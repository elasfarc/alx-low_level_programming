#include <stddef.h>

/**
 * array_iterator - a function the execute a function given as a parameter
 *			on each element of the array
 * @array: array of integers
 * @size: the size of the array
 * @action: the callback function
 *
 * Return: always void
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
		return;
	for (i = 0; i < size; i++)
		action(array[i]);
}
