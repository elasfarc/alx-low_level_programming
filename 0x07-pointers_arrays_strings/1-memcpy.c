/**
 * _memcpy - copies memory area.
 * @dest: copies to
 * @src: copies from
 * @n: number of bytes to be copied.
 *
 * Return: a pointer to @dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	if (!dest || !src)
		return (dest);

	for (i = 0; i < n; i++)
		*(((char *)dest) + i) = *(((char *)src) + i);
		/*((char *)dest)[i] = ((char *)src)[i];*/

	return (dest);
}
