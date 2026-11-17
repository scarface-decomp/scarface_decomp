// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Branch.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] fight::Branch::vfunc_07 (0x0023A990, 36 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Branch::vfunc_07 (Proto 0x001F83F0), which was matched first;
// its addresses and names were swapped for this function's.
// fight::Branch::vfunc_07 (Proto 0x0023A990, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
};

namespace fight {

class Branch
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
};

void Branch::vfunc_07()
{
    int r_ebx, r_edi, r_esi;

    r_edi = (int)this;
    r_ebx = *(int*)(r_edi + 32);
    r_esi = 0;
    if (r_ebx > 0) {
        do {
            ((Object*)*(int*)(*(int*)(r_edi + 36) + (r_esi * 4)))->vfunc_07();
            r_esi += 1;
        } while (r_esi < r_ebx);
    }
}

}

// ============================================================================
// [VERIFIED] fight::Branch::vfunc_08 (0x0023AA60, 45 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Branch::vfunc_08 (Proto 0x001F84B0), which was matched first;
// its addresses and names were swapped for this function's.
// fight::Branch::vfunc_08 (Proto 0x0023AA60, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_0023F1E0(int);
};

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
};

namespace fight {

class Branch
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual bool vfunc_08();
    char m_pad04[0xC];
    Field10 m_Field10; // +0x10
    char m_pad11[0xF];
    int m_Field20; // +0x20
    int m_Field24; // +0x24
};

bool Branch::vfunc_08()
{
    int r_ebx, r_esi;

    m_Field10.sub_0023F1E0((int)this);
    r_ebx = m_Field20;
    r_esi = 0;
    if (r_ebx > 0) {
        do {
            ((Object*)*(int*)(m_Field24 + (r_esi * 4)))->vfunc_08();
            r_esi += 1;
        } while (r_esi < r_ebx);
    }
    return true;
}

}

// ============================================================================
// [VERIFIED] fight::Branch::vfunc_09 (0x0023AA90, 44 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Branch::vfunc_09 (Proto 0x001F84E0), which was matched first;
// its addresses and names were swapped for this function's.
// fight::Branch::vfunc_09 (Proto 0x0023AA90, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_0023F210(int);
};

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
};

namespace fight {

class Branch
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual bool vfunc_09();
    char m_pad04[0xC];
    Field10 m_Field10; // +0x10
    char m_pad11[0xF];
    int m_Field20; // +0x20
    int m_Field24; // +0x24
};

bool Branch::vfunc_09()
{
    int r_esi;

    r_esi = m_Field20;
    r_esi -= 1;
    if (r_esi >= 0) {
        do {
            ((Object*)*(int*)(m_Field24 + (r_esi * 4)))->vfunc_09();
            r_esi -= 1;
        } while (r_esi >= 0);
    }
    m_Field10.sub_0023F210((int)this);
    return true;
}

}

// ============================================================================
// [VERIFIED] fight::Branch::vfunc_03 (0x0023B160, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Deleting destructor: destroys the branch, frees it when asked, and returns it.
// ============================================================================
extern "C" void __cdecl sub_0023F7A0(void* p);

namespace fight {

class Branch
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Branch* vfunc_03(unsigned int flags);
    void sub_0023AD60();
};

#pragma optimize("y", off)
Branch* Branch::vfunc_03(unsigned int flags)
{
    sub_0023AD60();
    if (flags & 1)
        sub_0023F7A0(this);
    return this;
}
#pragma optimize("", on)

}

