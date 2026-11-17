// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/Node.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 8 functions matched (37.50%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] fight::Node::vfunc_08 (0x001F8BF0, 58 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// fight::Node::vfunc_08 (Proto 0x001F8BF0, 58 bytes)
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
    virtual void vfunc_09(int);
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
    virtual void vfunc_28(int);
};

extern "C" void __cdecl sub_001F84B0(void);

namespace fight {

class Node
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
    virtual bool vfunc_08();
    char m_pad04[0x28];
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
};

bool Node::vfunc_08()
{
    int r_ebp, r_ebx, t2;

    sub_001F84B0();
    r_ebp = m_Field2C;
    r_ebx = 0;
    if (r_ebp > 0) {
        do {
            t2 = *(int*)(m_Field30 + (r_ebx * 4));
            if (*(int*)(m_Field30 + (r_ebx * 4))) {
                ((Object*)t2)->vfunc_28((int)this);
                ((Object*)t2)->vfunc_09((int)this);
            }
            r_ebx += 1;
        } while (r_ebx < r_ebp);
    }
    return true;
}

}

// ============================================================================
// [VERIFIED] fight::Node::vfunc_09 (0x001F8C30, 43 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// fight::Node::vfunc_09 (Proto 0x001F8C30, 43 bytes)
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
    virtual void vfunc_10(int);
};

namespace fight {

class Node
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
    virtual bool vfunc_09();
    void sub_001F84E0();
    char m_pad04[0x28];
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
};

bool Node::vfunc_09()
{
    int r_esi;

    r_esi = m_Field2C;
    r_esi -= 1;
    if (r_esi >= 0) {
        do {
            ((Object*)*(int*)(m_Field30 + (r_esi * 4)))->vfunc_10((int)this);
            r_esi -= 1;
        } while (r_esi >= 0);
    }
    sub_001F84E0();
    return true;
}

}

// ============================================================================
// [VERIFIED] fight::Node::vfunc_03 (0x001F92F0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// fight::Node::vfunc_03 (0x001F92F0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001F8EF0(void);
extern "C" void __cdecl sub_001FCF60(int);

namespace fight {

class Node
{
public:
    virtual Node* vfunc_03(int a1);
};

Node* Node::vfunc_03(int a1)
{
    sub_001F8EF0();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

