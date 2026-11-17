// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Wait_AimingAtMe.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 3 functions matched (33.33%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommandWaits::Wait_AimingAtMe::vfunc_00 (0x00138190, 103 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AICommandWaits::Wait_AimingAtMe::vfunc_00 (Proto 0x0011D430), which was matched first;
// its addresses and names were swapped for this function's.
// AICommandWaits::Wait_AimingAtMe::vfunc_00 (Proto 0x00138190, 103 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01(int);
    void sub_00026EC0(int);
    void sub_00026EE0();
    int sub_0011DDE0(int, int);
    int sub_0011DF20();
};

extern "C" int __cdecl sub_00027590(int);

namespace AICommandWaits {

class Wait_AimingAtMe
{
public:
    virtual void vfunc_00(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

void Wait_AimingAtMe::vfunc_00(int a1, int a2)
{
    int local_4, r_eax;

    ((Object*)(int)(&local_4))->sub_00026EC0(10);
    r_eax = sub_00027590(92);
    if (r_eax) {
        r_eax = ((Object*)r_eax)->sub_0011DF20();
    } else {
        r_eax = 0;
    }
    m_Field0C = r_eax;
    r_eax = sub_00027590(16);
    if (r_eax) {
        r_eax = ((Object*)r_eax)->sub_0011DDE0(8, m_Field0C);
    } else {
        r_eax = 0;
    }
    m_Field10 = r_eax;
    ((Object*)r_eax)->vfunc_01(a2);
    ((Object*)(int)(&local_4))->sub_00026EE0();
}

}

