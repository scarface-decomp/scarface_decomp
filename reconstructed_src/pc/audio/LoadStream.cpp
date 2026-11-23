// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/LoadStream.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] content::LoadStream::vfunc_03 (0x006EAC60, 70 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006EAC60
// what: 
// tool: the portal's starter code (no AI)

// content::LoadStream::vfunc_03 (PC 0x006EAC60, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_0073523C[];
extern "C" char DAT_0077240C[];
extern "C" void __cdecl sub_006DC500(int);
extern "C" void __cdecl sub_006E9810(int);
extern "C" void __cdecl sub_006EA9E0(void);

namespace content {

class LoadStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual LoadStream* vfunc_03(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    char m_pad0C[0x18];
    int m_Field24; // +0x24
};

LoadStream* LoadStream::vfunc_03(int a1)
{
    int t2, t4;

    *(int*)this = (int)DAT_0077240C;
    sub_006EA9E0();
    t2 = m_Field08;
    if (m_Field08) {
        ((Object*)t2)->vfunc_01();
    }
    t4 = m_Field24;
    if (m_Field24) {
        sub_006DC500(t4);
    }
    *(int*)this = (int)DAT_0073523C;
    if (a1 & 1) {
        sub_006E9810((int)this);
    }
    return this;
}

}

