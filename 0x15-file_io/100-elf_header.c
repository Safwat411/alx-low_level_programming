#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void validateElfFile(unsigned char *e_ident);
void printMagicNumbers(unsigned char *e_ident);
void printElfClass(unsigned char *e_ident);
void printElfData(unsigned char *e_ident);
void printElfVersion(unsigned char *e_ident);
void printElfAbi(unsigned char *e_ident);
void printElfOsAbi(unsigned char *e_ident);
void printElfType(unsigned int type, unsigned char *e_ident);
void printElfEntry(unsigned long int entry, unsigned char *e_ident);
void closeElfFile(int fileDescriptor);

/*
* validateElfFile - Check if a file is ELF
* @e_ident: A pointer to an array containing the ELF magic numbers.
*/
void validateElfFile(unsigned char *e_ident)
{
int i;
for (i = 0; i < 4; i++)
{
if (e_ident[i] != 127 &&
e_ident[i] != 'E' &&
e_ident[i] != 'L' &&
e_ident[i] != 'F') {
fprintf(stderr, "Error: Not an ELF file\n");
exit(98);
}
}
}

/**
 * printMagicNumbers - Prints the magic numbers of an ELF e_ident.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 */

void printMagicNumbers(unsigned char *e_ident)
{
int i;
printf(" Magic: ");

for (i = 0; i < EI_NIDENT; i++)
{
printf("%02x", e_ident[i]);

if (i == EI_NIDENT - 1)
printf("\n");

else
printf(" ");

}
}

/**
 * printElfClass - Prints the class of an ELF e_ident.
 * @e_ident: A pointer to an array containing the ELF class.
 */

void printElfClass(unsigned char *e_ident)
{
printf(" Class: ");

switch (e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}

/**
 * printElfData - Prints the data of an ELF e_ident.
 * @e_ident: A pointer to an array containing the ELF class.
 */

void printElfData(unsigned char *e_ident)
{
printf(" Data: ");

switch (e_ident[EI_DATA])
{
case ELFDATANONE:
printf("none\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}

/**
 * printElfVersion - Prints the version of an ELF e_ident.
 * @e_ident: A pointer to an array containing the ELF version.
 */

void printElfVersion(unsigned char *e_ident)
{
printf(" Version: %d", e_ident[EI_VERSION]);

switch (e_ident[EI_VERSION])
{
case EV_CURRENT:
printf(" (current)\n");
break;
default:
printf("\n");
break;
}
}

/**
 * printElfOsAbi - Prints the OS/ABI of an ELF e_ident.
 * @e_ident: A pointer to an array containing the ELF version.
 */

void printElfOsAbi(unsigned char *e_ident)
{
printf(" OS/ABI: ");

switch (e_ident[EI_OSABI])
{
case ELFOSABI_NONE:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("UNIX - HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_IRIX:
printf("UNIX - IRIX\n");
break;
case ELFOSABI_FREEBSD:
printf("UNIX - FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("UNIX - TRU64\n");
break;
case ELFOSABI_ARM:
printf("ARM\n");
break;
case ELFOSABI_STANDALONE:
printf("Standalone App\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}
}

/**
 * printElfAbi - Prints the ABI version of an ELF e_ident.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */

void printElfAbi(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * printElfType - Prints the type of an ELF e_ident.
 * @type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 */

void printElfType(unsigned int type, unsigned char *e_ident)
{
if (e_ident[EI_DATA] == ELFDATA2MSB)
type >>= 8;

printf(" Type: ");

switch (type)
{
case ET_NONE:
printf("NONE (None)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("<unknown: %x>\n", type);
}
}

/**
 * printElfEntry - Prints the entry point of an ELF e_ident.
 * @entry: The address of the ELF entry point.
 * @e_ident: A pointer to an array containing the ELF class.
 */

void printElfEntry(unsigned long int entry, unsigned char *e_ident)
{
printf(" Entry point address: ");

if (e_ident[EI_DATA] == ELFDATA2MSB)
{
entry = ((entry << 8) & 0xFF00FF00) |
((entry >> 8) & 0xFF00FF);
entry = (entry << 16) | (entry >> 16);
}

if (e_ident[EI_CLASS] == ELFCLASS32)
printf("%#x\n", (unsigned int)entry);
else
printf("%#lx\n", entry);
}

/**
 * closeElfFile - Closes an ELF file.
 * @fileDescriptor: The file descriptor of the ELF file.
 */

void closeElfFile(int fileDescriptor)
{
if (close(fileDescriptor) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fileDescriptor);
exit(98);
}
}

/**
 * main - Displays the information contained in the
 * ELF e_ident at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
Elf64_Ehdr *header;
int fileDescriptor, r;

if (argc != 2)
{
dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
exit(98);
}

fileDescriptor = open(argv[1], O_RDONLY);
if (fileDescriptor == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
header = malloc(sizeof(Elf64_Ehdr));
if (header == NULL)
{
closeElfFile(fileDescriptor);
dprintf(STDERR_FILENO, "Error: Can't allocate memory\n");
exit(98);
}

r = read(fileDescriptor, header, sizeof(Elf64_Ehdr));
if (r == -1)
{
free(header);
closeElfFile(fileDescriptor);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
exit(98);
}

validateElfFile(header->e_ident);
printf("ELF Header:\n");
printMagicNumbers(header->e_ident);
printElfClass(header->e_ident);
printElfData(header->e_ident);
printElfVersion(header->e_ident);
printElfAbi(header->e_ident);
printElfOsAbi(header->e_ident);
printElfType(header->e_type, header->e_ident);
printElfEntry(header->e_entry, header->e_ident);

free(header);
closeElfFile(fileDescriptor);
return (0);
}
