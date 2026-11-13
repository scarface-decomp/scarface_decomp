// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Condition.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 6 functions matched (33.33%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] Condition::vfunc_10 (0x00239D50, 68 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Condition::vfunc_10 (0x00239D50, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int, int);
};

class Condition
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
    virtual int vfunc_08(int);
    virtual void vfunc_09();
    virtual bool vfunc_10(int a1);
};

bool Condition::vfunc_10(int a1)
{
    int r_ebx, r_edi;

    r_edi = 0;
    if (vfunc_08(0)) {
        do {
            r_edi += 1;
        } while (vfunc_08(r_edi));
    }
    r_edi -= 1;
    if (r_edi >= 0) {
        r_ebx = a1;
        do {
            ((Object*)vfunc_08(r_edi))->vfunc_03((int)this, r_ebx);
            r_edi -= 1;
        } while (r_edi >= 0);
    }
    return true;
}

// ============================================================================
// [VERIFIED] fight::Condition::vfunc_03 (0x00239F30, 39 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::Param::vfunc_03 (0x00239CE0), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" char DAT_003D3B14[];
extern "C" void __cdecl sub_0023F7A0(void* p);

namespace fight {

class Condition
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Condition* vfunc_03(unsigned int flags);
    void sub_00239CD0();
};

#pragma optimize("y", off)
Condition* Condition::vfunc_03(unsigned int flags)
{
    *(void**)this = DAT_003D3B14;
    sub_00239CD0();
    if (flags & 1)
        sub_0023F7A0(this);
    return this;
}
#pragma optimize("", on)

}

