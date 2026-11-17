// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/BehaviourAnimPulse.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] BehaviourAnimPulse::vfunc_00 (0x0018F8E0, 37 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// BehaviourAnimPulse::vfunc_00 (Proto 0x0018F8E0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class BehaviourAnimPulse
{
public:
    virtual bool vfunc_00(int a1);
    virtual bool vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int);
    virtual void vfunc_04();
};

bool BehaviourAnimPulse::vfunc_00(int a1)
{
    if (!vfunc_01()) {
        vfunc_03(a1);
        vfunc_04();
    }
    return true;
}

// ============================================================================
// [VERIFIED] BehaviourAnimPulse::vfunc_02 (0x0018F940, 10 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// BehaviourAnimPulse::vfunc_02 (Proto 0x0018F940, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class BehaviourAnimPulse
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual bool vfunc_02(bool a1);
    char m_pad04[0x1C];
    bool m_Field20; // +0x20
};

bool BehaviourAnimPulse::vfunc_02(bool a1)
{
    m_Field20 = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] BehaviourAnimPulse::vfunc_04 (0x0018F9C0, 16 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// BehaviourAnimPulse::vfunc_04 (Proto 0x0018F9C0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
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
    virtual void vfunc_27(int);
};

class BehaviourAnimPulse
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    Field04* m_Field04; // +0x04
    char m_pad08[0x1C];
    unsigned char m_Field24; // +0x24
};

void BehaviourAnimPulse::vfunc_04()
{
    m_Field04->vfunc_27(m_Field24);
}

