// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ConcreteClassRep_VarietyDeclarationGroup_.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ConcreteClassRep<VarietyDeclarationGroup>::vfunc_01 (0x0008AE40, 53 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ConcreteClassRep<VarietyDeclarationGroup>::vfunc_01 (Proto 0x0008AE40, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00027EF0(int, int);
};

extern "C" char DAT_00383B14[];
extern "C" int __cdecl sub_00025140(int, int);

class VarietyDeclarationGroup;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

template <> int ConcreteClassRep<VarietyDeclarationGroup>::vfunc_01()
{
    int t2;

    t2 = sub_00025140(64, m_Field1C);
    if (t2) {
        ((Object*)t2)->sub_00027EF0(0, m_Field1C);
        *(int*)t2 = (int)DAT_00383B14;
        return t2;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] ConcreteClassRep<VarietyDeclarationGroup>::vfunc_02 (0x0008AE80, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ConcreteClassRep<CollisionBehaviourTypeGroup>::vfunc_02 (0x00011400), which was matched first;
// its addresses and names were swapped for this function's.
// ConcreteClassRep<VarietyDeclarationGroup>::vfunc_02 (0x0008AE80, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_003FE398;
extern "C" int DAT_003FE39C;
extern "C" char DAT_003F6B70[];
extern "C" int DAT_003F6B94;
extern "C" void __cdecl sub_000660D0(int, int);

class VarietyDeclarationGroup;

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

template <> void ConcreteClassRep<VarietyDeclarationGroup>::vfunc_02()
{
    sub_000660D0(DAT_003F6B94, DAT_003FE398);
    DAT_003FE39C = (int)DAT_003F6B70;
}

