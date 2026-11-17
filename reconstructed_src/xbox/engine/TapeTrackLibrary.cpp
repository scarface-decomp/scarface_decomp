// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/TapeTrackLibrary.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 6 functions matched (66.67%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] TapeTrackLibrary::vfunc_00 (0x001D7890, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// TapeTrackLibrary::vfunc_00 (0x001D7890, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043B9A8[];

class TapeTrackLibrary
{
public:
    virtual void* vfunc_00();
};

void* TapeTrackLibrary::vfunc_00()
{
    return DAT_0043B9A8;
}

// ============================================================================
// [VERIFIED] TapeTrackLibrary::vfunc_01 (0x001D78A0, 43 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as HitsHUD::vfunc_01 (Proto 0x0016BED0), which was matched first;
// its addresses and names were swapped for this function's.
// TapeTrackLibrary::vfunc_01 (Proto 0x001D78A0, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C6C34[];
extern "C" char DAT_003C6C4C[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_000290C0(void);

class TapeTrackLibrary
{
public:
    virtual void vfunc_00();
    virtual TapeTrackLibrary* vfunc_01(int a1);
    char m_pad04[0x3C];
    int m_Field40; // +0x40
};

TapeTrackLibrary* TapeTrackLibrary::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003C6C4C;
    m_Field40 = (int)DAT_003C6C34;
    sub_000290C0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] TapeTrackLibrary::vfunc_00 (0x001D78D0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// TapeTrackLibrary::vfunc_00 (0x001D78D0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class TapeTrackLibrary
{
public:
    virtual int vfunc_00();
};

int TapeTrackLibrary::vfunc_00()
{
    return *(short*)((char*)this - 0x8);
}

// ============================================================================
// [VERIFIED] TapeTrackLibrary::vfunc_03 (0x001D78E0, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as TapeTrackLibrary::vfunc_03 (Proto 0x0019F920), which was matched first;
// its addresses and names were swapped for this function's.
// TapeTrackLibrary::vfunc_03 (Proto 0x001D78E0, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class TapeTrackLibrary
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int TapeTrackLibrary::vfunc_03()
{
    return *(int*)((char*)this - 0x30);
}

