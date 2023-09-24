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
