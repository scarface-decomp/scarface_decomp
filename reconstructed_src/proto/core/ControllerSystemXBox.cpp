// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/ControllerSystemXBox.cpp (11 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 11 of 13 functions matched (84.62%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::ControllerSystemXBox::vfunc_07 (0x00204C20, 88 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x00204C20
// what: 
// tool: the portal's starter code (no AI)

// core::ControllerSystemXBox::vfunc_07 (Proto 0x00204C20, 88 bytes)
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
    virtual void vfunc_08(int, int);
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
    virtual void vfunc_21(int, int);
};

namespace core {

class ControllerSystemXBox
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int a1);
};

void ControllerSystemXBox::vfunc_07(int a1)
{
    int r_ebp, r_ebx, r_edi, r_esi;

    r_edi = a1;
    r_esi = (int)this;
    if (!a1) {
        *(bool*)(r_esi + 16) = false;
        ((Object*)r_esi)->vfunc_08(a1, a1);
        r_edi = 10;
    } else {
        *(bool*)(r_esi + 16) = true;
    }
    r_ebp = *(int*)(r_esi + 4768);
    *(int*)(r_esi + 24) = r_edi;
    r_esi += 32;
    r_ebx = 4;
    do {
        if (*(bool*)(r_esi + 1182)) {
            ((Object*)r_esi)->vfunc_21(r_edi, r_ebp);
        }
        r_esi += 1184;
        r_ebx -= 1;
    } while (r_ebx);
}

}

// ============================================================================
// [VERIFIED] core::ControllerSystemXBox::vfunc_08 (0x00204C80, 74 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x00204C80
// what: 
// tool: the portal's starter code (no AI)

// core::ControllerSystemXBox::vfunc_08 (Proto 0x00204C80, 74 bytes)
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
    virtual void vfunc_19(int);
};

extern "C" int __cdecl sub_001FFF50(void);

namespace core {

class ControllerSystemXBox
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
    virtual void vfunc_08(int a1, int a2);
    char m_pad04[0x10];
    int m_Field14; // +0x14
    char m_pad18[0x8];
    int m_Field20; // +0x20
};

void ControllerSystemXBox::vfunc_08(int a1, int a2)
{
    int r_ebx, r_esi;

    m_Field14 = a2 - a1;
    r_esi = (int)(&m_Field20);
    r_ebx = 4;
    do {
        if (*(bool*)(r_esi + 1182)) {
            ((Object*)r_esi)->vfunc_19(sub_001FFF50() + m_Field14);
        }
        r_esi += 1184;
        r_ebx -= 1;
    } while (r_ebx);
}

}

// ============================================================================
// [VERIFIED] core::ControllerSystemXBox::vfunc_10 (0x00204CD0, 22 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::ControllerSystemXBox::vfunc_10 (Proto 0x00204CD0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class ControllerSystemXBox
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int);
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10(int a1);
    char m_pad04[0x14];
    int m_Field18; // +0x18
    char m_pad1C[0x1284];
    int m_Field12A0; // +0x12A0
};

void ControllerSystemXBox::vfunc_10(int a1)
{
    m_Field12A0 = a1;
    a1 = m_Field18;
    vfunc_07(a1);
}

}

// ============================================================================
// [VERIFIED] core::ControllerSystemXBox::vfunc_11 (0x00204CF0, 17 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::ControllerSystemXBox::vfunc_11 (Proto 0x00204CF0, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class ControllerSystemXBox
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
    virtual int vfunc_11(int a1);
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

int ControllerSystemXBox::vfunc_11(int a1)
{
    int r_eax;

    r_eax = m_Field1C;
    if (!r_eax) {
        r_eax = a1;
        m_Field1C = a1;
    }
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] core::ControllerSystemXBox::vfunc_01 (0x002057E0, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::ControllerSystemXBox::vfunc_01 (Proto 0x002057E0, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class ControllerSystemXBox
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

void ControllerSystemXBox::vfunc_01()
{
    m_Field0C -= 1;
}

}

// ============================================================================
// [VERIFIED] core::ControllerSystemXBox::vfunc_04 (0x00205A70, 43 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::ControllerSystemXBox::vfunc_04 (Proto 0x00205A70, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual bool vfunc_04();
};

namespace core {

class ControllerSystemXBox
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04();
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

int ControllerSystemXBox::vfunc_04()
{
    int r_ebx, r_edi, r_esi;

    r_ebx = 0;
    r_esi = (int)(&m_Field20);
    r_edi = 4;
    do {
        if (((Object*)r_esi)->vfunc_04()) {
            r_ebx += 1;
        }
        r_esi += 1184;
        r_edi -= 1;
    } while (r_edi);
    return r_ebx;
}

}

// ============================================================================
// [VERIFIED] core::ControllerSystemXBox::vfunc_05 (0x00205AA0, 72 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::ControllerSystemXBox::vfunc_05 (Proto 0x00205AA0, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual bool vfunc_04();
};

namespace core {

class ControllerSystemXBox
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05(int a1);
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

int ControllerSystemXBox::vfunc_05(int a1)
{
    int r_ebx, r_edi, r_esi;

    r_ebx = 0;
    r_esi = 0;
    r_edi = (int)(&m_Field20);
    do {
        if (((Object*)r_edi)->vfunc_04()) {
            if (r_ebx == a1) goto L_37;
            r_ebx += 1;
        }
        r_esi += 1;
        r_edi += 1184;
    } while ((unsigned int)r_esi < (unsigned int)4);
    return 0;
L_37:
    r_esi = r_esi * 1184;
    return r_esi + (int)this + 32;
}

}

// ============================================================================
// [VERIFIED] core::ControllerSystemXBox::vfunc_09 (0x00205B70, 49 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x00205B70
// what: 
// tool: the portal's starter code (no AI)

// core::ControllerSystemXBox::vfunc_09 (Proto 0x00205B70, 49 bytes)
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
    virtual void vfunc_20(int);
};

namespace core {

class ControllerSystemXBox
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
    virtual void vfunc_09(int a1);
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

void ControllerSystemXBox::vfunc_09(int a1)
{
    int r_edi, r_esi;

    r_esi = (int)(&m_Field20);
    r_edi = 4;
    do {
        if (*(bool*)(r_esi + 1182)) {
            ((Object*)r_esi)->vfunc_20(a1);
        }
        r_esi += 1184;
        r_edi -= 1;
    } while (r_edi);
}

}

// ============================================================================
// [VERIFIED] core::ControllerSystemXBox::vfunc_12 (0x00205BB0, 19 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::ControllerSystemXBox::vfunc_12 (Proto 0x00205BB0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class ControllerSystemXBox
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
    virtual int vfunc_12(int a1);
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

int ControllerSystemXBox::vfunc_12(int a1)
{
    int r_eax;

    r_eax = m_Field1C;
    if (r_eax == a1) {
        m_Field1C = 0;
    }
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] core::ControllerSystemXBox::vfunc_00 (0x00205BD0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::ControllerSystemXBox::vfunc_00 (0x00205BD0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x00205BE0. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_00205BE0(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_00205BE0(); };

class ControllerSystemXBox : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    ControllerSystemXBox();
    virtual void sub_00205BE0();          // the real function; the thunk jumps here
};

ControllerSystemXBox::ControllerSystemXBox() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::ControllerSystemXBox::vfunc_03 (0x00205BE0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::ControllerSystemXBox::vfunc_03 (0x00205BE0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00429338;
extern "C" void __cdecl sub_00201990(int, int);
extern "C" void __cdecl sub_00205C10(void);

namespace core {

class ControllerSystemXBox
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ControllerSystemXBox* vfunc_03(int a1);
};

ControllerSystemXBox* ControllerSystemXBox::vfunc_03(int a1)
{
    sub_00205C10();
    if (a1 & 1) {
        sub_00201990(DAT_00429338, (int)this);
    }
    return this;
}

}

