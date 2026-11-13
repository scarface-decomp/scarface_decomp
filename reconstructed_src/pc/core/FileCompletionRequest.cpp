// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, core/FileCompletionRequest.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 4 functions matched (25.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::FileCompletionRequest::vfunc_00 (0x006E44D0, 82 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::FileCompletionRequest::vfunc_00 (0x002AA6D0), which was matched first;
// its addresses and names were swapped for this function's.
// core::FileCompletionRequest::vfunc_00 (0x006E44D0, 82 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
};

extern "C" char DAT_00771C98[];
extern "C" char DAT_00771CD8[];
extern "C" char DAT_0085CDDC[];
extern "C" int DAT_0085CDF4;
extern "C" void __cdecl sub_006DF070(int);
extern "C" void __cdecl sub_006DF080(int);

namespace core {

class FileCompletionRequest
{
public:
    virtual FileCompletionRequest* vfunc_00(int a1);
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

FileCompletionRequest* FileCompletionRequest::vfunc_00(int a1)
{
    int t1;

    t1 = m_Field10;
    *(int*)this = (int)DAT_00771CD8;
    ((Object*)t1)->vfunc_01();
    m_Field0C->vfunc_01();
    *(int*)this = (int)DAT_00771C98;
    if (a1 & 1) {
        sub_006DF080((int)DAT_0085CDDC);
        ((Object*)DAT_0085CDF4)->vfunc_05((int)this);
        sub_006DF070((int)DAT_0085CDDC);
    }
    return this;
}

}

