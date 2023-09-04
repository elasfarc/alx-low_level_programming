#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

ssize_t clean(int, char *, ssize_t);

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: the name of the file
 * @letters: the number of letters it should read and print
 *
 * Return: the actual numbers of letters it could read and print
 *		ON FAILURE: 0 if the file can not be opened or read.
 *			    0 if write fails or does not write the expected
 *				amount of bytes.
 *			    0 if @filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t bytes_read, bytes_written;
	char *data;

	if (!filename)
		return (0);

	data = malloc(sizeof(char) * letters);
	if (!data)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);


	bytes_read = read(fd, data, sizeof(char) * letters);
	if (bytes_read == -1)
		return (clean(fd, data, 0));

	bytes_written = write(STDOUT_FILENO, data, bytes_read);
	if (bytes_written == -1)
		return (clean(fd, data, 0));
	else
		return (clean(fd, data, bytes_written));

}

/**
 * clean - closes a file discriptor and free the alloccated string
 * @fd: the file discriptor
 * @s: the allocated string
 * @r: the return value.
 *
 * Return: signed size_t @r
 */

ssize_t clean(int fd, char *s, ssize_t r)
{
	close(fd);
	free(s);
	return (r);
}
