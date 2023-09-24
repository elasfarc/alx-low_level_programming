#include <stddef.h>

/**
 * _strchr - Search for the first occurrence of the character 'c'
 * in the string 's'.
 * @s: Pointer to a null-terminated string to be searched.
 * @c: The character to be located within the string 's'.
 *
 * Return:
 *    - If 'c' is found in 's', a pointer to the first occurrence
 *	of 'c' in 's' is returned.
 *    - If 'c' is not found in 's', a NULL pointer is returned.
 */
char *_strchr(char *s, char c)
{
	int i;

	if (!s)
		return (NULL);

	for (i = 0; s[i]; i++)
		if (s[i] == c)
			return (s + i);

	return (NULL);
}
