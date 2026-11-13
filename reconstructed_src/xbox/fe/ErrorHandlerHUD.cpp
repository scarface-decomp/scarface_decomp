// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/ErrorHandlerHUD.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 6 functions matched (50.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ErrorHandlerHUD::vfunc_00 (0x00194110, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// ErrorHandlerHUD::vfunc_00 (0x00194110, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00436774[];

class ErrorHandlerHUD
{
public:
    virtual void* vfunc_00();
};

void* ErrorHandlerHUD::vfunc_00()
{
    return DAT_00436774;
}

// ============================================================================
// [VERIFIED] ErrorHandlerHUD::vfunc_04 (0x001941E0, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ErrorHandlerHUD::vfunc_04 (0x001941E0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0048E54C;
extern "C" void __stdcall sub_00193190(int);

class ErrorHandlerHUD
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    char m_pad04[0x64];
    int m_Field68; // +0x68
};

void ErrorHandlerHUD::vfunc_04(int a1)
{
    sub_00193190(a1);
    m_Field68 = DAT_0048E54C;
}

// ============================================================================
// [VERIFIED] ErrorHandlerHUD::vfunc_01 (0x00194350, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as HitsHUD::vfunc_01 (0x00190610), which was matched first;
// its addresses and names were swapped for this function's.
// ErrorHandlerHUD::vfunc_01 (0x00194350, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BAF04[];
extern "C" char DAT_003BAF0C[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00193F80(void);

class ErrorHandlerHUD
{
public:
    virtual void vfunc_00();
    virtual ErrorHandlerHUD* vfunc_01(int a1);
    char m_pad04[0x60];
    int m_Field64; // +0x64
};

ErrorHandlerHUD* ErrorHandlerHUD::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003BAF0C;
    m_Field64 = (int)DAT_003BAF04;
    sub_00193F80();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

