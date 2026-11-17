// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/HUDManager2.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 4 functions matched (50.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] HUDManager2::vfunc_01 (0x0016EE80, 65 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// HUDManager2::vfunc_01 (Proto 0x0016EE80, 65 bytes)
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
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30(int);
};

class HUDManager2
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1, int a2);
    char m_pad04[0x14];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

int HUDManager2::vfunc_01(int a1, int a2)
{
    int r_ebp, r_edi, r_esi, t1;

    r_esi = m_Field1C;
    r_esi -= m_Field18;
    r_esi >>= 2;
    r_edi = 0;
    if (r_esi > 0) {
        r_ebp = a1;
        do {
            t1 = *(int*)(m_Field18 + (r_edi * 4));
            if (*(int*)(m_Field18 + (r_edi * 4))) {
                ((Object*)t1)->vfunc_30(r_ebp);
            }
            r_edi += 1;
        } while (r_edi < r_esi);
    }
    return 4;
}

// ============================================================================
// [VERIFIED] HUDManager2::vfunc_00 (0x0016F780, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// HUDManager2::vfunc_00 (0x0016F780, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0016F660(void);
extern "C" void __cdecl sub_00025160(int);

class HUDManager2
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual HUDManager2* vfunc_00(int a1);
};

HUDManager2* HUDManager2::vfunc_00(int a1)
{
    sub_0016F660();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

