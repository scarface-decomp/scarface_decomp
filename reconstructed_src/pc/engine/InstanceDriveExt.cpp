// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, engine/InstanceDriveExt.cpp (3 verified)
// GENERATED from reports/verified_registry.json by tools/registry_outputs.py. Do not edit.
// Every block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] InstanceDriveExt::vfunc_18 (0x006E5960, 26 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_Win32Drive_Cement_Audio.cpp
// ============================================================================
void InstanceDriveExt::vfunc_18(int a) {
    vfunc_11(a);
    vfunc_23();
}

// ============================================================================
// [VERIFIED] InstanceDriveExt::vfunc_22 (0x006E5A70, 35 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_Win32Drive_Cement_Audio.cpp
// ============================================================================
bool InstanceDriveExt::vfunc_22() {
    m_Lock04.Lock();
    bool bEmpty = (m_PendingCount14 == 0);
    m_Lock04.Unlock();
    return bEmpty;
}

// ============================================================================
// [VERIFIED] InstanceDriveExt::vfunc_46 (0x006E5E50, 12 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_Win32Drive_Cement_Audio.cpp
// ============================================================================
void InstanceDriveExt::vfunc_46(ICompletionArg* pArg) {
    pArg->OnExecute();
}

