// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/WakeTemplate.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] WakeTemplate::vfunc_00 (0x001C3E50, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// WakeTemplate::vfunc_00 (0x001C3E50, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00419E14[];

class WakeTemplate
{
public:
    virtual void* vfunc_00();
};

void* WakeTemplate::vfunc_00()
{
    return DAT_00419E14;
}

// ============================================================================
// [VERIFIED] WakeTemplate::vfunc_11 (0x001C3E60, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001C3E60
// what: 
// tool: the portal's starter code (no AI)

// WakeTemplate::vfunc_11 (Proto 0x001C3E60, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class WakeTemplate
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
    virtual unsigned short vfunc_11();
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x5];
    unsigned short m_Field28; // +0x28
};

unsigned short WakeTemplate::vfunc_11()
{
    unsigned short t1;

    t1 = m_Field20;
    m_Field22 = true;
    m_Field28 = t1;
    return t1;
}

// ============================================================================
// [VERIFIED] WakeTemplate::vfunc_12 (0x001C3E70, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// WakeTemplate::vfunc_12 (Proto 0x001C3E70, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class WakeTemplate
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
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
    char m_pad23[0x5];
    unsigned short m_Field28; // +0x28
};

void WakeTemplate::vfunc_12()
{
    m_Field28 = 65535;
    m_Field22 = false;
}

