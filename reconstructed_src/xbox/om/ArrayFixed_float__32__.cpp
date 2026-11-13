// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, om/ArrayFixed_float__32__.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 3 functions matched (33.33%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::MetaAttrib<container::ArrayFixed<float, 32>>::vfunc_02 (0x00083BF0, 57 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// om::MetaAttrib<container::ArrayFixed<float, 32>>::vfunc_02 (0x00083BF0, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_002D6340(int, int);

namespace om {

class MetaAttrib_container__ArrayFixed_float__32__
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual bool vfunc_02(int a1, int a2);
    char m_pad04[0x10];
    int m_Field14; // +0x14
};

bool MetaAttrib_container__ArrayFixed_float__32__::vfunc_02(int a1, int a2)
{
    int r_edi, r_esi;

    r_edi = m_Field14;
    r_edi += a2;
    r_esi = 0;
L_12:
    if (sub_002D6340(a1, *(int*)(r_edi + (r_esi * 4)))) {
        r_esi += 1;
        if ((unsigned int)r_esi < (unsigned int)32) goto L_12;
        return true;
    }
    return false;
}

}

