// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/EnterExitScriptTrack_.cpp (7 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 7 of 12 functions matched (58.33%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_19 (0x000226C0, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_19 (0x000226C0, 18 bytes)
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
// [VERIFIED] FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_23 (0x000226E0, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_23 (0x000226E0, 4 bytes)
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
// [VERIFIED] FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_03 (0x000227A0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_03 (0x000227A0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0023A8A0(void);
extern "C" void __cdecl sub_0023F7A0(int);

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
    sub_0023A8A0();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_17 (0x00022980, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_17 (0x00022980, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;

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
    return DAT_0039D65C;
}

// ============================================================================
// [VERIFIED] FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_16 (0x000518D0, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_16 (0x000518D0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D584;

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
    return DAT_0039D584;
}

// ============================================================================
// [VERIFIED] FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_08 (0x0023A8B0, 28 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_08 (0x0023A8B0, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

extern "C" int DAT_00457B18[];

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
        if ((unsigned int)a1 >= (unsigned int)2) goto L_18;
        r_eax = DAT_00457B18[a1];
    }
L_18:
    return r_eax;
}

// ============================================================================
// [VERIFIED] FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_18 (0x0023E600, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_18 (0x0023E600, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

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

