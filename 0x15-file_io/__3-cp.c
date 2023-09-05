#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * handle_error - handle the error
 * @flag: indicate the error type
 * @arg: the arg assiciated with the error
 * @code: the error code.
 */
void handle_error(int flag, char *arg, int code)
{
	char *err_msg1 = "Error: Can't read from file %s\n";
	char *err_msg2 = "Error: Can't write to %s\n";

	dprintf(2, flag == 1 ? err_msg1 : err_msg2, arg, arg);
	exit(code);
}

/**
 * cp_file - copy file from to
 * @from: path to the file to be copied from
 * @to: path to the file to be copied to
 *
 * Return: always void
 */

void cp_file(char *from, char *to)
{
	int fd1, fd2, f_close, f_close2, BUFF_SIZE = 1024;
	ssize_t r_bytes = 99, w_bytes;
	char *buffer = malloc(sizeof(char) * BUFF_SIZE);

	fd1 = open(from, O_RDONLY);
	if (fd1 == -1)
		handle_error(1, from, 98);
	fd2 = open(to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd2 == -1)
	{
		close(fd1);
		handle_error(2, to, 99);
	}
	while (r_bytes != 0)
	{
		r_bytes = read(fd1, buffer, BUFF_SIZE);
		if (r_bytes == -1)
		{
			close(fd1);
			close(fd2);
			handle_error(1, from, 98);
		}
		w_bytes = write(fd2, buffer, r_bytes);
		if (w_bytes == -1)
		{
			close(fd1);
			close(fd2);
			handle_error(2, to, 99);
		}
	}
	f_close = close(fd1);
	if (f_close == -1)
		dprintf(2, "Error: Can't close fd %d\n", fd1);
	f_close2 = close(fd2);
	if (f_close2 == -1)
		dprintf(2, "Error: Can't close fd %d\n", fd2);
	if (f_close == -1 || f_close2 == -1)
		exit(100);
	free(buffer);
}

/**
 * main - check the code.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	cp_file(argv[1], argv[2]);
	return (0);
}

