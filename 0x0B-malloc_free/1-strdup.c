#include <stdlib.h>

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
	short len = 0;

	if (str == NULL)
		return (NULL);


	while (*(str + len) != '\0')
		len++;

	dup_str = (char *) malloc(sizeof(char) * len);

	return (dup_str == NULL
		? NULL
		: dup_str);
}

