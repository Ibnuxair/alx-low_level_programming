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

	if (!filename)
		return (0);

	fp = open(filename, O_RDONLY);
	if (fp == -1)
	{
		return (0);
	}

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		perror("malloc");
		close(fp);
		return (0);
	}

	rt = read(fp, buffer, letters);
	if (rt == -1)
	{
		perror("read");
		free(buffer);
		close(fp);
		return (0);
	}

	wr = write(STDOUT_FILENO, buffer, rt);
	if (wr == -1 || wr != rt)
	{
		return (0);
	}

	free(buffer);
	close(fp);
	return (wr);
}
