// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/SkidmarkPrimitive.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::SkidmarkPrimitive::vfunc_08 (0x00050300, 54 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x00050300
// what: 
// tool: the portal's starter code (no AI)

// renderer::SkidmarkPrimitive::vfunc_08 (Proto 0x00050300, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
    int sub_00133AD0();
};

extern "C" char DAT_0044A59C[];
extern "C" bool DAT_0044A5EC;
extern "C" int __cdecl sub_00133750(void);

namespace renderer {

class SkidmarkPrimitive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
};

void SkidmarkPrimitive::vfunc_08()
{
    int r_edi, r_esi;

    if (DAT_0044A5EC) {
        r_edi = ((Object*)sub_00133750())->sub_00133AD0();
        r_esi = 0;
        do {
            ((Object*)*(int*)(((int)DAT_0044A59C) + r_esi))->vfunc_00(r_edi);
            r_esi += 4;
        } while ((unsigned int)r_esi < (unsigned int)32);
    }
}

}

// ============================================================================
// [VERIFIED] renderer::SkidmarkPrimitive::vfunc_03 (0x000505A0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LOSManager::LOSManagerFlowClient::vfunc_00 (0x000179C0), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::SkidmarkPrimitive::vfunc_03 (0x000505A0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003802AC[];
extern "C" void __cdecl sub_001FCF60(int);
extern "C" void __cdecl sub_00217400(void);

namespace renderer {

class SkidmarkPrimitive
{
public:
    virtual SkidmarkPrimitive* vfunc_03(int a1);
};

SkidmarkPrimitive* SkidmarkPrimitive::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003802AC;
    sub_00217400();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

