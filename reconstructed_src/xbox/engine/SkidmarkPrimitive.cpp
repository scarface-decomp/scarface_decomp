// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/SkidmarkPrimitive.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] renderer::SkidmarkPrimitive::vfunc_08 (0x0005A8E0, 57 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x0005A8E0
// what: 
// tool: the portal's starter code (no AI)

// renderer::SkidmarkPrimitive::vfunc_08 (0x0005A8E0, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
    int sub_0014FF20();
};

extern "C" char DAT_00475990[];
extern "C" bool DAT_00475A80;
extern "C" int __cdecl sub_0014FFE0(void);

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

    if (DAT_00475A80) {
        r_edi = ((Object*)sub_0014FFE0())->sub_0014FF20();
        r_esi = 0;
        do {
            ((Object*)*(int*)(((int)DAT_00475990) + r_esi))->vfunc_00(r_edi);
            r_esi += 4;
        } while ((unsigned int)r_esi < (unsigned int)192);
    }
}

}

// ============================================================================
// [VERIFIED] renderer::SkidmarkPrimitive::vfunc_03 (0x0005AB70, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: renderer::SkidmarkPrimitive's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as LOSManager::LOSManagerFlowClient::vfunc_00 (0x000179C0), which was matched first;
// its addresses and names were swapped for this function's.
// renderer::SkidmarkPrimitive::vfunc_03 (0x0005AB70, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A1114[];
extern "C" void __cdecl sub_0023F7A0(int);
extern "C" void __cdecl sub_0025D0C0(void);

namespace renderer {

class SkidmarkPrimitive
{
public:
    virtual SkidmarkPrimitive* vfunc_03(int a1);
};

SkidmarkPrimitive* SkidmarkPrimitive::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003A1114;
    sub_0025D0C0();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

}

