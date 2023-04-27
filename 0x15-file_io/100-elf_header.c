#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * error - Prints an error message to stderr and exits with status code 98.
 * @msg: The error message to print.
 */
void error(char *msg)
{
fprintf(stderr, "%s\n", msg);
exit(98);
}

/**
 * print_header - Prints the ELF header information to stdout.
 * @header: A pointer to the ELF header.
 */
void print_header(void *header)
{
int i;
Elf32_Ehdr *h32 = (Elf32_Ehdr *)header;

printf("ELF Header:\n");
printf("  Magic:   ");
for (i = 0; i < EI_NIDENT; i++)
printf("%02x ", h32->e_ident[i]);
printf("\n");
printf("  Class:           %s\n", h32->e_ident[EI_CLASS] == ELFCLASS64
? "ELF64" : "ELF32");
printf("  Data:            %s\n", h32->e_ident[EI_DATA] == ELFDATA2LSB
? "2's complement, little endian" : "2's complement, big endian");
printf("  Version:         %d (current)\n", h32->e_ident[EI_VERSION]);
printf("  OS/ABI:          %s\n", h32->e_ident[EI_OSABI] == ELFOSABI_SYSV
? "UNIX - System V" : "UNIX - unknown");
printf("  ABI Version:     %d\n", h32->e_ident[EI_ABIVERSION]);
printf("  Type:            %s\n", h32->e_type == ET_EXEC
? "EXEC (Executable file)" : h32->e_type == ET_DYN
? "DYN (Shared object file)" : "UNKNOWN");
printf("  Entry point address:   %x\n", h32->e_entry);
printf("\n");
}

/**
 * main - Main function that reads the ELF header from the specified file and
 * prints the information contained in it to stdout.
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char **argv)
{
int fd;
void *header;
ssize_t header_size;

if (argc != 2)
error("Usage: elf_header elf_filename");

fd = open(argv[1], O_RDONLY);
if (fd < 0)
error("Error opening file");

header_size = sizeof(Elf32_Ehdr);
header = malloc(header_size);

if (read(fd, (void *)header, header_size) != header_size)
error("Error reading file");

print_header(header);

free(header);
close(fd);
return (0);
}

