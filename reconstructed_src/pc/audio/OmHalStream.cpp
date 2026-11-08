// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/OmHalStream.cpp (4 verified)
// GENERATED from reports/verified_registry.json by tools/registry_outputs.py. Do not edit.
// Every block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] OmHalStream::vfunc_10 (0x006EBDF0, 11 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_Win32Drive_Cement_Audio.cpp
// ============================================================================
void OmHalStream::vfunc_10() {
    m_Sub1C0.ResetSub1C0();
}

// ============================================================================
// [VERIFIED] OmHalStream::vfunc_08 (0x006EBFA0, 36 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_Win32Drive_Cement_Audio.cpp
// ============================================================================
bool OmHalStream::vfunc_08(int* pOutBytes) {
    *pOutBytes = m_PendingBytes1B8;
    m_TotalBytes08 -= m_PendingBytes1B8;
    m_PendingBytes1B8 = 0;
    return true;
}

// ============================================================================
// [VERIFIED] OmHalStream::vfunc_09 (0x006EBFD0, 17 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_Win32Drive_Cement_Audio.cpp
// ============================================================================
AudioSlot16* OmHalStream::vfunc_09(int index) {
    return &m_SlotsB8[index];
}

// ============================================================================
// [VERIFIED] OmHalStream::vfunc_03 (0x006EC020, 13 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_Win32Drive_Cement_Audio.cpp
// ============================================================================
int OmHalStream::vfunc_03() {
    return InitAudioSub0C(m_Sub0C);   // add esp,4 (not pop ecx) because the result is returned
}

