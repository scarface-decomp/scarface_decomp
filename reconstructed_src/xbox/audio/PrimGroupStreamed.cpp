// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/PrimGroupStreamed.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 6 functions matched (50.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::PrimGroupStreamed::vfunc_07 (0x00292A40, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: pure3d::PrimGroupStreamed: Always returns 129.
// ============================================================================
// Same machine code as pure3d::PrimGroupStreamed::vfunc_07 (Proto 0x0024F300), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::PrimGroupStreamed::vfunc_07 (Proto 0x00292A40, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class PrimGroupStreamed
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
};

int PrimGroupStreamed::vfunc_07()
{
    return 129;
}

}

// ============================================================================
// [VERIFIED] pure3d::PrimGroupStreamed::vfunc_18 (0x00292B40, 23 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x00292B40
// what: 
// tool: the portal's starter code (no AI)

// pure3d::PrimGroupStreamed::vfunc_18 (0x00292B40, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Field50
{
    void sub_002B72E0(int, int, int);
};

namespace pure3d {

class PrimGroupStreamed
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
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18(int a1);
    char m_pad04[0x4C];
    Field50* m_Field50; // +0x50
};

void PrimGroupStreamed::vfunc_18(int a1)
{
    m_Field50->sub_002B72E0(a1, 0, 0);
}

}

// ============================================================================
// [VERIFIED] pure3d::PrimGroupStreamed::vfunc_17 (0x00292B60, 23 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::PrimGroupStreamed::vfunc_18 (0x00292B40), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00292B60
// what: 
// tool: the portal's starter code (no AI)

// pure3d::PrimGroupStreamed::vfunc_17 (0x00292B60, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Field50
{
    void sub_002B73C0(int, int, int);
};

namespace pure3d {

class PrimGroupStreamed
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
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17(int a1);
    char m_pad04[0x4C];
    Field50* m_Field50; // +0x50
};

void PrimGroupStreamed::vfunc_17(int a1)
{
    m_Field50->sub_002B73C0(a1, 0, 0);
}

}

