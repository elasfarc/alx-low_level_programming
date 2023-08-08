#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2D array
 * @width: width of the 2D array
 * @height: height of the 2D array
 *
 * Return: a pointer to the 2D array or NULL
 */

int **alloc_grid(int width, int height)
{
	int **_2D_arr;
	short i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	_2D_arr = malloc(sizeof(int *) * height);

	if (_2D_arr == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		*(_2D_arr + i) = malloc(sizeof(int) * width);

		for (j = 0; j < width; j++)
			*(*(_2D_arr + i) + j) = 0;
	}
	return (_2D_arr);
}

