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
void closeElfFile(int file_descriptor);

/**
 * validateElfFile - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void validateElfFile(unsigned char *e_ident)
{
	int x;

	for (x = 0; x < 4; x++)
	{
		if (e_ident[x] != 127 &&
		    e_ident[x] != 'E' &&
		    e_ident[x] != 'L' &&
		    e_ident[x] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * printMagicNumbers - Prints the magic numbers of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void printMagicNumbers(unsigned char *e_ident)
{
	int x;

	printf(" Magic: ");

	for (x = 0; x < EI_NIDENT; x++)
	{
		printf("%02x", e_ident[x]);

		if (x == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * printElfClass - Prints the class of an ELF header.
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
 * printElfData - Prints the data of an ELF header.
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
 * printElfVersion - Prints the version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void printElfVersion(unsigned char *e_ident)
{
	 printf(" Version: %d",
			  e_ident[EI_VERSION]);

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
 * printElfOsAbi - Prints the OS/ABI of an ELF header.
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
 * printElfAbi - Prints the ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */
void printElfAbi(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n",
		e_ident[EI_ABIVERSION]);
}

/**
 * printElfType - Prints the type of an ELF header.
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
 * printElfEntry - Prints the entry point of an ELF header.
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
 * @file_descriptor: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void closeElfFile(int file_descriptor)
{
	if (close(file_descriptor) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", file_descriptor);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 * ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 * the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		closeElfFile(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		closeElfFile(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	validateElfFile(header->e_ident);
	printf("ELF Header:\n");
	printMagicNumbers(header->e_ident);
	printElfClass(header->e_ident);
	printElfData(header->e_ident);
	printElfVersion(header->e_ident);
	printElfOsAbi(header->e_ident);
	printElfAbi(header->e_ident);
	printElfType(header->e_type, header->e_ident);
	printElfEntry(header->e_entry, header->e_ident);

	free(header);
	closeElfFile(o);
	return (0);
}
