// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/WeaponTemplate.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] WeaponTemplate::vfunc_00 (0x001C4580, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// WeaponTemplate::vfunc_00 (0x001C4580, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0041A924[];

class WeaponTemplate
{
public:
    virtual void* vfunc_00();
};

void* WeaponTemplate::vfunc_00()
{
    return DAT_0041A924;
}

// ============================================================================
// [VERIFIED] WeaponTemplate::vfunc_05 (0x001C4960, 51 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// bin: proto
// va: 0x001C4960
// what: 
// tool: the portal's starter code (no AI)

// WeaponTemplate::vfunc_05 (Proto 0x001C4960, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004616C0[];
extern "C" void __stdcall sub_00028C40(int);

class WeaponTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    char m_pad04[0x20];
    int m_Field24; // +0x24
    char m_pad28[0x68];
    int m_Field90; // +0x90
    float m_Field94; // +0x94
};

void WeaponTemplate::vfunc_05(int a1)
{
    sub_00028C40(a1);
    DAT_004616C0[m_Field24] = (int)this;
    if (0.0f > m_Field94) {
        *(int*)((char*)this + 0x94) = m_Field90;
    }
}

