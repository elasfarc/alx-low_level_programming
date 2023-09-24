#include <stddef.h>
#include <stdio.h>

char *_strchr(char *, char);

/**
 * _strpbrk - searches a string for any of a set of bytes.
 * @s: The string to be searched.
 * @accept: The string containing the characters to search for.
 *
 * Return: A pointer to the first occurrence in `s` of any character from
 * the `accept` string, or NULL if no such character is found.
 */
char *_strpbrk(char *s, char *accept)
{
	int i;

	if (!s)
		return (NULL);

	for (i = 0; s[i]; i++)
		if (_strchr(accept, s[i]))
			return (s + i);
	return (NULL);
}

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
	{
		if (s[i] == c)
			return (s + i);
		if (s[i + 1] == c && c == '\0')
			return (s + i + 1);
	}

	return (NULL);
}
