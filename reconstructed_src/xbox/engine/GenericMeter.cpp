// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/GenericMeter.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GenericMeter::vfunc_03 (0x0018EE90, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GenericMeter::vfunc_03 (Proto 0x0016B4F0), which was matched first;
// its addresses and names were swapped for this function's.
// GenericMeter::vfunc_03 (Proto 0x0018EE90, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GenericMeter
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual float vfunc_03();
    float m_Field04; // +0x04
};

float GenericMeter::vfunc_03()
{
    return m_Field04;
}

// ============================================================================
// [VERIFIED] GenericMeter::vfunc_05 (0x0018EEC0, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GenericMeter::vfunc_05 (Proto 0x0016B520), which was matched first;
// its addresses and names were swapped for this function's.
// GenericMeter::vfunc_05 (Proto 0x0018EEC0, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GenericMeter
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual float vfunc_05();
    char m_pad04[0x4];
    float m_Field08; // +0x08
};

float GenericMeter::vfunc_05()
{
    return m_Field08;
}

// ============================================================================
// [VERIFIED] GenericMeter::vfunc_00 (0x0018F130, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundSequenceLoader::vfunc_03 (0x00065190), which was matched first;
// its addresses and names were swapped for this function's.
// GenericMeter::vfunc_00 (0x0018F130, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B9FA0[];
extern "C" void __cdecl sub_00027600(int);

class GenericMeter
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual GenericMeter* vfunc_00(int a1);
};

GenericMeter* GenericMeter::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003B9FA0;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

