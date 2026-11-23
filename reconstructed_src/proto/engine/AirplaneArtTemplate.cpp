// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/AirplaneArtTemplate.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 5 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AirplaneArtTemplate::vfunc_00 (0x001C4D60, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AirplaneArtTemplate::vfunc_00 (0x001C4D60, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0041B2C4[];

class AirplaneArtTemplate
{
public:
    virtual void* vfunc_00();
};

void* AirplaneArtTemplate::vfunc_00()
{
    return DAT_0041B2C4;
}

// ============================================================================
// [VERIFIED] AirplaneArtTemplate::vfunc_01 (0x001C4D70, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// AirplaneArtTemplate::vfunc_01 (0x001C4D70, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A576C[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_001D1010(void);

class AirplaneArtTemplate
{
public:
    virtual void vfunc_00();
    virtual AirplaneArtTemplate* vfunc_01(int a1);
};

AirplaneArtTemplate* AirplaneArtTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A576C;
    sub_001D1010();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] AirplaneArtTemplate::vfunc_05 (0x001C4E50, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001C4E50
// what: 
// tool: the portal's starter code (no AI)

// AirplaneArtTemplate::vfunc_05 (Proto 0x001C4E50, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_001D1320(int);

class AirplaneArtTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    void sub_001C4DA0();
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
};

void AirplaneArtTemplate::vfunc_05(int a1)
{
    sub_001D1320(a1);
    if (m_Field22) {
        sub_001C4DA0();
    }
}

// ============================================================================
// [VERIFIED] AirplaneArtTemplate::vfunc_11 (0x001C4E70, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LoadPackage::vfunc_06 (0x001C63F0), which was matched first;
// its addresses and names were swapped for this function's.
// AirplaneArtTemplate::vfunc_11 (0x001C4E70, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001D1530(void);

class AirplaneArtTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_11();
    void sub_001C4DA0();
};

void AirplaneArtTemplate::vfunc_11()
{
    sub_001D1530();
    sub_001C4DA0();
}

// ============================================================================
// [VERIFIED] AirplaneArtTemplate::vfunc_12 (0x001D1540, 14 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CharacterFightTreeTemplate::vfunc_11 (0x001FB1F0), which was matched first;
// its addresses and names were swapped for this function's.
// AirplaneArtTemplate::vfunc_12 (0x001D1540, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001D1160(void);

class AirplaneArtTemplate
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
    virtual void vfunc_12();
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
};

void AirplaneArtTemplate::vfunc_12()
{
    sub_001D1160();
    m_Field22 = false;
}

