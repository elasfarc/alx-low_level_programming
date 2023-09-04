#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int _str_len(char *s);

/**
 * create_file - creates a file.
 * @filename: The name of the file.
 * @text_content: a NULL terminated string to write to thr file.
 *
 * Return: on success: (1)
 *		on failure: (-1)
 *
 * Description: The created file must have those permissions: rw-------.
 * If the file already exists, do not change the permissions.
 * if the file already exists, truncate it
 * if filename is NULL return -1
 * if text_content is NULL create an empty file
 */
int create_file(const char *filename, char *text_content)
{
	int fd, cont_len;
	ssize_t bytes_written;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	cont_len = _str_len(text_content);
	bytes_written = write(fd, text_content, sizeof(char) * cont_len);

	close(fd);

	return (bytes_written == -1 ? -1 : 1);
}

/**
 * _str_len - return the length of the string
 * @s: the string to get it's length
 *
 * Return: the length of the string not including the null char.
 */

int _str_len(char *s)
{
	return (!s || *(s + 0) == '\0'
		? 0
		: 1 + _str_len(s + 1));
}

