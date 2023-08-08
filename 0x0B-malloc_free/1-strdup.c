#include <stdlib.h>
#include <stdio.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 *	      which contains a copy of the string given as a parameter.
 * @str: string to be duplicated
 *
 * Return: pointer to the duplicated string or NULL
 */

char *_strdup(char *str)
{
	char *dup_str;
	short i = 0, len = 0;

	if (str == NULL)
		return (NULL);

	while (*(str + len) != '\0')
		len++;

	dup_str = (char *) malloc(sizeof(char) * len + 1);

	if (dup_str == NULL)
		return (NULL);

	while (i <= len)
	{
		*(dup_str + i) = *(str + i);
		i++;
	}

	return (dup_str == NULL
		? NULL
		: dup_str);
}

