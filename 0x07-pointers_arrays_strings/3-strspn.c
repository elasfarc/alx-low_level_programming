#include <stdio.h>
char *_strchr(char *s, char c);

/**
 * _strspn - calculates the length of the initial segment of a string that
 * consists of only the characters found in another string.
 * @s: The string to be searched.
 * @accept: The string containing the characters to search for.
 *
 * Return: The length of the initial segment of `s` consisting of only the
 * characters found in `accept`.
 */
unsigned int _strspn(char *s, char *accept)
{
	int i;

	for (i = 0; (s[i] && _strchr(accept, s[i])); i++)
		;

	return (i);

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
