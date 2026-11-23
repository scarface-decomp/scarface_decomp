// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/RoadPath.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] RoadPath::vfunc_04 (0x000336E0, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// RoadPath::vfunc_04 (0x000336E0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class RoadPath
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    char m_pad04[0x10];
    unsigned char m_Field14; // +0x14
};

void RoadPath::vfunc_04(int a1)
{
    m_Field14 = 2;
}

// ============================================================================
// [VERIFIED] RoadPath::vfunc_01 (0x00033AB0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as RoadPath::vfunc_01 (Proto 0x00030310), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x00033AB0
// what: 
// tool: the portal's starter code (no AI)

// RoadPath::vfunc_01 (Proto 0x00033AB0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class RoadPath
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x8];
    short m_Field0C; // +0x0C
};

int RoadPath::vfunc_01()
{
    return m_Field0C >= 2;
}

// ============================================================================
// [VERIFIED] RoadPath::vfunc_00 (0x000348D0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: RoadPath's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// RoadPath::vfunc_00 (0x000348D0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000344E0(void);
extern "C" void __cdecl sub_00027600(int);

class RoadPath
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual RoadPath* vfunc_00(int a1);
};

RoadPath* RoadPath::vfunc_00(int a1)
{
    sub_000344E0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

