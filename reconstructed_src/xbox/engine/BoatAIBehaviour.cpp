// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/BoatAIBehaviour.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 7 functions matched (42.86%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] BoatAIBehaviour::vfunc_00 (0x00138CD0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// BoatAIBehaviour::vfunc_00 (0x00138CD0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0042DDA4[];

class BoatAIBehaviour
{
public:
    virtual void* vfunc_00();
};

void* BoatAIBehaviour::vfunc_00()
{
    return DAT_0042DDA4;
}

// ============================================================================
// [VERIFIED] BoatAIBehaviour::vfunc_36 (0x00138D00, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// BoatAIBehaviour::vfunc_36 (0x00138D00, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class BoatAIBehaviour
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
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual int vfunc_36();
    char m_pad04[0x30];
    int m_Field34; // +0x34
};

int BoatAIBehaviour::vfunc_36()
{
    int r_eax, t1;

    r_eax = 2;
    t1 = m_Field34;
    if (m_Field34) {
        r_eax = 4;
        if (*(int*)(t1 + 1400) == 4) goto L_28;
        r_eax = 0;
        r_eax = !*(bool*)(t1 + 1466);
    }
L_28:
    return r_eax;
}

// ============================================================================
// [VERIFIED] BoatAIBehaviour::vfunc_01 (0x00138E70, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// BoatAIBehaviour::vfunc_01 (0x00138E70, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B1FA4[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_0014A260(void);

class BoatAIBehaviour
{
public:
    virtual void vfunc_00();
    virtual BoatAIBehaviour* vfunc_01(int a1);
};

BoatAIBehaviour* BoatAIBehaviour::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003B1FA4;
    sub_0014A260();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

