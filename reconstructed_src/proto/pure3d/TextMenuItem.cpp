// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/TextMenuItem.cpp (8 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 8 of 13 functions matched (61.54%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::frontend::TextMenuItem::vfunc_15 (0x00249630, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::frontend::TextMenuItem::vfunc_15 (Proto 0x00249630, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field34
{
    void sub_00206370();
};

namespace pure3d { namespace frontend {

class TextMenuItem
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
    char m_pad04[0x30];
    Field34* m_Field34; // +0x34
};

void TextMenuItem::vfunc_15()
{
    m_Field34->sub_00206370();
}

} }

// ============================================================================
// [VERIFIED] pure3d::frontend::TextMenuItem::vfunc_16 (0x00249640, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::frontend::TextMenuItem::vfunc_16 (Proto 0x00249640, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d { namespace frontend {

class TextMenuItem
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
    char m_pad04[0x30];
    int m_Field34; // +0x34
};

int TextMenuItem::vfunc_16()
{
    return *(short*)(m_Field34 + 80);
}

} }

// ============================================================================
// [VERIFIED] pure3d::frontend::TextMenuItem::vfunc_21 (0x00249690, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x00249690
// what: 
// tool: the portal's starter code (no AI)

// pure3d::frontend::TextMenuItem::vfunc_21 (Proto 0x00249690, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00206370(int);
};

namespace pure3d { namespace frontend {

class TextMenuItem
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
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    char m_pad04[0x28];
    char m_Field2C; // +0x2C
    bool m_Field2D; // +0x2D
    char m_pad2E[0x6];
    int m_Field34; // +0x34
};

void TextMenuItem::vfunc_21()
{
    int r_eax, r_edx;
    bool t1;

    r_edx = m_Field34;
    if (!r_edx) goto L_2C;
    r_eax = *(short*)(r_edx + 80);
    t1 = m_Field2D;
    r_eax -= 1;
    if (t1 & 4) {
        if (r_eax >= 0) goto L_24;
        r_eax += m_Field2C;
    }
    if (r_eax < 0) goto L_2C;
L_24:
    ((Object*)r_edx)->sub_00206370(r_eax);
L_2C:
    ;
}

} }

// ============================================================================
// [VERIFIED] pure3d::frontend::TextMenuItem::vfunc_22 (0x002496C0, 22 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Turns flag bit 3 of the menu item's byte at +0x2D on or off.
// ============================================================================
// bin: proto
// va: 0x002496C0
// what: Turns flag bit 3 of the menu item's byte at +0x2D on or off.
// tool: Claude Opus 5.5 (transplanted from xb:0x00088360, nearest by portal/tools/similar.py)
namespace pure3d {
namespace frontend {
class TextMenuItem
{
public:
    void vfunc_22(bool value);
    char m_pad00[0x2D];
    unsigned char m_Flag0 : 1;
    unsigned char m_Flag1 : 1;
    unsigned char m_Flag2 : 1;
    unsigned char m_Flag3 : 1;
};

void TextMenuItem::vfunc_22(bool value)
{
    m_Flag3 = value;
}
}
}

// ============================================================================
// [VERIFIED] pure3d::frontend::TextMenuItem::vfunc_18 (0x00249860, 82 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::frontend::TextMenuItem::vfunc_18 (Proto 0x00249860, 82 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00205D70(int);
};

extern "C" int DAT_00429080;

namespace pure3d { namespace frontend {

class TextMenuItem
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
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual int vfunc_18(bool a1);
};

int TextMenuItem::vfunc_18(bool a1)
{
    int r_eax, r_esi;

    r_eax = a1;
    r_esi = (int)this;
    if (a1) {
        if (*(int*)(r_esi + 48)) {
            r_eax = DAT_00429080;
            ((Object*)*(int*)(r_esi + 48))->sub_00205D70(r_eax);
        }
        if (!*(int*)(r_esi + 52)) goto L_30;
        ((Object*)*(int*)(r_esi + 52))->sub_00205D70(DAT_00429080);
    }
L_30:
    r_eax = *(int*)(r_esi + 36);
    if (r_eax) {
        if (!*(int*)(r_esi + 40)) goto L_4E;
        *(unsigned char*)(r_eax + 44) = (unsigned char)(*(bool*)(r_eax + 44) | 64);
        r_esi = *(int*)(r_esi + 40);
        *(unsigned char*)(r_esi + 44) |= 64;
    }
L_4E:
    return r_eax;
}

} }

// ============================================================================
// [VERIFIED] pure3d::frontend::TextMenuItem::vfunc_19 (0x002498C0, 72 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::frontend::TextMenuItem::vfunc_19 (Proto 0x002498C0, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00205D70(int);
};

extern "C" int DAT_00429084;

namespace pure3d { namespace frontend {

class TextMenuItem
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
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual int vfunc_19();
};

int TextMenuItem::vfunc_19()
{
    int r_eax, r_esi;

    r_esi = (int)this;
    if (*(int*)(r_esi + 48)) {
        r_eax = DAT_00429084;
        ((Object*)*(int*)(r_esi + 48))->sub_00205D70(r_eax);
    }
    if (*(int*)(r_esi + 52)) {
        ((Object*)*(int*)(r_esi + 52))->sub_00205D70(DAT_00429084);
    }
    r_eax = *(int*)(r_esi + 36);
    if (r_eax) {
        if (!*(int*)(r_esi + 40)) goto L_46;
        *(unsigned char*)(r_eax + 44) = (unsigned char)(*(bool*)(r_eax + 44) & 191);
        r_esi = *(int*)(r_esi + 40);
        *(unsigned char*)(r_esi + 44) &= 191;
    }
L_46:
    return r_eax;
}

} }

// ============================================================================
// [VERIFIED] pure3d::frontend::TextMenuItem::vfunc_17 (0x00249BA0, 20 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::frontend::TextMenuItem::vfunc_17 (Proto 0x00249BA0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d { namespace frontend {

class TextMenuItem
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
    virtual void vfunc_16();
    virtual int vfunc_17();
    char m_pad04[0x28];
    unsigned char m_Field2C; // +0x2C
    char m_pad2D[0x7];
    int m_Field34; // +0x34
};

int TextMenuItem::vfunc_17()
{
    int r_eax;

    r_eax = m_Field34;
    if (r_eax) {
        m_Field2C = (unsigned char)((*(int*)(r_eax + 60) - *(int*)(r_eax + 56)) >> 2);
    }
    return r_eax;
}

} }

// ============================================================================
// [VERIFIED] pure3d::frontend::TextMenuItem::vfunc_03 (0x00249DC0, 30 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::frontend::Text::vfunc_03 (Proto 0x00206FC0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::frontend::TextMenuItem::vfunc_03 (Proto 0x00249DC0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001FCF60(int);
extern "C" void __cdecl sub_00249A70(void);

namespace pure3d { namespace frontend {

class TextMenuItem
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual TextMenuItem* vfunc_03(int a1);
};

TextMenuItem* TextMenuItem::vfunc_03(int a1)
{
    sub_00249A70();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

} }

