// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/SemiConcreteClassRep_AITask_CodeAbstract_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SemiConcreteClassRep<AITask_CodeAbstract>::vfunc_01 (0x000FFDB0, 20 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// SemiConcreteClassRep<AITask_CodeAbstract>::vfunc_01 (Proto 0x000FFDB0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038B80C[];
extern "C" void __cdecl sub_0008ECF0(int, int);

class AITask_CodeAbstract;

template <class T0> class SemiConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x10];
    int m_Field14; // +0x14
};

template <> int SemiConcreteClassRep<AITask_CodeAbstract>::vfunc_01()
{
    sub_0008ECF0((int)DAT_0038B80C, m_Field14);
    return 0;
}

// ============================================================================
// [VERIFIED] SemiConcreteClassRep<AITask_CodeAbstract>::vfunc_02 (0x00101780, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<CollisionSurfaceType>::vfunc_02 (0x00011450), which was matched first;
// its addresses and names were swapped for this function's.
// SemiConcreteClassRep<AITask_CodeAbstract>::vfunc_02 (0x00101780, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00403B00;
extern "C" int DAT_00403B04;
extern "C" char DAT_00403AB0[];
extern "C" int DAT_00403AD4;
extern "C" void __cdecl sub_001011C0(void);
extern "C" void __cdecl sub_000660D0(int, int);

class AITask_CodeAbstract;

template <class T0> class SemiConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void SemiConcreteClassRep<AITask_CodeAbstract>::vfunc_02()
{
    sub_000660D0(DAT_00403AD4, DAT_00403B00);
    DAT_00403B04 = (int)DAT_00403AB0;
    sub_001011C0();
}

