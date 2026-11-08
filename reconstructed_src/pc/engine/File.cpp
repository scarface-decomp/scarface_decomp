// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, engine/File.cpp (14 verified)
// GENERATED from reports/verified_registry.json by tools/registry_outputs.py. Do not edit.
// Every block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] File::vfunc_00 (0x006E4D70, 12 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 2 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_File_And_Drive.cpp
// ============================================================================
void File::vfunc_00() {
    ResolveClassDescA(&g_FileClassDesc);
}

// ============================================================================
// [VERIFIED] File::vfunc_01 (0x006E4D80, 12 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 2 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_File_And_Drive.cpp
// ============================================================================
void File::vfunc_01() {
    ResolveClassDescB(&g_FileClassDesc);
}

// ============================================================================
// [VERIFIED] File::vfunc_10 (0x006E4F60, 36 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_File_And_Drive.cpp
// ============================================================================
void File::vfunc_10(void* a, int b, int c) {
    vfunc_04(a, b, c);
    vfunc_22();
}

// ============================================================================
// [VERIFIED] File::vfunc_11 (0x006E4F90, 36 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_File_And_Drive.cpp
// ============================================================================
void File::vfunc_11(const void* a, int b, int c) {
    vfunc_05(a, b, c);
    vfunc_22();
}

// ============================================================================
// [VERIFIED] File::vfunc_12 (0x006E4FC0, 26 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_File_And_Drive.cpp
// ============================================================================
void File::vfunc_12(int a) {
    vfunc_06(a);
    vfunc_22();
}

// ============================================================================
// [VERIFIED] File::vfunc_13 (0x006E4FE0, 26 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_File_And_Drive.cpp
// ============================================================================
void File::vfunc_13(int a) {
    vfunc_07(a);
    vfunc_22();
}

// ============================================================================
// [VERIFIED] File::vfunc_14 (0x006E5000, 26 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_File_And_Drive.cpp
// ============================================================================
void File::vfunc_14(int a) {
    vfunc_08(a);
    vfunc_22();
}

// ============================================================================
// [VERIFIED] File::vfunc_15 (0x006E5020, 16 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_File_And_Drive.cpp
// ============================================================================
void File::vfunc_15() {
    vfunc_09();
    vfunc_22();
}

// ============================================================================
// [VERIFIED] File::vfunc_16 (0x006E5030, 7 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_File_And_Drive.cpp
// ============================================================================
int File::vfunc_16() {
    return m_Field128;
}

// ============================================================================
// [VERIFIED] File::vfunc_21 (0x006E50E0, 35 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_File_And_Drive.cpp
// ============================================================================
bool File::vfunc_21() {
    m_Lock04.Lock();
    bool bEmpty = (m_PendingCount18 == 0);
    m_Lock04.Unlock();
    return bEmpty;
}

// ============================================================================
// [VERIFIED] File::vfunc_23 (0x006E5140, 29 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_File_And_Drive.cpp
// ============================================================================
int File::vfunc_23() {
    m_Lock04.Lock();
    int val = m_Field14;
    m_Lock04.Unlock();
    return val;
}

// ============================================================================
// [VERIFIED] File::vfunc_25 (0x006E5160, 24 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_File_And_Drive.cpp
// ============================================================================
char* File::vfunc_25() {
    // test al,al / jns: the name is returned when bit 7 is CLEAR.
    if (m_pDrive0C->GetDriveFlags08() & 0x80) {
        return 0;
    }
    return m_InlineName1E;
}

// ============================================================================
// [VERIFIED] File::vfunc_31 (0x006E51C0, 13 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_File_And_Drive.cpp
// ============================================================================
void File::vfunc_31(int val) {
    m_Field120 = val;
}

// ============================================================================
// [VERIFIED] File::AddRefLocked (0x006E54B0, 27 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_File_And_Drive.cpp
// ============================================================================
void File::AddRefLocked() {
    m_Lock04.Lock();
    ++m_RefCount08;
    m_Lock04.Unlock();
}

