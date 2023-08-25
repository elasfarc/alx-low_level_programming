/**
 * _strlen - return the length of a string
 * @s: the string.
 *
 * Return: always unsigned int - the length of the string.
 */
unsigned int _strlen(const char *s)
{
	return (s[0] == '\0'
			? 0
			: 1 + _strlen(s + 1));
}

