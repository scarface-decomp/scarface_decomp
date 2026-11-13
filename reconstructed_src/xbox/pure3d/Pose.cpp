// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/Pose.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 9 functions matched (33.33%). NOT COMPLETE YET.
// The 6 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::Pose::vfunc_04 (0x00282250, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::Pose::vfunc_04 (0x00282250, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class Pose
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04(int a1);
    char m_pad04[0x14];
    int m_Field18; // +0x18
};

int Pose::vfunc_04(int a1)
{
    return m_Field18 + ((a1 + (a1 * 2)) * 4);
}

}

// ============================================================================
// [VERIFIED] pure3d::Pose::vfunc_05 (0x00282270, 44 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::Pose::vfunc_05 (0x00282270, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class Pose
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05(int a1, int a2);
    char m_pad04[0x14];
    int m_Field18; // +0x18
    char m_pad1C[0x1];
    unsigned char m_Field1D; // +0x1D
};

int Pose::vfunc_05(int a1, int a2)
{
    int t1;

    t1 = m_Field18 + ((a1 + (a1 * 2)) * 4);
    *(int*)(m_Field18 + ((a1 + (a1 * 2)) * 4)) = *(int*)a2;
    *(int*)(t1 + 4) = *(int*)(a2 + 4);
    *(int*)(t1 + 8) = *(int*)(a2 + 8);
    m_Field1D |= 2;
    return t1;
}

}

// ============================================================================
// [VERIFIED] pure3d::Pose::vfunc_09 (0x002822A0, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::Pose::vfunc_09 (0x002822A0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

namespace pure3d {

class Pose
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
    virtual void vfunc_09(bool a1);
    char m_pad04[0x19];
    unsigned char m_Field1D; // +0x1D
};

void Pose::vfunc_09(bool a1)
{
    int r_eax;

    r_eax = a1;
    if (a1) {
        m_Field1D |= 1;
    }
}

}

