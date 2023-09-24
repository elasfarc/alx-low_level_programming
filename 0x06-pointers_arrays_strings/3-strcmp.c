#include <stddef.h>
#include <stdio.h>

/**
 * _strcmp - Compare two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return:
 *   - A negative integer if s1 is less than s2.
 *   - 0 if s1 and s2 are equal.
 *   - A positive integer if s1 is greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; (s1[i] && (s1[i] == s2[i])); i++)
		;
	return (s1[i] - s2[i]);
}
