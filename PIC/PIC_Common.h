#pragma once

enum {
    ET_NONE = 0x00,
    ET_REL = 0x01,
    ET_EXEC = 0x02,
    ET_DYN = 0x03,
    ET_CORE = 0x04,
    ET_LOOS = 0xFE00,
    ET_HIOS = 0xFEFF,
    ET_LOPROC = 0xFF00,
    ET_HIPROC = 0xFFFF
};
typedef struct
{
    uint8_t e_magic[4]; // ELF magic number
    uint8_t e_class;    // ELF class (32-bit or 64-bit)
    uint8_t e_data;     // Data encoding (little-endian or big-endian)
    uint8_t e_version;  // ELF header version
    uint8_t e_osabi;    // OS/ABI identification
    uint8_t e_abi_version; // ABI version
    uint16_t e_type;    // Object file type
    uint16_t e_machine; // Architecture
} ElfHdr;
// Enumeration for ELF machine types
enum ElfMachineType {
    ELF_MACHINE_NONE = 0x00,
    ELF_MACHINE_ATT_WE_32100 = 0x01,
    ELF_MACHINE_SPARC = 0x02,
    ELF_MACHINE_x86 = 0x03,
    ELF_MACHINE_MOTOROLA_68000 = 0x04,
    // Add more machine types here...
    ELF_MACHINE_WDC_65C816 = 0x101,
    // Add more machine types here...
    ELF_MACHINE_MAX // To get the count of elements in the enum
};

// Function to map hex value to description
const char* mapHexToElfMachineType(int hexValue) {
    switch (hexValue) {
    case ELF_MACHINE_NONE:
        return "No specific instruction set";
    case ELF_MACHINE_ATT_WE_32100:
        return "AT&T WE 32100";
    case ELF_MACHINE_SPARC:
        return "SPARC";
    case ELF_MACHINE_x86:
        return "x86";
    case ELF_MACHINE_MOTOROLA_68000:
        return "Motorola 68000 (M68k)";
        // Add more cases for other machine types here...
    case ELF_MACHINE_WDC_65C816:
        return "WDC 65C816";
        // Add more cases for other machine types here...
    default:
        return "Unknown";
    }
}




// Function to map hex value to description
const char* mapHexToElfType(uint16_t hexValue) {
    switch (hexValue) {
    case ET_NONE:
        return "Unknown";
    case ET_REL:
        return "Relocatable file";
    case ET_EXEC:
        return "Executable file";
    case ET_DYN:
        return "Shared object";
    case ET_CORE:
        return "Core file";
    case ET_LOOS :
        return "Operating system specific";
    case ET_HIOS:
        return "Operating system specific";
    case ET_LOPROC:
        return "Processor specific";
    case ET_HIPROC:
        return "Processor specific";
    default:
        return "Unknown";
    }
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
