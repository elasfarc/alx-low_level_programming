#include <stddef.h>

char *_strncpy(char *dest, char *src, int n)
{
	int i, src_len;

	if (!dest)
		return (NULL);

	for (i = 0; src[i]; i++)
		;
	src_len = i + 1;

	for (i = 0; (i < n); i++)
		dest[i] = i >= src_len
			? '\0'
			: src[i];

	return (dest);

}
