// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, core/MemoryDlAllocator.cpp (2 verified)
// GENERATED from reports/verified_registry.json by tools/registry_outputs.py. Do not edit.
// Every block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] MemoryDlAllocator::vfunc_06 (0x006E09E0, 28 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
bool MemoryDlAllocator::vfunc_06(unsigned int ptr) {
    if ((ptr >= m_StartAddr10 && ptr < m_EndAddr14) || ptr == 0) {
        return true;
    }
    return false;
}

// ============================================================================
// [VERIFIED] MemoryDlAllocator::vfunc_03 (0x006E0A60, 36 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 3 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
void* MemoryDlAllocator::vfunc_03(unsigned int flags) {
    this->~MemoryDlAllocator();
    if (flags & 1) {
        FreeToCorePool(g_pCoreMemoryPool, this);
    }
    return this;
}

