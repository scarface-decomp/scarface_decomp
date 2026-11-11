// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ScatteredEnemyCharacterGeneratorSpawnObject.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 6 functions matched (33.33%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ScatteredEnemyCharacterGeneratorSpawnObject::vfunc_00 (0x001ABE30, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// ScatteredEnemyCharacterGeneratorSpawnObject::vfunc_00 (0x001ABE30, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00417340[];

class ScatteredEnemyCharacterGeneratorSpawnObject
{
public:
    virtual void* vfunc_00();
};

void* ScatteredEnemyCharacterGeneratorSpawnObject::vfunc_00()
{
    return DAT_00417340;
}

// ============================================================================
// [VERIFIED] ScatteredEnemyCharacterGeneratorSpawnObject::vfunc_01 (0x001AC170, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// ScatteredEnemyCharacterGeneratorSpawnObject::vfunc_01 (0x001AC170, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001ABF00(void);
extern "C" void __cdecl sub_00025160(int);

class ScatteredEnemyCharacterGeneratorSpawnObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ScatteredEnemyCharacterGeneratorSpawnObject* vfunc_01(int a1);
};

ScatteredEnemyCharacterGeneratorSpawnObject* ScatteredEnemyCharacterGeneratorSpawnObject::vfunc_01(int a1)
{
    sub_001ABF00();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

