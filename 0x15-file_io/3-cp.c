#include "main.h"

/**
 * print_error_msg - prints the error message
 * @message: message to be printed
 */

void print_error_msg(char* message)
{
	dprintf(STDERR_FILENO, "Error: %s\n", message);
}

/**
 * main - copies the content of a file to another file
 * @argc: arguments count
 * @argv[]: array of arguments
 *
 * Return: 0 always (success)
 */

int main(int argc, char* argv[])
{
	char *src_file, *dest_file, buffer[BUFF_SIZE];
	int fp_src, fp_dest;
	ssize_t read_size, write_size;

	if (argc != 3) {
		print_error_msg("Usage: cp src_file dest_file\n");
		exit(97);
	}

	src_file = argv[1];
	dest_file = argv[2];

        fp_src = open(src_file, O_RDONLY);

        fp_dest = open(dest_file, O_CREAT | O_WRONLY | O_TRUNC, 0664);

	while ((read_size = read(fp_src, buffer, BUFF_SIZE)) > 0)
	{
		write_size = write(fp_dest, buffer, read_size);
		if (write_size != read_size) {
			print_error_msg(strerror(errno));
			exit(-1);
		}
	}

	if (fp_src == -1 || read_size == -1)
	{
		print_error_msg("Error: Can't read from src_file\n");
		exit(98);
	}

	if (fp_dest == -1 || write_size == -1)
        {
                print_error_msg("Error: Can't write to dest_file\n");
                exit(99);
	}
	if (close(fp_src) == -1)
	{
		print_error_msg("Error: Can't close fp fp_src\n");
		exit(100);
	}

	if (close(fp_dest) == -1)
	{
		print_error_msg("Error: Can't close fp fp_dest\n");
		exit(100);
	}
	return (0);
}
