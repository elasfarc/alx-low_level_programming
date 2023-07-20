#include "main.h"

/**
 * more_numbers - prints 10 times the numbers from 0 to 14
 *		  followed by a newline
 *
 * Return: always 0
 */

void more_numbers(void)
{
	short int i, digit, second_round = 0;

	for (i = 0; i < 10; i++)
	{
		for (digit = 48; digit <= 57; digit++)
		{
			if (second_round && digit > '4')
				break;
			if (second_round)
				_putchar('1');
			_putchar(digit);
			if (digit == '9')
			{
				digit = 47;
				second_round = 1;
			}
		}

		_putchar('\n');
		second_round = 0;
	};
}

