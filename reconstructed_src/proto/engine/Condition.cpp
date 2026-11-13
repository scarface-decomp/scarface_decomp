// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/Condition.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 6 functions matched (33.33%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] Condition::vfunc_07 (0x00026D50, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Condition::vfunc_07 (0x000CE970), which was matched first;
// its addresses and names were swapped for this function's.
// Condition::vfunc_07 (0x00026D50, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

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
    virtual int vfunc_07();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

int Condition::vfunc_07()
{
    return m_Field08;
}

// ============================================================================
// [VERIFIED] fight::Condition::vfunc_03 (0x001F79E0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LOSManager::LOSManagerFlowClient::vfunc_00 (0x000179C0), which was matched first;
// its addresses and names were swapped for this function's.
// fight::Condition::vfunc_03 (0x001F79E0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003ACD2C[];
extern "C" void __cdecl sub_001FCF60(int);
extern "C" void __cdecl sub_001F7730(void);

namespace fight {

class Condition
{
public:
    virtual Condition* vfunc_03(int a1);
};

Condition* Condition::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003ACD2C;
    sub_001F7730();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

