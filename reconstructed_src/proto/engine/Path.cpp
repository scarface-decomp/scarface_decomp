// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/Path.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 5 functions matched (60.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] Path::vfunc_01 (0x00030180, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x00030180
// what: 
// tool: the portal's starter code (no AI)

// Path::vfunc_01 (Proto 0x00030180, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Path
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x8];
    short m_Field0C; // +0x0C
    char m_pad0E[0xA];
    int m_Field18; // +0x18
};

int Path::vfunc_01()
{
    int r_eax;

    r_eax = m_Field18;
    if (r_eax) {
        if (r_eax == 3) goto L_17;
        r_eax = 1;
        if (m_Field0C >= 1) goto L_19;
    }
L_17:
    r_eax = 0;
L_19:
    return r_eax;
}

// ============================================================================
// [VERIFIED] Path::vfunc_00 (0x00030EE0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// Path::vfunc_00 (0x00030EE0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00030BB0(void);
extern "C" void __cdecl sub_00025160(int);

class Path
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Path* vfunc_00(int a1);
};

Path* Path::vfunc_00(int a1)
{
    sub_00030BB0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] Path::vfunc_03 (0x00031000, 34 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Path::vfunc_03 (Proto 0x00031000, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Path
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1, int a2, int a3);
    void sub_00030F00(int, int, int);
};

void Path::vfunc_03(int a1, int a2, int a3)
{
    vfunc_02();
    sub_00030F00(a1, a2, a3);
}

