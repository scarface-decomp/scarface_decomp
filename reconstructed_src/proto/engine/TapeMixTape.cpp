// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/TapeMixTape.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 6 functions matched (50.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] TapeMixTape::vfunc_00 (0x001A0150, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// TapeMixTape::vfunc_00 (0x001A0150, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0041506C[];

class TapeMixTape
{
public:
    virtual void* vfunc_00();
};

void* TapeMixTape::vfunc_00()
{
    return DAT_0041506C;
}

// ============================================================================
// [VERIFIED] TapeMixTape::vfunc_03 (0x001A02E0, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// TapeMixTape::vfunc_03 (Proto 0x001A02E0, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class TapeMixTape
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int TapeMixTape::vfunc_03()
{
    return *(int*)((char*)this - 0x10);
}

// ============================================================================
// [VERIFIED] TapeMixTape::vfunc_01 (0x001A03F0, 43 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: TapeMixTape's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// TapeMixTape::vfunc_01 (Proto 0x001A03F0, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A0F3C[];
extern "C" char DAT_003A0F54[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00029C00(void);

class TapeMixTape
{
public:
    virtual void vfunc_00();
    virtual TapeMixTape* vfunc_01(int a1);
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

TapeMixTape* TapeMixTape::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A0F54;
    m_Field20 = (int)DAT_003A0F3C;
    sub_00029C00();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

