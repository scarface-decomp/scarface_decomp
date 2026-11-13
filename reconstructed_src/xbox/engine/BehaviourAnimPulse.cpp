// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/BehaviourAnimPulse.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 6 functions matched (50.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] BehaviourAnimPulse::vfunc_00 (0x001C4870, 59 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// BehaviourAnimPulse::vfunc_00 (0x001C4870, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class BehaviourAnimPulse
{
public:
    virtual bool vfunc_00(int a1);
    virtual bool vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int);
    virtual void vfunc_05();
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

bool BehaviourAnimPulse::vfunc_00(int a1)
{
    if (!m_Field04) {
        if (m_Field08) goto L_17;
        return false;
    }
L_17:
    if (!vfunc_01()) {
        vfunc_04(a1);
        vfunc_05();
    }
    return true;
}

// ============================================================================
// [VERIFIED] BehaviourAnimPulse::vfunc_02 (0x001C48E0, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// BehaviourAnimPulse::vfunc_02 (0x001C48E0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class BehaviourAnimPulse
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual bool vfunc_02(bool a1);
    char m_pad04[0x28];
    bool m_Field2C; // +0x2C
};

bool BehaviourAnimPulse::vfunc_02(bool a1)
{
    m_Field2C = a1;
    return a1;
}

// ============================================================================
// [VERIFIED] BehaviourAnimPulse::vfunc_03 (0x001C48F0, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// BehaviourAnimPulse::vfunc_03 (0x001C48F0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class BehaviourAnimPulse
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
    char m_pad04[0x14];
    int m_Field18; // +0x18
    char m_pad1C[0x14];
    int m_Field30; // +0x30
};

int BehaviourAnimPulse::vfunc_03()
{
    int t1;

    t1 = m_Field18;
    m_Field30 = m_Field18;
    return t1;
}

