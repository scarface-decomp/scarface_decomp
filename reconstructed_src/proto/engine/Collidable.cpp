// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/Collidable.cpp (7 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 7 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] Collidable::vfunc_01 (0x00011E80, 28 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Releases one reference to a loaded object; at the last one it marks it and deletes it.
// ============================================================================
// Same machine code as Collidable::vfunc_01 (0x00011930), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00011E80
// what: Releases one reference to a loaded object; at the last one it marks it and deletes it.
// tool: Claude Opus 5.5 (examiner listing A5 and J10.6 R1; decomp.me preset 266 score 0)
class LoadObject_00011E80
{
public:
    virtual void vfunc_00();
    virtual void sub_00011E80();
    virtual unsigned int vfunc_02();
    virtual ~LoadObject_00011E80();

    unsigned int m_Count; // +0x04
};

void LoadObject_00011E80::sub_00011E80()
{
    if (m_Count < 2)
    {
        m_Count = 0x08000000;
        delete this;
    }
    else
    {
        m_Count--;
    }
}

// ============================================================================
// [VERIFIED] Collidable::vfunc_06 (0x00011EA0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_06 (0x00011A30), which was matched first;
// its addresses and names were swapped for this function's.
// Collidable::vfunc_06 (0x00011EA0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00200290();
};

class Collidable
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
};

void Collidable::vfunc_06()
{
    ((Object*)(int)this + 8)->sub_00200290();
}

// ============================================================================
// [VERIFIED] Collidable::vfunc_03 (0x000123F0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// Collidable::vfunc_03 (0x000123F0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00012300(void);
extern "C" void __cdecl sub_001FCF60(int);

class Collidable
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Collidable* vfunc_03(int a1);
};

Collidable* Collidable::vfunc_03(int a1)
{
    sub_00012300();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] Collidable::vfunc_05 (0x000550C0, 3 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_05 (0x000B7EB0), which was matched first;
// its addresses and names were swapped for this function's.
// Collidable::vfunc_05 (0x000550C0, 3 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Collidable
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual Collidable* vfunc_05();
};

Collidable* Collidable::vfunc_05()
{
    return this;
}

// ============================================================================
// [VERIFIED] Collidable::vfunc_00 (0x00056420, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_00 (0x000CE340), which was matched first;
// its addresses and names were swapped for this function's.
// Collidable::vfunc_00 (0x00056420, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Collidable
{
public:
    virtual void vfunc_00();
    int m_Field04; // +0x04
};

void Collidable::vfunc_00()
{
    m_Field04 += 1;
}

// ============================================================================
// [VERIFIED] Collidable::vfunc_02 (0x00056450, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_02 (0x000CE360), which was matched first;
// its addresses and names were swapped for this function's.
// Collidable::vfunc_02 (0x00056450, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Collidable
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    int m_Field04; // +0x04
};

int Collidable::vfunc_02()
{
    return m_Field04;
}

// ============================================================================
// [VERIFIED] Collidable::vfunc_04 (0x000590D0, 3 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_04 (0x00022720), which was matched first;
// its addresses and names were swapped for this function's.
// Collidable::vfunc_04 (0x000590D0, 3 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Collidable
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual bool vfunc_04();
};

bool Collidable::vfunc_04()
{
    return 0;
}

