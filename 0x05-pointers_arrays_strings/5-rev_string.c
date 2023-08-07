/**
 * rev_string - reverses a string
 * @s: string to be reversed
 *
 * Return: always void
 */
void rev_string(char *s)
{
	int lst_idx = 0, i, j;
	char temp;

	while (*(s + lst_idx) != '\0')
		lst_idx++;

	i = lst_idx - 1;
	j = 0;
	while (j < (i / 2))
	{
		temp = *(s + i - j);
		*(s + i - j) = *(s + j);
		*(s + j) = temp;
		j++;
	}
}

