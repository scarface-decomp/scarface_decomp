// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/NISPackage.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] NISPackage::vfunc_00 (0x000CD8C0, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// NISPackage::vfunc_00 (0x000CD8C0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class NISPackage
{
public:
    virtual void vfunc_00();
    char m_pad04[0x90];
    int m_Field94; // +0x94
};

void NISPackage::vfunc_00()
{
    m_Field94 += 1;
}

// ============================================================================
// [VERIFIED] NISPackage::vfunc_01 (0x000CD8D0, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// NISPackage::vfunc_01 (0x000CD8D0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class NISPackage
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void NISPackage::vfunc_01()
{
    int r_eax, r_ecx;

    r_ecx = (int)this;
    r_eax = *(int*)(r_ecx + 148);
    if (r_eax < 2) {
        r_eax = *(int*)r_ecx;
        r_eax = ((int (__stdcall*)(int))*(int*)(r_eax + 12))(1);
        return;
    }
    r_eax -= 1;
    *(int*)(r_ecx + 148) = r_eax;
}

// ============================================================================
// [VERIFIED] NISPackage::vfunc_02 (0x000CD8F0, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// NISPackage::vfunc_02 (0x000CD8F0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class NISPackage
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    char m_pad04[0x90];
    int m_Field94; // +0x94
};

int NISPackage::vfunc_02()
{
    return m_Field94;
}

// ============================================================================
// [VERIFIED] NISPackage::vfunc_03 (0x000CDF30, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// NISPackage::vfunc_03 (0x000CDF30, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000CDDA0(void);
extern "C" void __cdecl sub_00027600(int);

class NISPackage
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual NISPackage* vfunc_03(int a1);
};

NISPackage* NISPackage::vfunc_03(int a1)
{
    sub_000CDDA0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

