#include <stdlib.h>
#include <stdio.h>
short should_loop(char *s, short i);

/**
 * str_concat - a function that concatenates two strings.
 * @s1: first string
 * @s2: second string
 *
 * Return: Null on failure or a pointer points to the newly concatenated string
 */

char *str_concat(char *s1, char *s2)
{
	char *s3;
	unsigned short int len1 = 0, len2 = 0, len3, i = 0, j = 0;
	short is_s1 = should_loop(s1, len1);
	short is_s2 = should_loop(s2, len2);

	while (is_s1 || is_s2)
	{
		if (is_s1)
			len1++;
		if (is_s2)
			len2++;

		is_s1 = should_loop(s1, len1);
		is_s2 = should_loop(s2, len2);
	}

	len3 = len1 + len2 + 1;

	s3 = (char *) malloc(sizeof(char) * len3);
	if (s3 == NULL)
		return (NULL);

	while (i < len1 && len1 > 0)
	{
		*(s3 + i) = *(s1 + i);
		i++;
	}
	while (i < len1 + len2 && len2 > 0)
	{
		*(s3 + i) = *(s2 + j);
		j++;
		i++;
	}

	*(s3 + i) = '\0';

	return (s3);
}

/**
 * should_loop - determine if a giving string reached a null char
 *		  and it's value is not NULL
 * @s: string to be checked
 * @i: index of the current loop round
 *
 * Return: (1) if should keep iterating otherwise (0)
 */

short should_loop(char *s, short i)
{
	return (s != NULL && *(s + i) != '\0');
}

