#include "main.h"

/**
 * read_textfile -  reads a text file and prints it to the POSIX stdou
 * @filename: pointer to the file
 * @letters: is the number of letters it should read and print
 *
 * Return: returns the actual number of letters it could read and print
 * if the file can not be opened or read, return 0
 * if filename is NULL return 0
 * if write fails or does not write the expected amount of bytes, return 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t fp, rt, wr;

	fp = open(filename, O_RDONLY);
	if (fp == -1)
	{
		return (0);
		exit(1);
	}

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	rt = read(fp, buffer, letters);

	wr = write(STDIN_FILENO, buffer, rt);

	free(buffer);
	close(fp);
	return (wr);
}