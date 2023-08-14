int power(int, int);

/**
 * _atoi - convert a string to an integer.
 * @s: string to be converted
 *
 * Return: (always int) either 0 if no number is represented
 *		or the number in string.
 */

int _atoi(char *s)
{
	short i = 0, sign = 1, first_digit_idx,
	      is_first_digit = 0, is_digit, ci, number_of_digits;
	unsigned int number = 0;

	while (s[i] != '\0')
	{
		ci = (int)s[i];
		is_digit = ci >= 48 && ci <= 57;

		if (is_first_digit && !is_digit)
			break;
		if (!is_first_digit && is_digit)
		{
			first_digit_idx = i;
			is_first_digit = 1;
		}

		if (s[i] == '-')
			sign *= -1;

		i++;
	}

	number_of_digits = i - first_digit_idx - 1;

	if (is_first_digit)
		while (first_digit_idx < i)
		{
			ci = s[first_digit_idx] - '0';
			number += ci * power(10, number_of_digits);
		       number_of_digits--;
		       first_digit_idx++;
		}

	return (number * sign);
}


/**
 * power - get the power of a number
 * @n: base
 * @p: power
 *
 * Return: int
 */
int power(int n, int p)
{
	return (p == 0
		? 1
		: n * power(n, p - 1));
}
