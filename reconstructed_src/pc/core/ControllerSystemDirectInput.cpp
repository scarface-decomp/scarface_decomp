// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, core/ControllerSystemDirectInput.cpp (4 verified)
// GENERATED from reports/verified_registry.json by tools/registry_outputs.py. Do not edit.
// Every block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ControllerSystemDirectInput::vfunc_12 (0x006DE590, 19 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
void ControllerSystemDirectInput::vfunc_12(void* pDev) {
    if (m_pActiveDevice20 == pDev) {
        m_pActiveDevice20 = 0;
    }
}

// ============================================================================
// [VERIFIED] ControllerSystemDirectInput::vfunc_09 (0x006DE620, 44 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
void ControllerSystemDirectInput::vfunc_09(int arg) {
    ControllerDeviceNode* cur = m_pDeviceList28;
    if (cur != 0) {
        do {
            cur->OnSystemNotify(arg, m_SystemContext18);
            cur = cur->m_pNext280;
        } while (cur != 0);
    }
}

// ============================================================================
// [VERIFIED] ControllerSystemDirectInput::vfunc_05 (0x006DE650, 38 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
ControllerDeviceNode* ControllerSystemDirectInput::vfunc_05(unsigned int index) {
    unsigned int i = 0;
    ControllerDeviceNode* cur = m_pDeviceList28;
    if (cur != 0) {
        do {
            if (i == index) {
                return cur;
            }
            cur = cur->m_pNext280;
            ++i;
        } while (cur != 0);
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ControllerSystemDirectInput::vfunc_03 (0x006DE690, 36 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 3 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
void* ControllerSystemDirectInput::vfunc_03(unsigned int flags) {
    this->~ControllerSystemDirectInput();
    if (flags & 1) {
        FreeToCorePool(g_pCoreMemoryPool, this);
    }
    return this;
}

