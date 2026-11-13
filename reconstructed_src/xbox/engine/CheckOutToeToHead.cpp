// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/CheckOutToeToHead.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 7 functions matched (57.14%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CheckOutToeToHead::vfunc_06 (0x000EFD30, 51 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CheckOutToeToHead::vfunc_06 (0x000EFD30, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    bool sub_000CA1C0();
    void sub_000CA300(int, int);
};

class CheckOutToeToHead
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
    char m_pad15[0x3];
    int m_Field18; // +0x18
};

void CheckOutToeToHead::vfunc_06()
{
    if (m_Field18 != 13) {
        if (m_Field14.sub_000CA1C0()) {
            m_Field18 = 13;
            m_Field14.sub_000CA300(1000, 1500);
        }
    }
}

// ============================================================================
// [VERIFIED] CheckOutToeToHead::vfunc_01 (0x000EFD70, 26 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CheckOutToeToHead::vfunc_01 (0x000EFD70, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000CA300(int, int);
};

class CheckOutToeToHead
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    char m_pad04[0x14];
    int m_Field18; // +0x18
};

void CheckOutToeToHead::vfunc_01()
{
    m_Field18 = 6;
    ((Object*)(int)this + 20)->sub_000CA300(750, 1250);
}

// ============================================================================
// [VERIFIED] CheckOutToeToHead::vfunc_08 (0x000EFD90, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GlanceAtOvertakingPed::vfunc_08 (0x000EFD20), which was matched first;
// its addresses and names were swapped for this function's.
// CheckOutToeToHead::vfunc_08 (0x000EFD90, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003D111C;

class CheckOutToeToHead
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
    virtual float vfunc_08();
};

float CheckOutToeToHead::vfunc_08()
{
    return DAT_003D111C;
}

// ============================================================================
// [VERIFIED] CheckOutToeToHead::vfunc_05 (0x000EFDB0, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns a fixed number kept in the game's data.
// ============================================================================
// bin: xb
// va: 0x000EFDB0
// what: Returns a fixed number kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x000EFD20, names and addresses swapped)
// CheckOutToeToHead::vfunc_05 (0x000EFDB0, 7 bytes)
extern "C" float DAT_003AAC30;

class CheckOutToeToHead
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual float vfunc_05();
};

float CheckOutToeToHead::vfunc_05()
{
    return DAT_003AAC30;
}

