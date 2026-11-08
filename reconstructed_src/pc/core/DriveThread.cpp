// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, core/DriveThread.cpp (3 verified)
// GENERATED from reports/verified_registry.json by tools/registry_outputs.py. Do not edit.
// Every block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] DriveThread::vfunc_00 (0x006E7EB0, 11 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_Win32Drive_Cement_Audio.cpp
// ============================================================================
void DriveThread::vfunc_00() {
    ResolveDescA(m_pDesc08);
}

// ============================================================================
// [VERIFIED] DriveThread::vfunc_01 (0x006E7EC0, 11 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_Win32Drive_Cement_Audio.cpp
// ============================================================================
void DriveThread::vfunc_01() {
    ResolveDescB(m_pDesc08);
}

// ============================================================================
// [VERIFIED] DriveThread::vfunc_03 (0x006E8610, 36 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 3 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_Win32Drive_Cement_Audio.cpp
// ============================================================================
void* DriveThread::vfunc_03(unsigned int flags) {
    this->~DriveThread();
    if (flags & 1) {
        FreeToCorePool(g_pCoreMemoryPool, this);
    }
    return this;
}

