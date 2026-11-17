// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/CompletionEventRequest.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::CompletionEventRequest::vfunc_01 (0x0026C170, 18 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::CompletionEventRequest::vfunc_01 (Proto 0x0026C170, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0023F1E0(int);

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
    sub_0023F1E0(m_Field08);
    return 1;
}

}

// ============================================================================
// [VERIFIED] core::CompletionEventRequest::vfunc_06 (0x0026C190, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::CompletionEventRequest::vfunc_06 (Proto 0x0026C190, 6 bytes)
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
    return 22;
}

}

// ============================================================================
// [VERIFIED] core::CompletionEventRequest::vfunc_00 (0x0026CE10, 74 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::CompletionEventRequest::vfunc_00 (Proto 0x0026CE10, 74 bytes)
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

extern "C" char DAT_003B3AF0[];
extern "C" char DAT_003B3B10[];
extern "C" char DAT_0048E974[];
extern "C" int DAT_0048E990;
extern "C" void __cdecl sub_0023F180(int);
extern "C" void __cdecl sub_0023F190(int);

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
    *(int*)this = (int)DAT_003B3B10;
    ((Object*)t1)->vfunc_01();
    *(int*)this = (int)DAT_003B3AF0;
    if (a1 & 1) {
        sub_0023F190((int)DAT_0048E974);
        ((Object*)DAT_0048E990)->vfunc_05((int)this);
        sub_0023F180((int)DAT_0048E974);
    }
    return this;
}

}

