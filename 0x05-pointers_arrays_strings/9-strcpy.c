#include <stdio.h>

/**
 * _strcpy - copies the string pointed to by src,
 *	     including the terminating null byte (\0),
 *	     to the buffer pointed to by dest.
 *
 * @dest: copied to
 * @src: string to be copied
 *
 * Return: a pointer to the copied string des
 */

char *_strcpy(char *dest, char *src)
{
	unsigned short len = 0;

	while (*(src + len) != '\0')
	{
		*(dest + len) = *(src + len);
		len++;
		if (*(src + len) == '\0')
			*(dest + len) = '\0';
	}

	return (dest);
}

