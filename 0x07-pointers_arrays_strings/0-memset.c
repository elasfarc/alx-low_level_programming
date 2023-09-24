
/**
 * _memset - fill a byte string with a byte value.
 * @s: string to be written at.
 * @b: char to be written.
 * @n: number of bytes of values @b to be written to the string @s.
 *
 * Return: it's first argument.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = (unsigned int)b;

	return (s);
}

