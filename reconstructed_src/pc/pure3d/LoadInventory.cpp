// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, pure3d/LoadInventory.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] content::LoadInventory::vfunc_03 (0x006E9AE0, 81 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as content::LoadInventory::vfunc_03 (Proto 0x001FD230), which was matched first;
// its addresses and names were swapped for this function's.
// content::LoadInventory::vfunc_03 (Proto 0x006E9AE0, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    void sub_006EA020();
    void sub_006E9160();
};

extern "C" char DAT_0073523C[];
extern "C" char DAT_007723EC[];
extern "C" void __cdecl sub_0043CE70(int);
extern "C" void __cdecl sub_006E9810(int);

namespace content {

class LoadInventory
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual LoadInventory* vfunc_03(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

LoadInventory* LoadInventory::vfunc_03(int a1)
{
    int t1, t5;

    t1 = m_Field08;
    *(int*)this = (int)DAT_007723EC;
    if (m_Field08) {
        ((Object*)t1)->sub_006EA020();
        ((Object*)t1)->sub_006E9160();
        sub_0043CE70(t1);
    }
    t5 = m_Field0C;
    if (m_Field0C) {
        ((Object*)t5)->vfunc_01();
    }
    *(int*)this = (int)DAT_0073523C;
    if (a1 & 1) {
        sub_006E9810((int)this);
    }
    return this;
}

}

