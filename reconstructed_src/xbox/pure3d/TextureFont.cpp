// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/TextureFont.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 12 functions matched (41.67%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::TextureFont::vfunc_14 (0x0027D690, 83 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x0027D690
// what: 
// tool: the portal's starter code (no AI)

// pure3d::TextureFont::vfunc_14 (0x0027D690, 83 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int, int);
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
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual int vfunc_32(int, int, int, int, int);
};

extern "C" int DAT_00492F00;

namespace pure3d {

class TextureFont
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
    char m_pad04[0x20];
    int m_Field24; // +0x24
    char m_pad28[0x4];
    int m_Field2C; // +0x2C
};

int TextureFont::vfunc_14(int a1)
{
    int r_eax, r_ecx;

    r_ecx = (int)this;
    r_eax = m_Field2C;
    r_ecx = a1;
    r_eax = *(int*)(r_eax + (r_ecx * 4));
    r_ecx = m_Field24;
    *(int*)(r_ecx + 16) = r_eax;
    if (r_eax) {
        r_eax = *(int*)(r_eax + 12);
    } else {
        r_eax = 0;
    }
    r_ecx = *(int*)(r_ecx + 12);
    ((Object*)r_ecx)->vfunc_05(0x584554, r_eax);
    r_eax = m_Field24;
    r_eax = *(int*)(r_eax + 12);
    r_ecx = DAT_00492F00;
    r_eax = ((Object*)r_ecx)->vfunc_32(r_eax, 0, 8225, 0, 0);
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] pure3d::TextureFont::vfunc_17 (0x0027DE20, 18 B)
// By: lemiur | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Passes the call on to an object held in a global pointer.
// ============================================================================
// bin: xb
// va: 0x0027DE20
// what: Passes the call on to an object held in a global pointer.
// tool: Claude Opus 5.5 (symcov hint: IkeSoundMgr::PropagateForAudio)
// pure3d::TextureFont::vfunc_17 (0x0027DE20)
// Class shape from reports/classes/xb/pure3d__TextureFont.h.
// pure3d is built with frame pointers (push ebp; mov ebp, esp), like the other pure3d functions.
#pragma optimize("y", off)

class Class_00492F00
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
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33(int a1);
};

extern "C" Class_00492F00 *DAT_00492F00;
namespace pure3d {
class TextureFont
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual TextureFont* vfunc_03(unsigned int flags);
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
    virtual void vfunc_17(int a1);
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21(float a1);
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25(int a1);
    void sub_0027E1F0();
    char m_pad04[0x18];
    float m_Field1C; // +0x1C
    char m_pad20[0x4];
    int m_Field24; // +0x24
};
}

namespace pure3d {

// Forwards the argument to slot 33 of the global object.
void TextureFont::vfunc_17(int a1)
{
    DAT_00492F00->vfunc_33(a1);
}

}

// ============================================================================
// [VERIFIED] pure3d::TextureFont::vfunc_21 (0x0027DF40, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::TextureFont::vfunc_21 (0x0027DF40, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

extern "C" float DAT_0039D584;

namespace pure3d {

class TextureFont
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
    virtual void vfunc_21(float a1);
    char m_pad04[0x18];
    float m_Field1C; // +0x1C
};

void TextureFont::vfunc_21(float a1)
{
    int r_eax;

    if (a1 > DAT_0039D584) {
        r_eax = (int)a1;
        m_Field1C = a1;
        return;
    }
    *(int*)((char*)this + 0x1C) = 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::TextureFont::vfunc_25 (0x0027E140, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::TextureFont::vfunc_25 (0x0027E140, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

namespace pure3d {

class TextureFont
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
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25(int a1);
    char m_pad04[0x20];
    int m_Field24; // +0x24
};

void TextureFont::vfunc_25(int a1)
{
    int r_edi, t2;

    r_edi = a1;
    if (a1) {
        ((Object*)r_edi)->vfunc_00();
    }
    t2 = m_Field24;
    if (m_Field24) {
        ((Object*)t2)->vfunc_01();
    }
    m_Field24 = r_edi;
}

}

// ============================================================================
// [VERIFIED] pure3d::TextureFont::vfunc_03 (0x0027E2C0, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Branch::vfunc_03 (0x0023B160), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" void __cdecl sub_0023F7A0(void* p);

namespace pure3d {

class TextureFont
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual TextureFont* vfunc_03(unsigned int flags);
    void sub_0027E1F0();
};

#pragma optimize("y", off)
TextureFont* TextureFont::vfunc_03(unsigned int flags)
{
    sub_0027E1F0();
    if (flags & 1)
        sub_0023F7A0(this);
    return this;
}
#pragma optimize("", on)

}

