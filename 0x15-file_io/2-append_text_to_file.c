#include <fcntl.h>
#include <unistd.h>

int _slen(char *);

/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: is a NULL terminated string to add the end of the file.
 *
 * Return: on success 1
 *		on failure -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, cont_len;
	ssize_t w_bytes;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	cont_len = text_content ? _slen(text_content) : 0;
	w_bytes = write(fd, text_content, sizeof(char) * cont_len);

	close(fd);

	return (w_bytes == -1 ? -1 : 1);

}

/**
 * _slen - get the length of a string.
 * @s: string to get it's length.
 *
 * Return: the length of the string not including the null char
 */
int _slen(char *s)
{
	return (s[0] == '\0'
		? 0
		: 1 + _slen(s + 1));
}

