/*
    GOAL, IMPLEMENT ELF DL LOAD FOR PROGRAM RUNTIMES...

    1. Read Symbol Table

*/
#include "PIC_Backend.h"

uint32_t reverse_bytes(uint32_t bytes)
{
    uint32_t aux = 0;
    uint8_t byte;
    int i;

    for (i = 0; i < 32; i += 8)
    {
        byte = (bytes >> i) & 0xff;
        aux |= byte << (32 - 8 - i);
    }
    return aux;
}



//1 is error code..
int parse_elf(const char* elfFile, ElfHdr* target)
{
    FILE* file = fopen(elfFile, "rb");
    uint8_t file_header_bytes[0x40] = { 0 }; // Initialize to zero

    if (!file) {
        printf("Failure to open file %s\n", elfFile);
        return 1;
    }
    else {
        printf("Success opening file %s\n", elfFile);
    }

    if (fread_s(file_header_bytes, sizeof(file_header_bytes), sizeof(uint8_t), 32, file) != 32) {
        perror("Error reading 64 bits\n");
        fclose(file);
        return 1;
    }
    else {
        printf("Able to read 64 bits\n");
    }
    fclose(file);

    // Copy ELF magic number
    for (int i = 0; i < 4; i++) {
        target->e_magic[i] = file_header_bytes[i];
    }

    // Print ELF magic number
    
    printf("ELF magic data: ELF");
    //for (int i = 0x0; i < 0x40; i+=0x1) {
    //    printf("%02X : %d ", i, file_header_bytes[i]);
    //    
    //    if (i % 0x10) {
    //        printf("\n");
    //    }
    //}
    //
    printf("\n");

    // Print ELF class
    target->e_class = file_header_bytes[0x04];
    printf("ELF class: %u\n", target->e_class);

    // Print data encoding
    target->e_data = file_header_bytes[0x05];
    printf("Data encoding: %u\n", target->e_data);

    // Print ELF header version
    target->e_version = file_header_bytes[0x06];
    printf("ELF header version: %u\n", target->e_version);

    // Print OS/ABI identification
    target->e_osabi = file_header_bytes[0x07];
    printf("OS/ABI identification: %u\n", target->e_osabi);

    // Print ABI version
    target->e_abi_version = file_header_bytes[0x08];
    printf("ABI version: %u\n", target->e_abi_version);
    //might need to change depending on endianess...
    
    //print ELF type 
    target->e_type = file_header_bytes[0x11] << 8 | file_header_bytes[0x10];
    printf("ELF Type : %s\n",mapHexToElfType(target->e_type));

    //print machne architecture
    target->e_machine = file_header_bytes[0x13] << 8 | file_header_bytes[0x12];
    printf("Machine type : %s", mapIntToMachine(target->e_machine));
    
}
int parse64ELF(uint8_t * buffer, ElfHdr * target) {

}
int parse32ELF(uint8_t* buffer, ElfHdr* target) {

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
    ElfHdr elf;
    int code = parse_elf(path, &elf);

};
void* dlsym(void* handle, char* symbol)
{
}
int dlerror(void* handle)
{
}