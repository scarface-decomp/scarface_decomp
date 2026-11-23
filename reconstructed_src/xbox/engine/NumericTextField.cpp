// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/NumericTextField.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 5 functions matched (40.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] NumericTextField::vfunc_07 (0x0019D3E0, 49 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as NumericTextField::vfunc_06 (Proto 0x00173380), which was matched first;
// its addresses and names were swapped for this function's.
// NumericTextField::vfunc_07 (Proto 0x0019D3E0, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00023EC0(int);

class NumericTextField
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual bool vfunc_07(int a1, int a2, int a3);
    int m_Field04; // +0x04
    char m_pad08[0x10];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

bool NumericTextField::vfunc_07(int a1, int a2, int a3)
{
    if (a1) {
        m_Field04 = sub_00023EC0(a1);
    }
    m_Field18 = a2;
    m_Field1C = a3;
    return m_Field04;
}

// ============================================================================
// [VERIFIED] NumericTextField::vfunc_00 (0x0019D530, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: NumericTextField's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as SoundSequenceLoader::vfunc_03 (0x00065190), which was matched first;
// its addresses and names were swapped for this function's.
// NumericTextField::vfunc_00 (0x0019D530, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BC9C4[];
extern "C" void __cdecl sub_00027600(int);

class NumericTextField
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual NumericTextField* vfunc_00(int a1);
};

NumericTextField* NumericTextField::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003BC9C4;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

