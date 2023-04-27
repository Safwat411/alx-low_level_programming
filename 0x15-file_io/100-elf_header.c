#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <elf.h>

/**
* check_magic_number - Checks if the file is an ELF by comparing magic numbers
* @e_ident: An array containing the ELF header values
* Return: True if the magic numbers match, False otherwise
*/
bool check_magic_number(unsigned char *e_ident)
{
if (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3)
{
return (false);
}
return (true);
}

/**
* print_type - Determines and prints the type of ELF file
* @e_type: An integer representing the type of ELF file
* Return: None
*/
void print_type(uint16_t e_type)
{
const char *type_str;
switch (e_type)
{
case ET_NONE:
type_str = "NONE (No file type)";
break;
case ET_REL:
type_str = "REL (Relocatable file)";
break;
case ET_EXEC:
type_str = "EXEC (Executable file)";
break;
case ET_DYN:
type_str = "DYN (Shared object file)";
break;
case ET_CORE:
type_str = "CORE (Core file)";
break;
default:
type_str = "UNKNOWN";
break;
}
printf("  Type:                              %s\n", type_str);
}

/**
* main - Entry point to the ELF header parsing program
* @argc: An integer representing the number of arguments passed to the program
* @argv: A pointer to an array of characters representing the arguments passed
* Return: 0 if the program runs successfully, 1 otherwise
*/
int main(int argc, char **argv)
{
FILE *file;
unsigned char e_ident[EI_NIDENT];
uint16_t e_type;
if (argc < 2)
{
printf("Usage: %s <ELF file>\n", argv[0]);
return (1);
}
file = fopen(argv[1], "rb");
if (!file)
{
printf("Failed to open file: %s\n", argv[1]);
return (1);
}
if (fread(e_ident, 1, EI_NIDENT, file) != EI_NIDENT)
{
printf("Failed to read ELF header from file: %s\n", argv[1]);
fclose(file);
return (1);
}
if (!check_magic_number(e_ident))
{
printf("File is not an ELF file\n");
fclose(file);
return (1);
}
e_type = *(uint16_t *)&e_ident[EI_DATA];
print_type(e_type);
fclose(file);
return (0);
}

