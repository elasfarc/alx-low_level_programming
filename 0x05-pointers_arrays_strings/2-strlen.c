/**
 * _strlen - returns the length of a string
 * @str: string to be procceced
 *
 * Return: the length of the string (int)
 */
int _strlen(char *str)
{
	int i, len;

	for (i = 0; str[i] != '\0'; i++)
		len = i + 1;

	return (len);
}
