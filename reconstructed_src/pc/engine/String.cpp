// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, engine/String.cpp (9 verified)
// GENERATED from reports/verified_registry.json by tools/registry_outputs.py. Do not edit.
// Every block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] String::vfunc_04 (0x006E0090, 36 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
bool String::vfunc_04(String* other) {
    if (other != 0) {
        return vfunc_05(other->vfunc_08());
    }
    return false;
}

// ============================================================================
// [VERIFIED] String::vfunc_06 (0x006E01E0, 34 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
void String::vfunc_06(String* other) {
    if (other != 0 && other != this) {
        vfunc_07(other->vfunc_08());
    }
}

// ============================================================================
// [VERIFIED] String::vfunc_08 (0x006E0250, 17 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
const char* String::vfunc_08() {
    if (GetHighBit() & 1) {
        return 0;
    }
    return m_pBuffer10;
}

// ============================================================================
// [VERIFIED] String::vfunc_14 (0x006E0430, 26 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
void String::vfunc_14(char ch) {
    char buf[2];
    buf[0] = ch;
    buf[1] = 0;
    vfunc_17(buf);
}

// ============================================================================
// [VERIFIED] String::vfunc_11 (0x006E0490, 26 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 | 2 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
void String::vfunc_11(bool bVal) {
    vfunc_17(bVal ? g_TrueStringLiteral : g_FalseStringLiteral);
}

// ============================================================================
// [VERIFIED] String::vfunc_19 (0x006E04B0, 22 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
void String::vfunc_19() {
    if (!(GetHighBit() & 1)) {
        _strlwr(m_pBuffer10);
    }
}

// ============================================================================
// [VERIFIED] String::vfunc_20 (0x006E04D0, 22 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
void String::vfunc_20() {
    if (!(GetHighBit() & 1)) {
        _strupr(m_pBuffer10);
    }
}

// ============================================================================
// [VERIFIED] String::vfunc_22 (0x006E04F0, 20 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
int String::vfunc_22(const char* other) {
    return StringCompareHelper(m_pBuffer10, other);   // the game returns the helper's result as is
}

// ============================================================================
// [VERIFIED] String::vfunc_03 (0x006E0540, 36 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 3 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
void* String::vfunc_03(unsigned int flags) {
    this->~String();
    if (flags & 1) {
        FreeToCorePool(g_pCoreMemoryPool, this);
    }
    return this;
}

