// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, core/Platform.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::Platform::vfunc_01 (0x006DF4B0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006DF4B0
// what: 
// tool: the portal's starter code (no AI)

// core::Platform::vfunc_01 (PC 0x006DF4B0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class Platform
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    char m_pad04[0x10];
    int m_Field14; // +0x14
};

void Platform::vfunc_01()
{
    m_Field14 += -1;
}

}

// ============================================================================
// [VERIFIED] core::Platform::vfunc_04 (0x006DF4C0, 24 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006DF4C0
// what: 
// tool: the portal's starter code (no AI)

// core::Platform::vfunc_04 (PC 0x006DF4C0, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F268;
extern "C" int DAT_0072F288;

namespace core {

class Platform
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04();
    int m_Field04; // +0x04
};

int Platform::vfunc_04()
{
    int r_eax;

    r_eax = m_Field04;
    if (!r_eax) {
        r_eax = ((int (__cdecl*)(void))DAT_0072F288)();
        if (r_eax) goto L_17;
        return ((int (__cdecl*)(void))DAT_0072F268)();
    }
L_17:
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] core::Platform::vfunc_06 (0x006DF590, 50 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006DF590
// what: 
// tool: the portal's starter code (no AI)

// core::Platform::vfunc_06 (PC 0x006DF590, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F28C;
extern "C" char sub_006DF530[];

namespace core {

class Platform
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06(int a1);
    int m_Field04; // +0x04
    char m_pad08[0x4];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

int Platform::vfunc_06(int a1)
{
    int t1;

    if (!m_Field10) {
        t1 = m_Field04;
        if (!m_Field04) goto L_21;
        m_Field0C = ((int (__stdcall*)(int, int, int))DAT_0072F28C)(t1, -4, (int)sub_006DF530);
    }
L_21:
    *(int*)(a1 + 4) = m_Field10;
    m_Field10 = a1;
    return a1;
}

}

