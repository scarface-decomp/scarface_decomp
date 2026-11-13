// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/CivilianInterior.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CivilianInterior::vfunc_00 (0x0016E090, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// CivilianInterior::vfunc_00 (0x0016E090, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00430D9C[];

class CivilianInterior
{
public:
    virtual void* vfunc_00();
};

void* CivilianInterior::vfunc_00()
{
    return DAT_00430D9C;
}

// ============================================================================
// [VERIFIED] CivilianInterior::vfunc_13 (0x0016F2D0, 76 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CivilianInterior::vfunc_13 (0x0016F2D0, 76 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B50D0[];
extern "C" int DAT_0048ACD4;
extern "C" bool DAT_0048ACD8;
extern "C" int __cdecl sub_000700C0(int, int);
extern "C" void __cdecl sub_0016E310(int, int, int);
extern "C" void __cdecl sub_0016F140(void);

class CivilianInterior
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
};

void CivilianInterior::vfunc_13()
{
    sub_0016F140();
    if (!(1 & DAT_0048ACD8)) {
        *(int*)&DAT_0048ACD8 = *(int*)&DAT_0048ACD8 | 1;
        DAT_0048ACD4 = sub_000700C0((int)DAT_003B50D0, 0);
    }
    sub_0016E310((int)this, DAT_0048ACD4, 0);
}

