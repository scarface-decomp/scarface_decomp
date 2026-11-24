// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/CementLoadTracker.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CementLoadTracker::vfunc_01 (0x00056430, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CementLoadTracker::vfunc_01 (0x00060C80), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00056430
// what: Decrements the reference count at +0x04 and deletes the CementLoadTracker when it reaches zero.
// tool: Gemini 4 Neon

class CementLoadTracker
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ~CementLoadTracker();
    int m_RefCount; // +0x04
};

void CementLoadTracker::vfunc_01()
{
    if (--m_RefCount == 0) {
        m_RefCount = 0x02222222;
        delete this;
    }
}

// ============================================================================
// [VERIFIED] CementLoadTracker::vfunc_03 (0x000566B0, 59 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: CementLoadTracker's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as CementLoadTracker::vfunc_03 (0x00060EC0), which was matched first;
// its addresses and names were swapped for this function's.
// CementLoadTracker::vfunc_03 (0x000566B0, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000563B0(int);
};

extern "C" char DAT_0037D85C[];
extern "C" char DAT_00380A64[];
extern "C" int DAT_0044A984;
extern "C" void __cdecl sub_00025160(int);

class CementLoadTracker
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual CementLoadTracker* vfunc_03(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

CementLoadTracker* CementLoadTracker::vfunc_03(int a1)
{
    int t1;

    t1 = m_Field08;
    *(int*)this = (int)DAT_00380A64;
    ((Object*)DAT_0044A984)->sub_000563B0(t1);
    m_Field08 = 0;
    *(int*)this = (int)DAT_0037D85C;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

