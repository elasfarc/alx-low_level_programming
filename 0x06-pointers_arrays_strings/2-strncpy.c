#include <stddef.h>

/**
 * _strncpy - Copy up to 'n' characters from the source string
 * to the destination.
 * @dest: A pointer to the destination string.
 * @src: A pointer to the source string.
 * @n: The maximum number of characters to copy.
 *
 * Return: A pointer to the destination string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, src_len;

	if (!dest)
		return (NULL);

	for (i = 0; src[i]; i++)
		;
	src_len = i + 1;

	for (i = 0; (i < n); i++)
		dest[i] = i >= src_len
			? '\0'
			: src[i];

	return (dest);

}
