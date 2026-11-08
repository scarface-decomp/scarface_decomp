// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, core/MemoryAllocatorMalloc.cpp (4 verified)
// GENERATED from reports/verified_registry.json by tools/registry_outputs.py. Do not edit.
// Every block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] MemoryAllocatorMalloc::vfunc_04 (0x006DF730, 26 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
void* MemoryAllocatorMalloc::vfunc_04(unsigned int size) {
    if (size == 0) {
        size = 1;
    }
    return malloc(size);
}

// ============================================================================
// [VERIFIED] MemoryAllocatorMalloc::vfunc_05 (0x006DF750, 15 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
void MemoryAllocatorMalloc::vfunc_05(void* ptr) {
    free(ptr);
}

// ============================================================================
// [VERIFIED] MemoryAllocatorMalloc::vfunc_07 (0x006DF760, 21 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
void* MemoryAllocatorMalloc::vfunc_07(unsigned int a, unsigned int b) {
    return AlignedAllocHelper(a, b);
}

// ============================================================================
// [VERIFIED] MemoryAllocatorMalloc::vfunc_08 (0x006DF7C0, 22 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
void MemoryAllocatorMalloc::vfunc_08(void* ptr) {
    if (ptr) {
        free(*((void**)ptr - 1));
    }
}

