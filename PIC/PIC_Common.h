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
const char* mapIntToBI(int value)
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

const char* mapIntToMachine(int value) {
    switch (value) {
    case 0x00: return "No specific instruction set";
    case 0x01: return "AT&T WE 32100";
    case 0x02: return "SPARC";
    case 0x03: return "x86";
    case 0x04: return "Motorola 68000 (M68k)";
    case 0x05: return "Motorola 88000 (M88k)";
    case 0x06: return "Intel MCU";
    case 0x07: return "Intel 80860";
    case 0x08: return "MIPS";
    case 0x09: return "IBM System/370";
    case 0x0A: return "MIPS RS3000 Little-endian";
    case 0x0F: return "Hewlett-Packard PA-RISC";
    case 0x13: return "Intel 80960";
    case 0x14: return "PowerPC";
    case 0x15: return "PowerPC (64-bit)";
    case 0x16: return "S390, including S390x";
    case 0x17: return "IBM SPU/SPC";
    case 0x24: return "NEC V800";
    case 0x25: return "Fujitsu FR20";
    case 0x26: return "TRW RH-32";
    case 0x27: return "Motorola RCE";
    case 0x28: return "Arm (up to Armv7/AArch32)";
    case 0x29: return "Digital Alpha";
    case 0x2A: return "SuperH";
    case 0x2B: return "SPARC Version 9";
    case 0x2C: return "Siemens TriCore embedded processor";
    case 0x2D: return "Argonaut RISC Core";
    case 0x2E: return "Hitachi H8/300";
    case 0x2F: return "Hitachi H8/300H";
    case 0x30: return "Hitachi H8S";
    case 0x31: return "Hitachi H8/500";
    case 0x32: return "IA-64";
    case 0x33: return "Stanford MIPS-X";
    case 0x34: return "Motorola ColdFire";
    case 0x35: return "Motorola M68HC12";
    case 0x36: return "Fujitsu MMA Multimedia Accelerator";
    case 0x37: return "Siemens PCP";
    case 0x38: return "Sony nCPU embedded RISC processor";
    case 0x39: return "Denso NDR1 microprocessor";
    case 0x3A: return "Motorola Star*Core processor";
    case 0x3B: return "Toyota ME16 processor";
    case 0x3C: return "STMicroelectronics ST100 processor";
    case 0x3D: return "Advanced Logic Corp. TinyJ embedded processor family";
    case 0x3E: return "AMD x86-64";
    case 0x3F: return "Sony DSP Processor";
    case 0x40: return "Digital Equipment Corp. PDP-10";
    case 0x41: return "Digital Equipment Corp. PDP-11";
    case 0x42: return "Siemens FX66 microcontroller";
    case 0x43: return "STMicroelectronics ST9+ 8/16 bit microcontroller";
    case 0x44: return "STMicroelectronics ST7 8-bit microcontroller";
    case 0x45: return "Motorola MC68HC16 Microcontroller";
    case 0x46: return "Motorola MC68HC11 Microcontroller";
    case 0x47: return "Motorola MC68HC08 Microcontroller";
    case 0x48: return "Motorola MC68HC05 Microcontroller";
    case 0x49: return "Silicon Graphics SVx";
    case 0x4A: return "STMicroelectronics ST19 8-bit microcontroller";
    case 0x4B: return "Digital VAX";
    case 0x4C: return "Axis Communications 32-bit embedded processor";
    case 0x4D: return "Infineon Technologies 32-bit embedded processor";
    case 0x4E: return "Element 14 64-bit DSP Processor";
    case 0x4F: return "LSI Logic 16-bit DSP Processor";
    case 0x8C: return "TMS320C6000 Family";
    case 0xAF: return "MCST Elbrus e2k";
    case 0xB7: return "Arm 64-bits (Armv8/AArch64)";
    case 0xDC: return "Zilog Z80";
    case 0xF3: return "RISC-V";
    case 0xF7: return "Berkeley Packet Filter";
    case 0x101: return "WDC 65C816";
    default: return "Unknown";
    }
}