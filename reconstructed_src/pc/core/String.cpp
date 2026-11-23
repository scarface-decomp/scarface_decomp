// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, core/String.cpp (12 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 12 of 22 functions matched (54.55%). NOT COMPLETE YET.
// The 10 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::String::vfunc_04 (0x006E0090, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E0090
// what: 
// tool: the portal's starter code (no AI)

// core::String::vfunc_04 (PC 0x006E0090, 36 bytes)
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
    virtual int vfunc_08();
};

namespace core {

class String
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual bool vfunc_04(int a1);
    virtual bool vfunc_05(int);
};

bool String::vfunc_04(int a1)
{
    if (a1) {
        return vfunc_05(((Object*)a1)->vfunc_08());
    }
    return false;
}

}

// ============================================================================
// [VERIFIED] core::String::vfunc_24 (0x006E00C0, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns the number at +0x14 with its top bit cleared.
// ============================================================================
// bin: pc
// va: 0x006E00C0
// what: Returns the number at +0x14 with its top bit cleared.
// tool: Claude Opus 5.5 (transplanted from proto:0x000FAB90, nearest by portal/tools/similar.py)
// sub_006E00C0 (Proto 0x006E00C0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006E00C0
{
public:
    int sub_006E00C0();
    char m_pad00[0x14];
    int m_Field14; // +0x14
};

int Class_006E00C0::sub_006E00C0()
{
    return m_Field14 & 2147483647;
}

// ============================================================================
// [VERIFIED] core::String::vfunc_06 (0x006E01E0, 34 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E01E0
// what: 
// tool: the portal's starter code (no AI)

// core::String::vfunc_06 (PC 0x006E01E0, 34 bytes)
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
    virtual int vfunc_08();
};

namespace core {

class String
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int a1);
    virtual void vfunc_07(int);
};

void String::vfunc_06(int a1)
{
    if (a1) {
        if (a1 == (int)this) goto L_1E;
        vfunc_07(((Object*)a1)->vfunc_08());
    }
L_1E:
    ;
}

}

// ============================================================================
// [VERIFIED] core::String::vfunc_08 (0x006E0250, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E0250
// what: 
// tool: the portal's starter code (no AI)

// core::String::vfunc_08 (PC 0x006E0250, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class String
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
    virtual int vfunc_08();
    char m_pad04[0xC];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

int String::vfunc_08()
{
    if (((unsigned char)(((unsigned int)m_Field14) >> 31)) & 1) {
        return 0;
    }
    return m_Field10;
}

}

// ============================================================================
// [VERIFIED] core::String::vfunc_18 (0x006E0290, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E0290
// what: 
// tool: the portal's starter code (no AI)

// core::String::vfunc_18 (PC 0x006E0290, 30 bytes)
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
    virtual int vfunc_08();
};

namespace core {

class String
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
    virtual void vfunc_17(int);
    virtual void vfunc_18(int a1);
};

void String::vfunc_18(int a1)
{
    if (a1) {
        vfunc_17(((Object*)a1)->vfunc_08());
    }
}

}

// ============================================================================
// [VERIFIED] core::String::vfunc_16 (0x006E03E0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E03E0
// what: 
// tool: the portal's starter code (no AI)

// core::String::vfunc_16 (PC 0x006E03E0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class String
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
};

void String::vfunc_16()
{
    vfunc_15();
}

}

// ============================================================================
// [VERIFIED] core::String::vfunc_19 (0x006E04B0, 22 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E04B0
// what: 
// tool: the portal's starter code (no AI)

// core::String::vfunc_19 (PC 0x006E04B0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F23C;

namespace core {

class String
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
    char m_pad04[0xC];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

void String::vfunc_19()
{
    if (!(((unsigned char)(((unsigned int)m_Field14) >> 31)) & 1)) {
        ((void (__cdecl*)(int))DAT_0072F23C)(m_Field10);
    }
}

}

// ============================================================================
// [VERIFIED] core::String::vfunc_20 (0x006E04D0, 22 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::String::vfunc_19 (PC 0x006E04B0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006E04D0
// what: 
// tool: the portal's starter code (no AI)

// core::String::vfunc_20 (PC 0x006E04D0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F238;

namespace core {

class String
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
    char m_pad04[0xC];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

void String::vfunc_20()
{
    if (!(((unsigned char)(((unsigned int)m_Field14) >> 31)) & 1)) {
        ((void (__cdecl*)(int))DAT_0072F238)(m_Field10);
    }
}

}

// ============================================================================
// [VERIFIED] core::String::vfunc_22 (0x006E04F0, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E04F0
// what: 
// tool: the portal's starter code (no AI)

// core::String::vfunc_22 (PC 0x006E04F0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006DE7A0(int, int);

namespace core {

class String
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
    virtual void vfunc_22(int a1);
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

void String::vfunc_22(int a1)
{
    sub_006DE7A0(m_Field10, a1);
}

}

// ============================================================================
// [VERIFIED] core::String::vfunc_21 (0x006E0510, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006E0510
// what: 
// tool: the portal's starter code (no AI)

// core::String::vfunc_21 (PC 0x006E0510, 36 bytes)
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
    virtual int vfunc_08();
};

namespace core {

class String
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
    virtual bool vfunc_21(int a1);
    virtual bool vfunc_22(int);
};

bool String::vfunc_21(int a1)
{
    if (a1) {
        return vfunc_22(((Object*)a1)->vfunc_08());
    }
    return false;
}

}

// ============================================================================
// [VERIFIED] core::String::vfunc_03 (0x006E0540, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::String::vfunc_03 (0x006E0540, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);
extern "C" void __cdecl sub_006E0570(void);

namespace core {

class String
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual String* vfunc_03(int a1);
};

String* String::vfunc_03(int a1)
{
    sub_006E0570();
    if (a1 & 1) {
        sub_006DC430(DAT_007F5A70, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] core::String::vfunc_00 (0x006E05C0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::String::vfunc_00 (0x006E05C0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x006E0540. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_006E0540(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_006E0540(); };

class String : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    String();
    virtual void sub_006E0540();          // the real function; the thunk jumps here
};

String::String() {}                  // building one is what makes the compiler write its tables and the thunk
}

