// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, verified functions in address order (155)
// GENERATED from reports/verified_registry.json by tools/registry_outputs.py. Do not edit.
// Every block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ControllerInputPointDirectInput::vfunc_01 (0x006DDC60, 23 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
// 1. core::ControllerInputPointDirectInput::vfunc_01 (PC VA 0x006DDC60, 23 B)
class RefCountedSub04 {
public:
    virtual ~RefCountedSub04();
    int m_Pad04;
    int m_RefCount08;
}

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

// ============================================================================
// [VERIFIED] sub_006DEDF0 (0x006DEDF0, 1 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
void __cdecl pc_sub_006DEDF0(void) {}

// ============================================================================
// [VERIFIED] LoadSet::vfunc_00 (0x006DF4A0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
class LoadSet {
public:
    virtual void vfunc_00();

private:
    char pad_0004[16];
    int field_0014;
};

void LoadSet::vfunc_00() {
    field_0014 += 1;
}

// ============================================================================
// [VERIFIED] Platform::vfunc_04 (0x006DF4C0, 24 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 2 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
// 4. core::Platform::vfunc_04 (PC VA 0x006DF4C0, 24 B)
class Platform {
public:
    int m_Field04; // +0x04
    virtual void vfunc_04(); // PC VA 0x006DF4C0 (24 B)
}

// ============================================================================
// [VERIFIED] MemoryAllocatorMalloc::vfunc_04 (0x006DF730, 26 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
void* MemoryAllocatorMalloc::vfunc_04(unsigned int size) {
    if (size == 0) {
        size = 1;
    }
    return malloc(size);
}

// ============================================================================
// [VERIFIED] MemoryAllocatorMalloc::vfunc_05 (0x006DF750, 15 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
void MemoryAllocatorMalloc::vfunc_05(void* ptr) {
    free(ptr);
}

// ============================================================================
// [VERIFIED] MemoryAllocatorMalloc::vfunc_07 (0x006DF760, 21 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
void* MemoryAllocatorMalloc::vfunc_07(unsigned int a, unsigned int b) {
    return AlignedAllocHelper(a, b);
}

// ============================================================================
// [VERIFIED] MemoryAllocatorMalloc::vfunc_08 (0x006DF7C0, 22 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
void MemoryAllocatorMalloc::vfunc_08(void* ptr) {
    if (ptr) {
        free(*((void**)ptr - 1));
    }
}

// ============================================================================
// [VERIFIED] GameMemorySegmentCollection::vfunc_00 (0x006E0010, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
class GameMemorySegmentCollection {
public:
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    virtual void vfunc_00();
};

void GameMemorySegmentCollection::vfunc_00() {
    this->m_Field0C += 1;
}

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

// ============================================================================
// [VERIFIED] MemorySmallDlAllocator::vfunc_03 (0x006E1D40, 36 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 3 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
void* MemorySmallDlAllocator::vfunc_03(unsigned int flags) {
    this->~MemorySmallDlAllocator();
    if (flags & 1) {
        FreeToCorePool(g_pCoreMemoryPool, this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] CompletionEventRequest::vfunc_01 (0x006E36A0, 18 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
int CompletionEventRequest::vfunc_01() {
    SetCompletionEvent(m_hEvent08);
    return 1;
}

// ============================================================================
// [VERIFIED] core::CompletionEventRequest::vfunc_06 (0x006E36C0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
unsigned int __cdecl pc_sub_006E36C0(void) { return 0x00000017; }

// ============================================================================
// [VERIFIED] FileCompletionRequest::vfunc_01 (0x006E3700, 18 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_DirectInput_String_Memory.cpp
// ============================================================================
int FileCompletionRequest::vfunc_01() {
    m_pHolder0C->m_pSub0C->OnRequestCompleted(this);
    return 3;
}

// ============================================================================
// [VERIFIED] core::DriveCompletionRequest::vfunc_06 (0x006E3760, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
unsigned int __cdecl pc_sub_006E3760(void) { return 0x00000016; }

// ============================================================================
// [VERIFIED] fight::VUpperBodyAnimStateCondition::?$ParamString::vfunc_01 (0x006E3C20, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
unsigned int __cdecl pc_sub_006E3C20(void) { return 0x00000003; }

// ============================================================================
// [VERIFIED] fight::VDirectionalGetHitCondition::?$ParamEnumConstList::vfunc_01 (0x006E3DD0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
unsigned int __cdecl pc_sub_006E3DD0(void) { return 0x00000005; }

// ============================================================================
// [VERIFIED] core::FileGetPositionRequest::vfunc_06 (0x006E3E60, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
unsigned int __cdecl pc_sub_006E3E60(void) { return 0x00000007; }

// ============================================================================
// [VERIFIED] DealerSpawnObject::vfunc_45 (0x006E3EB0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
unsigned int __cdecl pc_sub_006E3EB0(void) { return 0x00000008; }

// ============================================================================
// [VERIFIED] fight::VExitConditionTrack::?$ParamBranch::vfunc_01 (0x006E3F00, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
unsigned int __cdecl pc_sub_006E3F00(void) { return 0x00000009; }

// ============================================================================
// [VERIFIED] core::DriveOpenRequest::vfunc_06 (0x006E3F60, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
unsigned int __cdecl pc_sub_006E3F60(void) { return 0x0000000B; }

// ============================================================================
// [VERIFIED] core::DriveMediaRequest::vfunc_06 (0x006E3FC0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
unsigned int __cdecl pc_sub_006E3FC0(void) { return 0x0000000C; }

// ============================================================================
// [VERIFIED] GlanceAtOvertakingPed::vfunc_10 (0x006E4010, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
unsigned int __cdecl pc_sub_006E4010(void) { return 0x0000000D; }

// ============================================================================
// [VERIFIED] core::DriveCreateDirectoryRequest::vfunc_06 (0x006E4070, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
unsigned int __cdecl pc_sub_006E4070(void) { return 0x0000000E; }

// ============================================================================
// [VERIFIED] core::DriveDestroyDirectoryRequest::vfunc_06 (0x006E40D0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
unsigned int __cdecl pc_sub_006E40D0(void) { return 0x0000000F; }

// ============================================================================
// [VERIFIED] GangSpawnObject::vfunc_45 (0x006E4150, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
unsigned int __cdecl pc_sub_006E4150(void) { return 0x00000010; }

// ============================================================================
// [VERIFIED] core::DriveFindNextRequest::vfunc_06 (0x006E41B0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
unsigned int __cdecl pc_sub_006E41B0(void) { return 0x00000011; }

// ============================================================================
// [VERIFIED] core::DriveFindCloseRequest::vfunc_06 (0x006E4200, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
unsigned int __cdecl pc_sub_006E4200(void) { return 0x00000012; }

// ============================================================================
// [VERIFIED] core::DriveFileDestroyRequest::vfunc_06 (0x006E4270, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
unsigned int __cdecl pc_sub_006E4270(void) { return 0x00000013; }

// ============================================================================
// [VERIFIED] core::DriveCancelRequest::vfunc_06 (0x006E42C0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
unsigned int __cdecl pc_sub_006E42C0(void) { return 0x00000014; }

// ============================================================================
// [VERIFIED] core::DriveLockRequest::vfunc_06 (0x006E42D0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
unsigned int __cdecl pc_sub_006E42D0(void) { return 0x00000015; }

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

// ============================================================================
// [VERIFIED] InstanceDrive::vfunc_00 (0x006E5550, 12 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 2 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_File_And_Drive.cpp
// ============================================================================
void InstanceDrive::vfunc_00() {
    ResolveClassDescA(&g_InstanceDriveClassDesc);
}

// ============================================================================
// [VERIFIED] InstanceDrive::vfunc_01 (0x006E5560, 12 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 2 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_File_And_Drive.cpp
// ============================================================================
void InstanceDrive::vfunc_01() {
    ResolveClassDescB(&g_InstanceDriveClassDesc);
}

// ============================================================================
// [VERIFIED] InstanceDrive::vfunc_12 (0x006E58B0, 26 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_File_And_Drive.cpp
// ============================================================================
void InstanceDrive::vfunc_12(int a) {
    vfunc_05(a);
    vfunc_23();
}

// ============================================================================
// [VERIFIED] InstanceDrive::vfunc_13 (0x006E58D0, 16 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_File_And_Drive.cpp
// ============================================================================
void InstanceDrive::vfunc_13() {
    vfunc_06();
    vfunc_23();
}

// ============================================================================
// [VERIFIED] InstanceDrive::vfunc_14 (0x006E58E0, 26 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_File_And_Drive.cpp
// ============================================================================
void InstanceDrive::vfunc_14(int a) {
    vfunc_07(a);
    vfunc_23();
}

// ============================================================================
// [VERIFIED] InstanceDrive::vfunc_15 (0x006E5900, 26 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_File_And_Drive.cpp
// ============================================================================
void InstanceDrive::vfunc_15(int a) {
    vfunc_08(a);
    vfunc_23();
}

// ============================================================================
// [VERIFIED] InstanceDrive::vfunc_17 (0x006E5940, 26 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_File_And_Drive.cpp
// ============================================================================
void InstanceDrive::vfunc_17(int a) {
    vfunc_10(a);
    vfunc_23();
}

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

// ============================================================================
// [VERIFIED] Drive::vfunc_00 (0x006E6070, 23 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_Win32Drive_Cement_Audio.cpp
// ============================================================================
void Drive::vfunc_00() {
    m_Lock0C.AddRefLocked();
}

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

// ============================================================================
// [VERIFIED] NISStreamDataLoader::vfunc_04 (0x006E9E70, 27 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | excerpt from reconstructed_src/PC_Core_Win32Drive_Cement_Audio.cpp
// ============================================================================
// 7. NISStreamDataLoader::vfunc_04 (PC VA 0x006E9E70, 27 B)
class NISStreamDataLoader {
public:
    char pad[0x0C];
    int  m_Field10; // +0x10
    virtual void vfunc_00(); virtual void vfunc_01(); virtual void vfunc_02(); virtual void vfunc_03();
    virtual void vfunc_04(int a, int b, int c, int d, int e); // PC VA 0x006E9E70 (27 B)
    virtual void vfunc_05();
    virtual void vfunc_06(int a, int b, int f10, int e);      // +0x18
}

// ============================================================================
// [VERIFIED] Stats::~Stats (0x006E9E90, 31 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 | 1 external relocation(s) unchecked | excerpt from reconstructed_src/PC_Core_Win32Drive_Cement_Audio.cpp
// ============================================================================
Stats::~Stats() {
}

// ============================================================================
// [VERIFIED] sub_006E9F50 (0x006E9F50, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
unsigned int __cdecl pc_sub_006E9F50(void) { return 0x00000001; }

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

// ============================================================================
// [VERIFIED] sub_006EE9B0 (0x006EE9B0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_0085CEC0; void* __cdecl pc_sub_006EE9B0(void) { return &DAT_0085CEC0; }

// ============================================================================
// [VERIFIED] om::audio::VMix::?$EntityType::vfunc_03 (0x006EEBF0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007C1624; void* __cdecl pc_sub_006EEBF0(void) { return &DAT_007C1624; }

// ============================================================================
// [VERIFIED] om::audio::VClip::?$EntityType::vfunc_03 (0x006EECB0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007C6038; void* __cdecl pc_sub_006EECB0(void) { return &DAT_007C6038; }

// ============================================================================
// [VERIFIED] om::audio::VSequence::?$EntityType::vfunc_03 (0x006EEDE0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007C1604; void* __cdecl pc_sub_006EEDE0(void) { return &DAT_007C1604; }

// ============================================================================
// [VERIFIED] sub_006EF290 (0x006EF290, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_0085D0F0; void* __cdecl pc_sub_006EF290(void) { return &DAT_0085D0F0; }

// ============================================================================
// [VERIFIED] om::audio::VLayerTemplate::?$EntityType::vfunc_03 (0x006F0560, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007F6A1C; void* __cdecl pc_sub_006F0560(void) { return &DAT_007F6A1C; }

// ============================================================================
// [VERIFIED] om::audio::VListenerEffectWin32::?$EntityType::vfunc_03 (0x006F67B0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007C5AF8; void* __cdecl pc_sub_006F67B0(void) { return &DAT_007C5AF8; }

// ============================================================================
// [VERIFIED] pure3d::d3dErrorShader::vfunc_04 (0x007048D0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FB648; void* __cdecl pc_sub_007048D0(void) { return &DAT_007FB648; }

// ============================================================================
// [VERIFIED] pure3d::d3dReflShader::vfunc_16 (0x00704A40, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FB7F0; void* __cdecl pc_sub_00704A40(void) { return &DAT_007FB7F0; }

// ============================================================================
// [VERIFIED] pure3d::d3dReflShader::vfunc_17 (0x00704A50, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FB718; void* __cdecl pc_sub_00704A50(void) { return &DAT_007FB718; }

// ============================================================================
// [VERIFIED] pure3d::d3dReflShader::vfunc_18 (0x00704A60, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FB6D0; void* __cdecl pc_sub_00704A60(void) { return &DAT_007FB6D0; }

// ============================================================================
// [VERIFIED] pure3d::d3dReflShader::vfunc_19 (0x00704A70, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FB838; void* __cdecl pc_sub_00704A70(void) { return &DAT_007FB838; }

// ============================================================================
// [VERIFIED] pure3d::d3dReflShader::vfunc_04 (0x00704A80, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FB6AC; void* __cdecl pc_sub_00704A80(void) { return &DAT_007FB6AC; }

// ============================================================================
// [VERIFIED] pure3d::d3dPointSpriteShader::vfunc_16 (0x00705050, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FB9D8; void* __cdecl pc_sub_00705050(void) { return &DAT_007FB9D8; }

// ============================================================================
// [VERIFIED] pure3d::d3dPointSpriteShader::vfunc_17 (0x00705060, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FBA08; void* __cdecl pc_sub_00705060(void) { return &DAT_007FBA08; }

// ============================================================================
// [VERIFIED] pure3d::d3dPointSpriteShader::vfunc_18 (0x00705070, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FB918; void* __cdecl pc_sub_00705070(void) { return &DAT_007FB918; }

// ============================================================================
// [VERIFIED] pure3d::d3dPointSpriteShader::vfunc_04 (0x00705080, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FB8F4; void* __cdecl pc_sub_00705080(void) { return &DAT_007FB8F4; }

// ============================================================================
// [VERIFIED] pure3d::d3dLayeredShader::vfunc_16 (0x007053D0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FBC28; void* __cdecl pc_sub_007053D0(void) { return &DAT_007FBC28; }

// ============================================================================
// [VERIFIED] pure3d::d3dLayeredShader::vfunc_17 (0x007053E0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FBC70; void* __cdecl pc_sub_007053E0(void) { return &DAT_007FBC70; }

// ============================================================================
// [VERIFIED] pure3d::d3dLayeredShader::vfunc_18 (0x007053F0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FBB50; void* __cdecl pc_sub_007053F0(void) { return &DAT_007FBB50; }

// ============================================================================
// [VERIFIED] pure3d::d3dLayeredShader::vfunc_19 (0x00705400, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FBBB0; void* __cdecl pc_sub_00705400(void) { return &DAT_007FBBB0; }

// ============================================================================
// [VERIFIED] pure3d::d3dLayeredShader::vfunc_04 (0x00705410, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_00769BD0; void* __cdecl pc_sub_00705410(void) { return &DAT_00769BD0; }

// ============================================================================
// [VERIFIED] sub_00705430 (0x00705430, 1 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
void __cdecl pc_sub_00705430(void) {}

// ============================================================================
// [VERIFIED] pure3d::d3dSpecularShader::vfunc_04 (0x007066A0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FBFE8; void* __cdecl pc_sub_007066A0(void) { return &DAT_007FBFE8; }

// ============================================================================
// [VERIFIED] pure3d::d3dSpecularShader::vfunc_16 (0x00706B80, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FBFA0; void* __cdecl pc_sub_00706B80(void) { return &DAT_007FBFA0; }

// ============================================================================
// [VERIFIED] pure3d::d3dSpecularShader::vfunc_17 (0x00706B90, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FBE98; void* __cdecl pc_sub_00706B90(void) { return &DAT_007FBE98; }

// ============================================================================
// [VERIFIED] pure3d::d3dSpecularShader::vfunc_18 (0x00706BA0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FBE50; void* __cdecl pc_sub_00706BA0(void) { return &DAT_007FBE50; }

// ============================================================================
// [VERIFIED] pure3d::d3dSpecularShader::vfunc_19 (0x00706BB0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FBF40; void* __cdecl pc_sub_00706BB0(void) { return &DAT_007FBF40; }

// ============================================================================
// [VERIFIED] pure3d::d3dCharacterShader::vfunc_16 (0x00707310, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FC198; void* __cdecl pc_sub_00707310(void) { return &DAT_007FC198; }

// ============================================================================
// [VERIFIED] pure3d::d3dCharacterShader::vfunc_17 (0x00707320, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FC0C0; void* __cdecl pc_sub_00707320(void) { return &DAT_007FC0C0; }

// ============================================================================
// [VERIFIED] pure3d::d3dCharacterShader::vfunc_18 (0x00707330, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FC078; void* __cdecl pc_sub_00707330(void) { return &DAT_007FC078; }

// ============================================================================
// [VERIFIED] pure3d::d3dCharacterShader::vfunc_19 (0x00707340, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_0085D760; void* __cdecl pc_sub_00707340(void) { return &DAT_0085D760; }

// ============================================================================
// [VERIFIED] pure3d::d3dCharacterShader::vfunc_04 (0x00707350, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_0073E280; void* __cdecl pc_sub_00707350(void) { return &DAT_0073E280; }

// ============================================================================
// [VERIFIED] sub_007073A0 (0x007073A0, 1 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
void __cdecl pc_sub_007073A0(void) {}

// ============================================================================
// [VERIFIED] sub_00707D80 (0x00707D80, 1 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
void __cdecl pc_sub_00707D80(void) {}

// ============================================================================
// [VERIFIED] pure3d::d3dVehicleShader::vfunc_04 (0x00707EA0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007331B0; void* __cdecl pc_sub_00707EA0(void) { return &DAT_007331B0; }

// ============================================================================
// [VERIFIED] pure3d::d3dVehicleShader::vfunc_16 (0x00707EF0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FC550; void* __cdecl pc_sub_00707EF0(void) { return &DAT_007FC550; }

// ============================================================================
// [VERIFIED] pure3d::d3dVehicleShader::vfunc_17 (0x00707F00, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FC4C0; void* __cdecl pc_sub_00707F00(void) { return &DAT_007FC4C0; }

// ============================================================================
// [VERIFIED] pure3d::d3dVehicleShader::vfunc_18 (0x00707F10, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FC418; void* __cdecl pc_sub_00707F10(void) { return &DAT_007FC418; }

// ============================================================================
// [VERIFIED] pure3d::d3dVehicleShader::vfunc_19 (0x00707F20, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FC508; void* __cdecl pc_sub_00707F20(void) { return &DAT_007FC508; }

// ============================================================================
// [VERIFIED] pure3d::d3dShadowShader::vfunc_16 (0x00708F50, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FC7E0; void* __cdecl pc_sub_00708F50(void) { return &DAT_007FC7E0; }

// ============================================================================
// [VERIFIED] pure3d::d3dShadowShader::vfunc_17 (0x00708F60, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FC690; void* __cdecl pc_sub_00708F60(void) { return &DAT_007FC690; }

// ============================================================================
// [VERIFIED] pure3d::d3dShadowShader::vfunc_18 (0x00708F70, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FC648; void* __cdecl pc_sub_00708F70(void) { return &DAT_007FC648; }

// ============================================================================
// [VERIFIED] pure3d::d3dShadowShader::vfunc_19 (0x00708F80, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FC768; void* __cdecl pc_sub_00708F80(void) { return &DAT_007FC768; }

// ============================================================================
// [VERIFIED] pure3d::d3dShadowShader::vfunc_04 (0x00708F90, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_0072F5B0; void* __cdecl pc_sub_00708F90(void) { return &DAT_0072F5B0; }

// ============================================================================
// [VERIFIED] pure3d::d3dShadowDecalShader::vfunc_16 (0x007090A0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FC968; void* __cdecl pc_sub_007090A0(void) { return &DAT_007FC968; }

// ============================================================================
// [VERIFIED] pure3d::d3dShadowDecalShader::vfunc_17 (0x007090B0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FC890; void* __cdecl pc_sub_007090B0(void) { return &DAT_007FC890; }

// ============================================================================
// [VERIFIED] pure3d::d3dShadowDecalShader::vfunc_18 (0x007090C0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FC848; void* __cdecl pc_sub_007090C0(void) { return &DAT_007FC848; }

// ============================================================================
// [VERIFIED] pure3d::d3dShadowDecalShader::vfunc_19 (0x007090D0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_0085D788; void* __cdecl pc_sub_007090D0(void) { return &DAT_0085D788; }

// ============================================================================
// [VERIFIED] pure3d::d3dShadowDecalShader::vfunc_04 (0x007090E0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_00769C04; void* __cdecl pc_sub_007090E0(void) { return &DAT_00769C04; }

// ============================================================================
// [VERIFIED] pure3d::d3dDecalShader::vfunc_04 (0x00709370, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_00769C24; void* __cdecl pc_sub_00709370(void) { return &DAT_00769C24; }

// ============================================================================
// [VERIFIED] pure3d::d3dVertexFadeShader::vfunc_04 (0x00709470, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FC9FC; void* __cdecl pc_sub_00709470(void) { return &DAT_007FC9FC; }

// ============================================================================
// [VERIFIED] pure3d::d3dVertexFadeShader::vfunc_16 (0x007099F0, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FCAF8; void* __cdecl pc_sub_007099F0(void) { return &DAT_007FCAF8; }

// ============================================================================
// [VERIFIED] pure3d::d3dVertexFadeShader::vfunc_17 (0x00709A00, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FCA50; void* __cdecl pc_sub_00709A00(void) { return &DAT_007FCA50; }

// ============================================================================
// [VERIFIED] pure3d::d3dVertexFadeShader::vfunc_18 (0x00709A10, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FCB70; void* __cdecl pc_sub_00709A10(void) { return &DAT_007FCB70; }

// ============================================================================
// [VERIFIED] pure3d::d3dVertexFadeShader::vfunc_19 (0x00709A20, 6 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
extern "C" char DAT_007FCB28; void* __cdecl pc_sub_00709A20(void) { return &DAT_007FCB28; }

// ============================================================================
// [VERIFIED] sub_0072C940 (0x0072C940, 1 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
void __cdecl pc_sub_0072C940(void) {}

// ============================================================================
// [VERIFIED] sub_0072CC00 (0x0072CC00, 1 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
void __cdecl pc_sub_0072CC00(void) {}

// ============================================================================
// [VERIFIED] sub_0072CC10 (0x0072CC10, 1 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
void __cdecl pc_sub_0072CC10(void) {}

// ============================================================================
// [VERIFIED] sub_0072CD30 (0x0072CD30, 1 B)
// By: unattributed | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
void __cdecl pc_sub_0072CD30(void) {}

