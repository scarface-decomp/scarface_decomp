// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, ai/AIActionUnary.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionUnary::vfunc_04 (0x001047E0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LazyEvaluatorOnSidewalk::vfunc_00 (0x001078B0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x001047E0
// what: Passes the call on to the object this one holds.
// tool: Claude Fable 5.2 (look-alike of 0x000E5480, names and addresses swapped)
// AIActionUnary::vfunc_04 (0x001047E0, 8 bytes)
struct Field08
{
    void sub_00102F90();
};

class AIActionUnary
{
public:
    virtual void vfunc_04();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
};

void AIActionUnary::vfunc_04()
{
    m_Field08->sub_00102F90();
}

// ============================================================================
// [VERIFIED] AIActionUnary::vfunc_00 (0x00104CE0, 50 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: AIActionUnary's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// AIActionUnary::vfunc_00 (Proto 0x00104CE0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

extern "C" char DAT_0038C664[];
extern "C" char DAT_0038C6B0[];
extern "C" void __cdecl sub_00025160(int);

class AIActionUnary
{
public:
    virtual AIActionUnary* vfunc_00(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

AIActionUnary* AIActionUnary::vfunc_00(int a1)
{
    int t1;

    t1 = m_Field08;
    *(int*)this = (int)DAT_0038C6B0;
    if (m_Field08) {
        ((Object*)t1)->vfunc_00(1);
    }
    *(int*)this = (int)DAT_0038C664;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

