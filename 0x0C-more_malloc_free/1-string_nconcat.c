#include <stdlib.h>
#include <stddef.h>

size_t _strlen(char *s);

/**
 * string_nconcat - Concatenate two strings, limiting the second string
 * to 'n' bytes.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The maximum number of bytes from s2 to concatenate.
 *
 * Return: A pointer to the newly allocated concatenated string,
 * or NULL on failure.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	size_t new_len, len1, len2, i, j;
	char *concated;

	s1 = s1 ? s1 : "";
	s2 = s2 ? s2 : "";
	len1 = _strlen(s1);
	len2 = _strlen(s2);
	new_len = len1 + (n >= len2 ? len2 : n) + 1;

	concated = malloc(sizeof(char) * new_len);
	if (!concated)
		return (NULL);

	for (i = 0; i < len1; i++)
		concated[i] = s1[i];
	for (j = 0; i < new_len - 1; (i++, j++))
		concated[i] = s2[j];

	concated[new_len] = '\0';

	return (concated);
}

/**
 * _strlen - Calculate the length of a string.
 * @s: The input string.
 *
 * Return: The length of the string, or 0 if 's' is NULL.
 */
size_t _strlen(char *s)
{
	size_t i;

	if (!s)
		return (0);

	for (i = 0; s[i]; i++)
		;

	return (i);
}
