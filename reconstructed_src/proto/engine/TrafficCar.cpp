// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/TrafficCar.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] TrafficCar::vfunc_00 (0x001DFDE0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// TrafficCar::vfunc_00 (0x001DFDE0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00426574[];

class TrafficCar
{
public:
    virtual void* vfunc_00();
};

void* TrafficCar::vfunc_00()
{
    return DAT_00426574;
}

// ============================================================================
// [VERIFIED] TrafficCar::vfunc_46 (0x001DFDF0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// TrafficCar::vfunc_46 (0x001DFDF0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001D9150(void);

class TrafficCar
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_46();
};

void TrafficCar::vfunc_46()
{
    sub_001D9150();
}

// ============================================================================
// [VERIFIED] TrafficCar::vfunc_01 (0x001DFEC0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// TrafficCar::vfunc_01 (0x001DFEC0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A9D5C[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_001D8780(void);

class TrafficCar
{
public:
    virtual void vfunc_00();
    virtual TrafficCar* vfunc_01(int a1);
};

TrafficCar* TrafficCar::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A9D5C;
    sub_001D8780();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

