// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, pure3d/LoadRequest.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] content::LoadRequest::vfunc_03 (0x006EB580, 76 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as content::LoadRequest::vfunc_03 (Proto 0x001FED30), which was matched first;
// its addresses and names were swapped for this function's.
// content::LoadRequest::vfunc_03 (Proto 0x006EB580, 76 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_0073523C[];
extern "C" char DAT_00772428[];
extern "C" void __cdecl sub_006E9810(int);

namespace content {

class LoadRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual LoadRequest* vfunc_03(int a1);
    char m_pad04[0x14];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    char m_pad20[0x104];
    int m_Field124; // +0x124
};

LoadRequest* LoadRequest::vfunc_03(int a1)
{
    int t1, t3, t5;

    t1 = m_Field18;
    *(int*)this = (int)DAT_00772428;
    if (m_Field18) {
        ((Object*)t1)->vfunc_01();
    }
    t3 = m_Field124;
    if (m_Field124) {
        ((Object*)t3)->vfunc_01();
    }
    t5 = m_Field1C;
    if (m_Field1C) {
        ((Object*)t5)->vfunc_01();
    }
    *(int*)this = (int)DAT_0073523C;
    if (a1 & 1) {
        sub_006E9810((int)this);
    }
    return this;
}

}

