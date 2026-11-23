// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AIStimulusDetector.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIStimulusDetector::vfunc_01 (0x0011DCF0, 25 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIStimulusDetector::vfunc_01 (Proto 0x00102B20), which was matched first;
// its addresses and names were swapped for this function's.
// AIStimulusDetector::vfunc_01 (Proto 0x0011DCF0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000F85F0();
    int sub_001655C0(int);
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
    ((Object*)((Object*)a1)->sub_001655C0((int)this))->sub_000F85F0();
}

// ============================================================================
// [VERIFIED] AIStimulusDetector::vfunc_00 (0x0011DEC0, 64 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: AIStimulusDetector's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as AIStimulusDetector::vfunc_00 (Proto 0x00102CF0), which was matched first;
// its addresses and names were swapped for this function's.
// AIStimulusDetector::vfunc_00 (Proto 0x0011DEC0, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
    int sub_001655C0(int);
};

struct Object
{
    void sub_000F6430();
};

extern "C" char DAT_003AAAE0[];
extern "C" char DAT_003AE7AC[];
extern "C" void __cdecl sub_00027600(int);

class AIStimulusDetector
{
public:
    virtual AIStimulusDetector* vfunc_00(int a1);
    Field04* m_Field04; // +0x04
};

AIStimulusDetector* AIStimulusDetector::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003AE7AC;
    if (m_Field04) {
        ((Object*)m_Field04->sub_001655C0((int)this))->sub_000F6430();
        m_Field04 = 0;
    }
    *(int*)this = (int)DAT_003AAAE0;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

