#include "main.h"
/**
 * print_error_msg - prints the error message
 * @message: message to be printed
 */
void print_error_msg(char *message)
{
	dprintf(STDERR_FILENO, "Error: %s\n", message);
}

/**
 * close_fd - closes file descriptor
 * @fd: file descriptor to be closed
 */
void close_fd(int fd)
{
	int x;

	x = close(fd);
	if (x == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * create_buff - allocates 1024 bytes for the buffer
 * @file: file pointer to the file we're writing to
 *
 * Return: buffer pointer
 */
char *create_buff(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * BUFF_SIZE);
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}
	return (buffer);
}

/**
 * main - copies the content of a file to another file
 * @argc: arguments count
 * @argv: array of arguments
 * Return: 0 always (success)
 */
int main(int argc, char *argv[])
{
	char *buffer;
	int fd_src, fd_dest;
	ssize_t read_size, write_size;

	if (argc != 3)
	{
		print_error_msg("Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buff(argv[2]);
	fd_src = open(argv[1], O_RDONLY);
	read_size = read(fd_src, buffer, BUFF_SIZE);
	umask(0);     /**no permissions will be removed**/
	fd_dest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	while (read_size > 0)
	{
		if (fd_src == -1 || read_size == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		write_size = write(fd_dest, buffer, read_size);
		if (fd_dest == -1 || write_size == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		read_size = read(fd_src, buffer, BUFF_SIZE);
	}
	free(buffer);
	close(fd_src);
	close(fd_dest);
	return (0);
}
