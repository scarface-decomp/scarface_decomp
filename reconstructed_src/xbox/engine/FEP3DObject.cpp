// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/FEP3DObject.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] FEP3DObject::vfunc_04 (0x00023080, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
class FEP3DObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(unsigned char mode);
    void sub_0002B700(int a1);
};

// Calls the same method with 0 once, and a second time unless the mode is 1.
void FEP3DObject::vfunc_04(unsigned char mode)
{
    sub_0002B700(0);
    if (mode != 1)
        sub_0002B700(0);
}

// ============================================================================
// [VERIFIED] FEP3DObject::vfunc_00 (0x00023170, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// FEP3DObject::vfunc_00 (0x00023170, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0041ACC4[];

class FEP3DObject
{
public:
    virtual void* vfunc_00();
};

void* FEP3DObject::vfunc_00()
{
    return DAT_0041ACC4;
}

// ============================================================================
// [VERIFIED] FEP3DObject::vfunc_01 (0x00023480, 89 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FEP3DObject::vfunc_01 (0x00023480, 89 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
};

extern "C" char DAT_0039E5C4[];
extern "C" char DAT_0039E7DC[];
extern "C" void __cdecl sub_00027600(int);

class FEP3DObject
{
public:
    virtual void vfunc_00();
    virtual FEP3DObject* vfunc_01(int a1);
    void sub_0002C720();
    char m_pad04[0x28];
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
};

FEP3DObject* FEP3DObject::vfunc_01(int a1)
{
    int t1, t2, t4, t6;

    t1 = m_Field2C;
    *(int*)this = (int)DAT_0039E7DC;
    if (m_Field2C) {
        t2 = *(int*)(t1 + 68);
        if (*(int*)(t1 + 68)) {
            ((Object*)t2)->vfunc_16();
        }
        t4 = m_Field30;
        if (!m_Field30) goto L_2A;
        ((Object*)t4)->vfunc_01();
    }
L_2A:
    t6 = m_Field2C;
    if (m_Field2C) {
        ((Object*)t6)->vfunc_01();
    }
    *(int*)this = (int)DAT_0039E5C4;
    sub_0002C720();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

