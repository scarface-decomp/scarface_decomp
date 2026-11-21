// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, engine/PlayerBink.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 13 functions matched (38.46%). NOT COMPLETE YET.
// The 8 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] movie::PlayerBink::vfunc_16 (0x00701150, 14 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as movie::PlayerBink::vfunc_16 (Proto 0x002AFEE0), which was matched first;
// its addresses and names were swapped for this function's.
// movie::PlayerBink::vfunc_16 (Proto 0x00701150, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace movie {

class PlayerBink
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
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual int vfunc_16();
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

int PlayerBink::vfunc_16()
{
    int t1;

    t1 = m_Field1C;
    if (m_Field1C) {
        return *(int*)(t1 + 12);
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] movie::PlayerBink::vfunc_04 (0x00701230, 75 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as movie::PlayerBink::vfunc_04 (Proto 0x002AFFC0), which was matched first;
// its addresses and names were swapped for this function's.
// movie::PlayerBink::vfunc_04 (Proto 0x00701230, 75 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

namespace movie {

class PlayerBink
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1, int a2, int a3);
    char m_pad04[0xC];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

void PlayerBink::vfunc_04(int a1, int a2, int a3)
{
    int r_edi;

    r_edi = m_Field10;
    if (r_edi != a1) {
        m_Field10 = a1;
        if (a1) {
            ((Object*)a1)->vfunc_00();
        }
        if (!r_edi) goto L_25;
        ((Object*)r_edi)->vfunc_01();
    }
L_25:
    r_edi = m_Field14;
    if (r_edi != a2) {
        m_Field14 = a2;
        if (a2) {
            ((Object*)a2)->vfunc_00();
        }
        if (!r_edi) goto L_46;
        ((Object*)r_edi)->vfunc_01();
    }
L_46:
    ;
}

}

// ============================================================================
// [VERIFIED] movie::PlayerBink::vfunc_05 (0x00701280, 12 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as movie::PlayerBink::vfunc_05 (Proto 0x002B0010), which was matched first;
// its addresses and names were swapped for this function's.
// movie::PlayerBink::vfunc_05 (Proto 0x00701280, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
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

namespace movie {

class PlayerBink
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    char m_pad04[0x10];
    Field14* m_Field14; // +0x14
    char m_pad18[0xC];
    bool m_Field24; // +0x24
};

void PlayerBink::vfunc_05()
{
    m_Field24 = false;
    m_Field14->vfunc_09();
}

}

// ============================================================================
// [VERIFIED] movie::PlayerBink::vfunc_00 (0x00701580, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// movie::PlayerBink::vfunc_00 (0x00701580, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x00701630. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace movie {
class ControllerSystemXBox_Base0 { public: virtual void sub_00701630(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_00701630(); };

class PlayerBink : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    PlayerBink();
    virtual void sub_00701630();          // the real function; the thunk jumps here
};

PlayerBink::PlayerBink() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] movie::PlayerBink::vfunc_03 (0x00701630, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// movie::PlayerBink::vfunc_03 (0x00701630, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);
extern "C" void __cdecl sub_00701590(void);

namespace movie {

class PlayerBink
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual PlayerBink* vfunc_03(int a1);
};

PlayerBink* PlayerBink::vfunc_03(int a1)
{
    sub_00701590();
    if (a1 & 1) {
        sub_006DC430(DAT_007F5A70, (int)this);
    }
    return this;
}

}

