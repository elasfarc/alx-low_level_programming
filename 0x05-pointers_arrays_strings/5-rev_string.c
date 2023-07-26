/**
 * rev_string - a function that reverses a string.
 * @s: string to be reversed
 *
 * Return: void
 */

void rev_string(char *s)
{
	short int i, len;
	char temp;

	i = 0;
	while (s[i] != '\0')
		i++;
	len = i;

	for (i = 0; i < (len - 1) / 2; i++)
	{
		temp = s[i];
		s[i] = s[len - 1];
		s[len - 1] = temp;
		len--;
	}
}

