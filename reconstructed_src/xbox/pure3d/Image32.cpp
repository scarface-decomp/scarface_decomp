// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/Image32.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 7 functions matched (42.86%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::Image32::vfunc_11 (0x00263430, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::Image32::vfunc_11 (0x00263430, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class Image32
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
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual int vfunc_11(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0x10];
    int m_Field20; // +0x20
};

int Image32::vfunc_11(int a1, int a2)
{
    return *(int*)(m_Field20 + (((m_Field0C * a2) + a1) * 4));
}

}

// ============================================================================
// [VERIFIED] pure3d::Image32::vfunc_12 (0x00263450, 28 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::Image32::vfunc_12 (0x00263450, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class Image32
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
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual int vfunc_12(int a1, int a2, int a3);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0x10];
    int m_Field20; // +0x20
};

int Image32::vfunc_12(int a1, int a2, int a3)
{
    int t1;

    t1 = (m_Field0C * a2) + a1;
    *(int*)(m_Field20 + (((m_Field0C * a2) + a1) * 4)) = a3;
    return t1;
}

}

// ============================================================================
// [VERIFIED] pure3d::Image32::vfunc_13 (0x00263470, 55 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::Image32::vfunc_13 (0x00263470, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class Image32
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
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual int vfunc_13(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    char m_pad14[0xC];
    int m_Field20; // +0x20
};

int Image32::vfunc_13(int a1)
{
    int r_eax, r_edx, r_esi, t1;

    r_eax = m_Field20;
    r_esi = m_Field10;
    r_esi *= m_Field0C;
    r_edx = 0;
    if (r_esi > 0) {
        r_esi = a1;
        do {
            *(int*)r_eax = r_esi;
            t1 = m_Field10 * m_Field0C;
            r_eax += 4;
            r_edx += 1;
        } while (r_edx < t1);
    }
    return r_eax;
}

}

