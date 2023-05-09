#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <elf.h>

#define BUFF_SIZE 1024
#define EXIT_STATUS 98

typedef uint64_t Elf64_Addr;
typedef uint64_t Elf64_Off;

/**
 * struct elf_header_s - ELF header structure
 * @e_ident: identifies the file as an object file and provides
 *           basic information about the object file format.
 * @e_type: specifies the object file type.
 * @e_machine: specifies the required architecture for an individual file.
 * @e_version: specifies the object file version.
 * @e_entry: virtual address to which the system first transfers control.
 * @e_phoff: program header table's file offset in bytes.
 * @e_shoff: section header table's file offset in bytes.
 */

typedef struct elf_header_s
{
	unsigned char e_ident[EI_NIDENT];
	uint16_t e_type;
	uint16_t e_machine;
	uint32_t e_version;
	Elf64_Addr e_entry;
	Elf64_Off e_phoff;
	Elf64_Off e_shoff;
} Elf_Header;

int _putchar(char c);
void print_error_msg(char *message);
void print_elf_header(Elf_Header header);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif  /*ENDIF*/
