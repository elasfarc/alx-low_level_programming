#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "main.h"

#define BUFF_SIZE (1024)

/**
 * clean - perform cleaning operations
 *		closing file discreptors and free allocated memory.
 * @cp: points to cp_t type
 */
void clean(cp_t *cp)
{
	int fd1, fd2;

	if (!cp)
		return;

	fd1 = cp->fd1;
	fd2 = cp->fd2;

	if (cp->buffer)
		free(cp->buffer);
	free(cp);

	if (fd1 > -1)
		close(fd1);
	if (fd2 > -1)
		close(fd2);

}

/**
 * cp_file - copy file from to
 * @from: path to the file to be copied from
 * @to: path to the file to be copied to
 *
 * Return: pointer to a cp_t type.
 */
cp_t *cp_file(char *from, char *to)
{
	cp_t *cp;
	ssize_t r_bytes, w_bytes;

	cp = malloc(sizeof(cp_t));
	if (cp == NULL)
		return (NULL);
	cp->code = 0;
	cp->fd1 = -1;
	cp->fd2 = -1;
	cp->buffer = malloc(sizeof(char) * BUFF_SIZE);
	if (cp->buffer == NULL)
		cp->code = 1;

	cp->fd1 = from ? open(from, O_RDONLY) : -1;
	if (cp->fd1 == -1)
		cp->code = 98;
	cp->fd2 = open(to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (cp->fd2 == -1)
		cp->code = 99;

	if (cp->code != 0)
		return (cp);

	while ((r_bytes = read(cp->fd1, cp->buffer, BUFF_SIZE)) > 0)
	{
		w_bytes = write(cp->fd2, cp->buffer, r_bytes);
		if (w_bytes == -1)
			return ((cp->code = 99), cp);
	}

	if (r_bytes == -1)
		return ((cp->code = 98), cp);
	if (close(cp->fd1) == -1)
		return ((cp->code = 100), cp);
	cp->fd1 = -1;
	if (close(cp->fd2) == -1)
		return ((cp->code = 100), cp);
	cp->fd2 = -1;
	return (cp);
}

/**
 * main - check the code.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */

int main(int argc, char **argv)
{
	cp_t *cp;

	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}

	cp = cp_file(argv[1], argv[2]);

	if (!cp || cp->code == 1)
		dprintf(2, "Error: allocating memory\n");
	if (cp->code == 98)
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
	if (cp->code == 99)
		dprintf(2, "Error: Can't write to %s\n", argv[2]);
	if (cp->code == 100)
		dprintf(2, "Error: Can't close fd %d\n", cp->fd1 > -1 ? cp->fd1 : cp->fd2);

	clean(cp);

	if (cp->code != 0)
		exit(cp->code);

	return (0);
}
