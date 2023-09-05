#ifndef _MAIN_H_
#define _MAIN_H_

/**
 * struct cp_s - copy file function's state
 * @code: represents different codes for different errors.
 * @fd1: the source file's file discreptor.
 * @fd2: the destination file's file discreptor.
 * @buffer: the string used as a buffer
 *		for reading from src and writing to dest.
 */
typedef struct cp_s
{
	int code, fd1, fd2;
	char *buffer;
} cp_t;


int _putchar(char);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);


#endif
