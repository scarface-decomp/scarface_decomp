// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, engine/CementLibrary.cpp (6 verified)
// GENERATED from reports/verified_registry.json by tools/registry_outputs.py. Do not edit.
// Every block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CementLibrary::vfunc_00 (0x006E6710, 11 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_Win32Drive_Cement_Audio.cpp
// ============================================================================
void* CementLibrary::vfunc_00() {
    return m_pOwner0C->m_Sub04.vfunc_00();
}

// ============================================================================
// [VERIFIED] CementLibrary::vfunc_01 (0x006E6720, 12 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_Win32Drive_Cement_Audio.cpp
// ============================================================================
void* CementLibrary::vfunc_01() {
    return m_pOwner0C->m_Sub04.vfunc_01();
}

// ============================================================================
// [VERIFIED] CementLibrary::vfunc_05 (0x006E6730, 39 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 | 2 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_Win32Drive_Cement_Audio.cpp
// ============================================================================
void CementLibrary::vfunc_05() {
    while (m_State20 == 0) {
        PollCementState();
        YieldCementThread(0);
    }
}

// ============================================================================
// [VERIFIED] CementLibrary::vfunc_07 (0x006E6760, 10 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_Win32Drive_Cement_Audio.cpp
// ============================================================================
bool CementLibrary::vfunc_07() {
    return m_State20 == 1;
}

// ============================================================================
// [VERIFIED] CementLibrary::vfunc_06 (0x006E6770, 23 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_Win32Drive_Cement_Audio.cpp
// ============================================================================
void CementLibrary::vfunc_06(ICementCallback* cb, int context) {
    m_pCallback6C = cb;
    m_Context70   = context;
    cb->OnCementCallback();
}

// ============================================================================
// [VERIFIED] CementLibrary::AddRefLocked10 (0x006E6B50, 23 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_Win32Drive_Cement_Audio.cpp
// ============================================================================
void CementLibrary::AddRefLocked10() {
    m_Lock10.AddRefLocked();
}

