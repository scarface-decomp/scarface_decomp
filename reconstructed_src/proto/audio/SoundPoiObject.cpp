// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/SoundPoiObject.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SoundPoiObject::vfunc_00 (0x0019FD50, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// SoundPoiObject::vfunc_00 (0x0019FD50, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00414CFC[];

class SoundPoiObject
{
public:
    virtual void* vfunc_00();
};

void* SoundPoiObject::vfunc_00()
{
    return DAT_00414CFC;
}

// ============================================================================
// [VERIFIED] SoundPoiObject::vfunc_05 (0x0019FF20, 60 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x0019FF20
// what: 
// tool: the portal's starter code (no AI)

// SoundPoiObject::vfunc_05 (Proto 0x0019FF20, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00028C40(int);
extern "C" int __cdecl sub_00028CF0(int, int);

class SoundPoiObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
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
    virtual void vfunc_27(int);
    char m_pad04[0x5C];
    int m_Field60; // +0x60
    char m_pad64[0x1C];
    int m_Field80; // +0x80
    char m_pad84[0x8];
    int m_Field8C; // +0x8C
};

void SoundPoiObject::vfunc_05(int a1)
{
    int t2;

    sub_00028C40(a1);
    t2 = m_Field8C;
    if (m_Field8C) {
        if (!*(unsigned char*)t2) goto L_2D;
        m_Field80 = sub_00028CF0(t2, 0);
    }
L_2D:
    vfunc_27((int)(&m_Field60));
}

