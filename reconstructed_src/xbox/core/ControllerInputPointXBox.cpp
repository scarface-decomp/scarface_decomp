// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/ControllerInputPointXBox.cpp (8 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 8 of 10 functions matched (80.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::ControllerInputPointXBox::vfunc_04 (0x0002E690, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::ControllerInputPointXBox::vfunc_04 (0x0002E690, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class ControllerInputPointXBox
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04();
    char m_pad04[0x20];
    int m_Field24; // +0x24
};

int ControllerInputPointXBox::vfunc_04()
{
    return m_Field24;
}

}

// ============================================================================
// [VERIFIED] core::ControllerInputPointXBox::vfunc_14 (0x00248010, 17 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerInputPointXBox::vfunc_14 (Proto 0x002053C0), which was matched first;
// its addresses and names were swapped for this function's.
// core::ControllerInputPointXBox::vfunc_14 (Proto 0x00248010, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class ControllerInputPointXBox
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
    virtual void vfunc_13();
    virtual int vfunc_14(int a1);
    char m_pad04[0x14];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

int ControllerInputPointXBox::vfunc_14(int a1)
{
    m_Field18 = 0;
    m_Field1C = a1;
    return a1;
}

}

// ============================================================================
// [VERIFIED] core::ControllerInputPointXBox::vfunc_06 (0x00248110, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerInputPointXBox::vfunc_06 (Proto 0x002054C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x00248110
// what: Stores the value passed in at +0x14, clamped between 0 and 1.
// tool: Claude Opus 5.5 (transplanted from xb:0x00247FD0, nearest by portal/tools/similar.py)
// core::ControllerInputPointXBox::vfunc_06


namespace core {
class ControllerInputPointXBox
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(float value);

    char m_pad04[0x10];
    float m_Field14; // +0x14
};

// Clamps the value to [0, 1] and stores it.
void ControllerInputPointXBox::vfunc_06(float value)
{
    if (value < 0.0f)
    {
        m_Field14 = 0.0f;
    }
    else if (value > 1.0f)
    {
        m_Field14 = 1.0f;
    }
    else
    {
        m_Field14 = value;
    }
}
}

// ============================================================================
// [VERIFIED] core::ControllerInputPointXBox::vfunc_08 (0x00248150, 24 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerInputPointXBox::vfunc_08 (Proto 0x00205500), which was matched first;
// its addresses and names were swapped for this function's.
// core::ControllerInputPointXBox::vfunc_08 (Proto 0x00248150, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class ControllerInputPointXBox
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
    virtual int vfunc_08(int a1, int a2);
    char m_pad04[0x28];
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
};

int ControllerInputPointXBox::vfunc_08(int a1, int a2)
{
    int r_eax;

    r_eax = m_Field2C;
    if (!r_eax) {
        r_eax = a2;
        m_Field30 = a2;
        m_Field2C = a1;
    }
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] core::ControllerInputPointXBox::vfunc_09 (0x00248170, 20 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerInputPointXBox::vfunc_09 (Proto 0x00205520), which was matched first;
// its addresses and names were swapped for this function's.
// core::ControllerInputPointXBox::vfunc_09 (Proto 0x00248170, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class ControllerInputPointXBox
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
    virtual int vfunc_09(int a1);
    char m_pad04[0x28];
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
};

int ControllerInputPointXBox::vfunc_09(int a1)
{
    int r_eax;

    r_eax = m_Field2C;
    if (r_eax == a1) {
        r_eax = 0;
        m_Field2C = 0;
        m_Field30 = 0;
    }
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] core::ControllerInputPointXBox::vfunc_10 (0x00248190, 28 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerInputPointXBox::vfunc_10 (Proto 0x00205540), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x00248190
// what: 
// tool: the portal's starter code (no AI)

// core::ControllerInputPointXBox::vfunc_10 (Proto 0x00248190, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class ControllerInputPointXBox
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
    virtual float vfunc_10(int a1);
    char m_pad04[0x4];
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    char m_pad14[0x4];
    int m_Field18; // +0x18
};

float ControllerInputPointXBox::vfunc_10(int a1)
{
    if (a1) {
        *(int*)a1 = m_Field18;
    }
    return ((m_Field10 - m_Field0C) * m_Field08) + m_Field0C;
}

}

// ============================================================================
// [VERIFIED] core::ControllerInputPointXBox::vfunc_11 (0x002481B0, 17 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerInputPointXBox::vfunc_11 (Proto 0x00205560), which was matched first;
// its addresses and names were swapped for this function's.
// core::ControllerInputPointXBox::vfunc_11 (Proto 0x002481B0, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class ControllerInputPointXBox
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
    int m_Field10; // +0x10
};

int ControllerInputPointXBox::vfunc_11(int a1, int a2)
{
    m_Field0C = a1;
    m_Field10 = a2;
    return a1;
}

}

// ============================================================================
// [VERIFIED] core::ControllerInputPointXBox::vfunc_12 (0x002481D0, 29 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerInputPointXBox::vfunc_12 (Proto 0x00205580), which was matched first;
// its addresses and names were swapped for this function's.
// core::ControllerInputPointXBox::vfunc_12 (Proto 0x002481D0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class ControllerInputPointXBox
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
    virtual int vfunc_12(int a1, int a2);
};

int ControllerInputPointXBox::vfunc_12(int a1, int a2)
{
    int r_eax, r_ecx;

    r_ecx = (int)this;
    r_eax = a1;
    if (a1) {
        *(int*)r_eax = *(int*)(r_ecx + 12);
    }
    r_eax = a2;
    if (a2) {
        r_ecx = *(int*)(r_ecx + 16);
        *(int*)r_eax = r_ecx;
    }
    return r_eax;
}

}

