// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/CompletionEventRequest.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::CompletionEventRequest::vfunc_01 (0x002A98B0, 18 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CompletionEventRequest::vfunc_01 (Proto 0x0026C170), which was matched first;
// its addresses and names were swapped for this function's.
// core::CompletionEventRequest::vfunc_01 (Proto 0x002A98B0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00283BD0(int);

namespace core {

class CompletionEventRequest
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

int CompletionEventRequest::vfunc_01()
{
    sub_00283BD0(m_Field08);
    return 1;
}

}

// ============================================================================
// [VERIFIED] core::CompletionEventRequest::vfunc_06 (0x002A98D0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::CompletionEventRequest: Always returns 23.
// ============================================================================
// core::CompletionEventRequest::vfunc_06 (0x002A98D0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class CompletionEventRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06();
};

int CompletionEventRequest::vfunc_06()
{
    return 23;
}

}

// ============================================================================
// [VERIFIED] core::CompletionEventRequest::vfunc_00 (0x002AA5C0, 74 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CompletionEventRequest::vfunc_00 (Proto 0x0026CE10), which was matched first;
// its addresses and names were swapped for this function's.
// core::CompletionEventRequest::vfunc_00 (Proto 0x002AA5C0, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
};

extern "C" char DAT_003DA6C8[];
extern "C" char DAT_003DA6E8[];
extern "C" char DAT_004BDD44[];
extern "C" int DAT_004BDD60;
extern "C" void __cdecl sub_00283B70(int);
extern "C" void __cdecl sub_00283B80(int);

namespace core {

class CompletionEventRequest
{
public:
    virtual CompletionEventRequest* vfunc_00(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

CompletionEventRequest* CompletionEventRequest::vfunc_00(int a1)
{
    int t1;

    t1 = m_Field0C;
    *(int*)this = (int)DAT_003DA6E8;
    ((Object*)t1)->vfunc_01();
    *(int*)this = (int)DAT_003DA6C8;
    if (a1 & 1) {
        sub_00283B80((int)DAT_004BDD44);
        ((Object*)DAT_004BDD60)->vfunc_05((int)this);
        sub_00283B70((int)DAT_004BDD44);
    }
    return this;
}

}

