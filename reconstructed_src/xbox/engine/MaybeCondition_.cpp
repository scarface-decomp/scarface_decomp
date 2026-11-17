// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/MaybeCondition_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] fight::ConditionFactoryTemplate<fight::MaybeCondition>::vfunc_07 (0x0023E000, 65 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::ConditionFactoryTemplate<fight::MaybeCondition>::vfunc_07 (Proto 0x001FB9C0), which was matched first;
// its addresses and names were swapped for this function's.
// fight::ConditionFactoryTemplate<fight::MaybeCondition>::vfunc_07 (Proto 0x0023E000, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00242D20(int);
    void sub_00239EE0();
};

extern "C" char DAT_003D44EC[];
extern "C" int __cdecl sub_0023F760(int);

namespace fight { class MaybeCondition; }

namespace fight { 
template <class T0> class ConditionFactoryTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07();
};
}

template <> int fight::ConditionFactoryTemplate<fight::MaybeCondition>::vfunc_07()
{
    int r_edi, r_esi;

    r_edi = (int)this;
    r_esi = sub_0023F760(20);
    if (r_esi) {
        ((Object*)r_esi)->sub_00239EE0();
        *(int*)r_esi = (int)DAT_003D44EC;
        *(int*)(r_esi + 16) = 0x42C80000;
    } else {
        r_esi = 0;
    }
    if (r_edi) {
        r_edi += 8;
        ((Object*)r_esi + 8)->sub_00242D20(r_edi);
    }
    return r_esi;
}

