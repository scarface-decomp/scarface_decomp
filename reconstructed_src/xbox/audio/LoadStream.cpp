// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/LoadStream.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] content::LoadStream::vfunc_03 (0x00240100, 80 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// content::LoadStream::vfunc_03 (0x00240100, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_0039E22C[];
extern "C" char DAT_003D4C08[];
extern "C" bool DAT_00492E94;
extern "C" void __cdecl sub_0023F7A0(int);
extern "C" void __cdecl sub_0023FB40(void);
extern "C" void __cdecl sub_0023FDD0(void);

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
    int m_Field28; // +0x28
};

LoadStream* LoadStream::vfunc_03(int a1)
{
    int t2;

    *(int*)this = (int)DAT_003D4C08;
    sub_0023FDD0();
    t2 = m_Field08;
    if (m_Field08) {
        ((Object*)t2)->vfunc_01();
    }
    DAT_00492E94 = false;
    sub_0023FB40();
    m_Field24 = 0;
    m_Field28 = 0;
    *(int*)this = (int)DAT_0039E22C;
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

}

