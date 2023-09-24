#include <stddef.h>

/**
 * _strncat - Concatenate n characters from src to dest.
 * @dest: A pointer to the destination string.
 * @src: A pointer to the source string.
 * @n: The maximum number of characters to concatenate.
 *
 * Return: A pointer to the destination string.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	if (!dest)
		return (NULL);
	if (!src)
		return (dest);

	for (i = 0; dest[i]; i++)
		;

	for (j = 0; (src[j] && j < n); (j++, i++))
		dest[i] = src[j];

	dest[i] = '\0';

	return (dest);
}
