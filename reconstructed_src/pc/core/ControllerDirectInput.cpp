// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, core/ControllerDirectInput.cpp (4 verified)
// GENERATED from reports/verified_registry.json by tools/registry_outputs.py. Do not edit.
// Every block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ControllerDirectInput::vfunc_12 (0x006DDF60, 38 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
InputPointNode174* ControllerDirectInput::vfunc_12(unsigned int index) {
    unsigned int i = 0;
    InputPointNode174* cur = m_pInputList264;
    if (cur != 0) {
        do {
            if (i == index) {
                return cur;
            }
            cur = cur->m_pNext174;
            ++i;
        } while (cur != 0);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ControllerDirectInput::vfunc_17 (0x006DDFA0, 38 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
OutputPointNode19C* ControllerDirectInput::vfunc_17(unsigned int index) {
    unsigned int i = 0;
    OutputPointNode19C* cur = m_pOutputList270;
    if (cur != 0) {
        do {
            if (i == index) {
                return cur;
            }
            cur = cur->m_pNext19C;
            ++i;
        } while (cur != 0);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ControllerDirectInput::vfunc_07 (0x006DE000, 21 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
const char* ControllerDirectInput::vfunc_07() {
    IControllerSubObj27C* pSub = m_pSubObj27C;
    if (pSub != 0) {
        return pSub->GetDeviceName();
    }
    return g_EmptyControllerName;
}

// ============================================================================
// [VERIFIED] ControllerDirectInput::vfunc_03 (0x006DE1D0, 36 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 3 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
void* ControllerDirectInput::vfunc_03(unsigned int flags) {
    this->~ControllerDirectInput();
    if (flags & 1) {
        FreeToCorePool(g_pCoreMemoryPool, this);
    }
    return this;
}

