#include <stdlib.h>
char *init_char_arr(char *, unsigned int, char);

/**
 * create_array - creates an array of chars,
 *		  and initializes it with a specific char.
 * @size: size of the array
 * @c: character to initialize the array with
 *
 * Return: a pointer to the array or NULL if fails
 */

char *create_array(unsigned int size, char c)
{
	char *arr;

	arr = (char *) malloc(size * sizeof(char));

	return (size == 0 || arr == NULL
		? NULL
		: init_char_arr(arr, size, c));
}

/**
 * init_char_arr - initializes an array of type char
 * @arr: pointer to the base of the array
 * @size: size of the array
 * @init_char: char to init the array with
 *
 * Return: pointer to the array been init
 */
char *init_char_arr(char *arr, unsigned int size, char init_char)
{
	unsigned short int i;

	for (i = 0; i < size; i++)
		*(arr + i) = init_char;

	return (arr);
}


