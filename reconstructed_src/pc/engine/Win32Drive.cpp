// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, engine/Win32Drive.cpp (5 verified)
// GENERATED from reports/verified_registry.json by tools/registry_outputs.py. Do not edit.
// Every block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] Win32Drive::vfunc_00 (0x006E7480, 14 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_Win32Drive_Cement_Audio.cpp
// ============================================================================
void Win32Drive::vfunc_00() {
    ResolveDescA(&m_DescEC);
}

// ============================================================================
// [VERIFIED] Win32Drive::vfunc_01 (0x006E7490, 14 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_Win32Drive_Cement_Audio.cpp
// ============================================================================
void Win32Drive::vfunc_01() {
    ResolveDescB(&m_DescEC);
}

// ============================================================================
// [VERIFIED] Win32Drive::vfunc_02 (0x006E74A0, 7 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_Win32Drive_Cement_Audio.cpp
// ============================================================================
char* Win32Drive::vfunc_02() {
    return m_DriveInfoE0;
}

// ============================================================================
// [VERIFIED] Win32Drive::vfunc_22 (0x006E74D0, 29 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_Win32Drive_Cement_Audio.cpp
// ============================================================================
int Win32Drive::vfunc_22(void** pHandle) {
    CloseHandle(*pHandle);
    *pHandle = (void*)-1;
    return 1;
}

// ============================================================================
// [VERIFIED] Win32Drive::vfunc_03 (0x006E78B0, 36 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 3 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_Win32Drive_Cement_Audio.cpp
// ============================================================================
void* Win32Drive::vfunc_03(unsigned int flags) {
    this->~Win32Drive();
    if (flags & 1) {
        FreeToCorePool(g_pCoreMemoryPool, this);
    }
    return this;
}

