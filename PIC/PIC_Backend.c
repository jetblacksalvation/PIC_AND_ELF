/*
    GOAL, IMPLEMENT ELF DL LOAD FOR PROGRAM RUNTIMES...

    1. Read Symbol Table

*/
#include "PIC_Backend.h"

typedef struct
{
    uint8_t e_ident[16];  /* Magic number and other info */
    uint16_t e_type;      /* Object file type */
    uint16_t e_machine;   /* Architecture */
    uint32_t e_version;   /* Object file version */
    uint64_t e_entry;     /* Entry point virtual address */
    uint64_t e_phoff;     /* Program header table file offset */
    uint64_t e_shoff;     /* Section header table file offset */
    uint32_t e_flags;     /* Processor-specific flags */
    uint16_t e_ehsize;    /* ELF header size in bytes */
    uint16_t e_phentsize; /* Program header table entry size */
    uint16_t e_phnum;     /* Program header table entry count */
    uint16_t e_shentsize; /* Section header table entry size */
    uint16_t e_shnum;     /* Section header table entry count */
    uint16_t e_shstrndx;  /* Section header string table index */
} Elf64Hdr;


//1 is error code..
int parse_elf(const char* elfFile, Elf64Hdr* buffer)
{
    FILE* file = fopen(elfFile, "rb");
    uint8_t file_header_bytes[8] = { 0 }; // Initialize to zero

    if (!file) {
        printf("Failure to open file %s\n", elfFile);
        return 1;
    }
    else {
        printf("Success opening file %s\n", elfFile);
    }

    if (fread_s(file_header_bytes, 8, sizeof(uint8_t), 8, file) != 8) {
        perror("Error reading 64 bits\n");
        fclose(file);
        return 1;
    }
    else {
        printf("Able to read 64 bits\n");
    }

    // Print each byte of the read header
    printf("Read header bytes: ");
    for (int i = 0; i < 8; i++) {
        printf("%02X ", file_header_bytes[i]);
    }
    printf("\n");

    // Check if the flag for 64-bit is set
    printf("Value at index 0x04: %u\n", file_header_bytes[0x04]);
    if (file_header_bytes[0x04] == 2) {
        printf("Elf was 64\n");
    }
    else if (file_header_bytes[0x04] == 1) {
        printf("Elf was 32\n");
    }
    buffer->e_type = file_header_bytes[0x04];

    fclose(file);
    return 0;


}
const char* mapIntToMachine(int value)
{
    switch (value)
    {
    case 0x00:
        return "System V";
    case 0x01:
        return "HP-UX";
    case 0x02:
        return "NetBSD";
    case 0x03:
        return "Linux";
    case 0x04:
        return "GNU Hurd";
    case 0x06:
        return "Solaris";
    case 0x07:
        return "AIX (Monterey)";
    case 0x08:
        return "IRIX";
    case 0x09:
        return "FreeBSD";
    case 0x0A:
        return "Tru64";
    case 0x0B:
        return "Novell Modesto";
    case 0x0C:
        return "OpenBSD";
    case 0x0D:
        return "OpenVMS";
    case 0x0E:
        return "NonStop Kernel";
    case 0x0F:
        return "AROS";
    case 0x10:
        return "FenixOS";
    case 0x11:
        return "Nuxi CloudABI";
    case 0x12:
        return "Stratus Technologies OpenVOS";
    default:
        return "Unknown";
    }
}

// void * dlopen(char *, int);
// void * dlsym(void*, char*);
// int    dlerror(void*);
enum
{
    RTLD_LAZY,
    RTLD_NOW,
    RTLD_GLOBAL,
    RTLD_LOCAL,
    RTLD_NODELETE,
    RTLD_NOLOAD,
    RTLD_DEEPBIND
};

typedef struct _ELF_Table
{
    int x;
};
// for internal use..
void* dlopen(char* path, int flags)
{
    Elf64Hdr elf;
    int code = parse_elf(path, &elf);

    printf("%s is path\n", path);
    printf("%s is machine type. int = %d", mapIntToMachine(elf.e_machine), elf.e_machine);
};
void* dlsym(void* handle, char* symbol)
{
}
int dlerror(void* handle)
{
}