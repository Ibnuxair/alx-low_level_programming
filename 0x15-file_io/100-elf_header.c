#include "main.h"
#include <elf.h>

/**
 * print_error_msg - prints an error message to stderr
 * @message: the error message to print
 */

void print_error_msg(char *message)
{
	dprintf(STDERR_FILENO, "Error: %s\n", message);
	exit(EXIT_STATUS);
}

/**
 * print_elf_header - prints the ELF header information to stdout
 * @header: the ELF header to print
 */

void print_elf_header(Elf_Header header)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header.e_ident[i]);
	}
	printf("\n");
	printf("  Class:                             %s\n",
	       header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n",
	       header.e_ident[EI_DATA] == ELFDATA2LSB ?
	       "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d%s\n",
	       header.e_ident[EI_VERSION],
	       header.e_ident[EI_VERSION] == EV_CURRENT ? " (current)" : "");
	printf("  OS/ABI:                            %d\n",
	       header.e_ident[EI_OSABI]);
	printf("  ABI Version:                       %d\n",
	       header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              %d\n", header.e_type);
	printf("  Entry point address:              0x%lx\n", header.e_entry);
}

/**
 * main - entry point for the program
 * @argc: the number of arguments
 * @argv: an array of pointers to the arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	char *filename = argv[1];
	int fd;
	Elf_Header header;

	if (argc != 2)
		print_error_msg("Usage: elf_header elf_filename");

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error_msg(strerror(errno));

	if (read(fd, &header, EI_NIDENT) != EI_NIDENT)
		print_error_msg(strerror(errno));

	if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
		print_error_msg("Not an ELF file");

	if (lseek(fd, 0, SEEK_SET) == -1)
		print_error_msg(strerror(errno));

	if (read(fd, &header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
		print_error_msg(strerror(errno));

	close(fd);

	print_elf_header(header);

	return (0);
}
