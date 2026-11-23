// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/AIStimulusDetector.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIStimulusDetector::vfunc_01 (0x00102B20, 25 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIStimulusDetector::vfunc_01 (Proto 0x00102B20, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000E4210();
    int sub_00148D30(int);
};

class AIStimulusDetector
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1);
    int m_Field04; // +0x04
};

void AIStimulusDetector::vfunc_01(int a1)
{
    m_Field04 = a1;
    ((Object*)((Object*)a1)->sub_00148D30((int)this))->sub_000E4210();
}

// ============================================================================
// [VERIFIED] AIStimulusDetector::vfunc_00 (0x00102CF0, 64 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: AIStimulusDetector's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// AIStimulusDetector::vfunc_00 (Proto 0x00102CF0, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
    int sub_00148D30(int);
};

struct Object
{
    void sub_000E1DD0();
};

extern "C" char DAT_00389160[];
extern "C" char DAT_0038C5D8[];
extern "C" void __cdecl sub_00025160(int);

class AIStimulusDetector
{
public:
    virtual AIStimulusDetector* vfunc_00(int a1);
    Field04* m_Field04; // +0x04
};

AIStimulusDetector* AIStimulusDetector::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_0038C5D8;
    if (m_Field04) {
        ((Object*)m_Field04->sub_00148D30((int)this))->sub_000E1DD0();
        m_Field04 = 0;
    }
    *(int*)this = (int)DAT_00389160;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

