// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/CopSpawnObject.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 10 functions matched (30.00%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CopSpawnObject::vfunc_04 (0x001DA130, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// CopSpawnObject::vfunc_04 (0x001DA130, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001EA030(void);

class CopSpawnObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
};

void CopSpawnObject::vfunc_04()
{
    sub_001EA030();
}

// ============================================================================
// [VERIFIED] CopSpawnObject::vfunc_00 (0x001DAE20, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// CopSpawnObject::vfunc_00 (0x001DAE20, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043DB24[];

class CopSpawnObject
{
public:
    virtual void* vfunc_00();
};

void* CopSpawnObject::vfunc_00()
{
    return DAT_0043DB24;
}

// ============================================================================
// [VERIFIED] CopSpawnObject::vfunc_01 (0x001DCE40, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GameGroup::vfunc_01 (0x000290E0), which was matched first;
// its addresses and names were swapped for this function's.
// CopSpawnObject::vfunc_01 (0x001DCE40, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C74E4[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_001DC440(void);

class CopSpawnObject
{
public:
    virtual void vfunc_00();
    virtual CopSpawnObject* vfunc_01(int a1);
    void sub_001EA010();
};

CopSpawnObject* CopSpawnObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003C74E4;
    sub_001DC440();
    sub_001EA010();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

