#include <stdio.h>

char *_memcpy(char *, char *, unsigned int);

/**
 * simple_print_buffer - prints buffer in hexa
 * @buffer: the address of memory to print
 * @size: the size of the memory to print
 *
 * Return: Nothing.
 */
void simple_print_buffer(char *buffer, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		if (i % 10)
			printf(" ");
		if (!(i % 10) && i)
			printf("\n");
		printf("0x%02x", buffer[i]);
		i++;
	}
	printf("\n");
}

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	char buffer[] = "First, solve the problem. Then, write the code.";
	char buffer2[] = "Talk is cheap. Show me the code.";
	char *p;
	unsigned int len;
	unsigned int offset;
	unsigned int offset2;

	len = 48;
	offset = 0;
	offset2 = 0;
	simple_print_buffer(buffer, len);
	p = _memcpy(buffer + offset, buffer2 + offset2, 10);
	printf("-------------------------------------------------\n");
	simple_print_buffer(buffer, len);
	printf("-------------------------------------------------\n");
	simple_print_buffer(p, len - offset);
	return (0);
}
