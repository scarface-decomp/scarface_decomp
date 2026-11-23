// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/EnterExitScriptTrack_.cpp (11 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 11 of 12 functions matched (91.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_19 (0x00020350, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_19 (0x000226C0), which was matched first;
// its addresses and names were swapped for this function's.
// FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_19 (0x00020350, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace fight { class EnterExitScriptTrack; }

namespace FightTree { 
template <class T0> class FightActionController
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
    virtual int vfunc_19(int a1);
};
}

template <> int FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_19(int a1)
{
    int r_eax;

    r_eax = 0;
    if (a1) {
        r_eax = *(int*)a1;
        r_eax = ((int (__cdecl*)(void))*(int*)(r_eax + 16))();
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_23 (0x00020370, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_23 (0x000226E0), which was matched first;
// its addresses and names were swapped for this function's.
// FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_23 (0x00020370, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace fight { class EnterExitScriptTrack; }

namespace FightTree { 
template <class T0> class FightActionController
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
    virtual float vfunc_23();
    char m_pad04[0x8];
    float m_Field0C; // +0x0C
};
}

template <> float FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_23()
{
    return m_Field0C;
}

// ============================================================================
// [VERIFIED] FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_24 (0x00020380, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// What it does: Stores a number at +0xC and returns true.
// ============================================================================
// Same machine code as FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_24 (0x000226F0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00020380
// what: Stores a number at +0xC and returns true.
// tool: Claude Opus 5.5 (generated from the shape 'set float field, return true', checked on decomp.me preset 266 by example)
class Class_00020380
{
public:
    bool sub_00020380(float value);
    char m_pad00[0xC];
    float m_FieldC; // +0xC
};

bool Class_00020380::sub_00020380(float value)
{
    m_FieldC = value;
    return true;
}

// ============================================================================
// [VERIFIED] FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_25 (0x00020390, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_25 (Proto 0x00020390, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace fight { class EnterExitScriptTrack; }

namespace FightTree { 
template <class T0> class FightActionController
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
    virtual float vfunc_25();
    char m_pad04[0xC];
    float m_Field10; // +0x10
};
}

template <> float FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_25()
{
    return m_Field10;
}

// ============================================================================
// [VERIFIED] FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_26 (0x000203A0, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// What it does: Stores a number at +0x10 and returns true.
// ============================================================================
// Same machine code as FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_26 (0x00022700), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x000203A0
// what: Stores a number at +0x10 and returns true.
// tool: Claude Opus 5.5 (generated from the shape 'set float field, return true', checked on decomp.me preset 266 by example)
class Class_000203A0
{
public:
    bool sub_000203A0(float value);
    char m_pad00[0x10];
    float m_Field10; // +0x10
};

bool Class_000203A0::sub_000203A0(float value)
{
    m_Field10 = value;
    return true;
}

// ============================================================================
// [VERIFIED] FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_03 (0x00020420, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_03 (0x000227A0), which was matched first;
// its addresses and names were swapped for this function's.
// FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_03 (0x00020420, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001F82F0(void);
extern "C" void __cdecl sub_001FCF60(int);

namespace fight { class EnterExitScriptTrack; }

namespace FightTree { 
template <class T0> class FightActionController
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual FightActionController<fight::EnterExitScriptTrack>* vfunc_03(int a1);
};
}

template <> FightTree::FightActionController<fight::EnterExitScriptTrack>* FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_03(int a1)
{
    sub_001F82F0();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_16 (0x000D7640, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_16 (0x000518D0), which was matched first;
// its addresses and names were swapped for this function's.
// FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_16 (0x000D7640, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CD94;

namespace fight { class EnterExitScriptTrack; }

namespace FightTree { 
template <class T0> class FightActionController
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
    virtual float vfunc_16();
};
}

template <> float FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_16()
{
    return DAT_0037CD94;
}

// ============================================================================
// [VERIFIED] FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_17 (0x000D7700, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_17 (0x00022980), which was matched first;
// its addresses and names were swapped for this function's.
// FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_17 (0x000D7700, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE60;

namespace fight { class EnterExitScriptTrack; }

namespace FightTree { 
template <class T0> class FightActionController
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
    virtual float vfunc_17();
};
}

template <> float FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_17()
{
    return DAT_0037CE60;
}

// ============================================================================
// [VERIFIED] FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_08 (0x001F8300, 25 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_08 (Proto 0x001F8300, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00428520[];

namespace fight { class EnterExitScriptTrack; }

namespace FightTree { 
template <class T0> class FightActionController
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
    virtual int vfunc_08(int a1);
};
}

template <> int FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_08(int a1)
{
    int r_eax;

    r_eax = 0;
    if (a1 >= 0) {
        if ((unsigned int)a1 >= (unsigned int)2) goto L_16;
        r_eax = DAT_00428520[a1];
    }
L_16:
    return r_eax;
}

// ============================================================================
// [VERIFIED] FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_31 (0x001F83B0, 3 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_31 (0x001E0B70), which was matched first;
// its addresses and names were swapped for this function's.
// FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_31 (0x001F83B0, 3 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace fight { class EnterExitScriptTrack; }

namespace FightTree { 
template <class T0> class FightActionController
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
    virtual void vfunc_31(int a1, int a2);
};
}

template <> void FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_31(int a1, int a2)
{
}

// ============================================================================
// [VERIFIED] FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_18 (0x001FBF50, 13 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_18 (Proto 0x001FBF50, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace fight { class EnterExitScriptTrack; }

namespace FightTree { 
template <class T0> class FightActionController
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
    virtual int vfunc_18(int a1);
};
}

template <> int FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_18(int a1)
{
    *(int*)a1 = -65281;
    return a1;
}

