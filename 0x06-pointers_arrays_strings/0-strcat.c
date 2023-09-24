#include <stddef.h>

/**
 * _strcat - Concatenate two strings.
 * @dest: A pointer to the destination string.
 * @src: A pointer to the source string.
 *
 * Return: A pointer to the destination string.
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	if (!dest)
		return (NULL);
	if (!src)
		return (dest);

	for (i = 0; dest[i] != '\0'; i++)
		;

	for ((j = 0, i += 1); src[j] != '\0'; (j++, i++))
		dest[i] = src[j];

	dest[i] = '\0';

	return (dest);
}

