// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/Wait_AttackedBy.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommandWaits::Wait_AttackedBy::vfunc_00 (0x0011D570, 103 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommandWaits::Wait_AttackedBy::vfunc_00 (Proto 0x0011D570, 103 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01(int);
    void sub_00024AB0(int);
    void sub_00024AD0();
    int sub_00102C10(int, int);
    int sub_00102D50();
};

extern "C" int __cdecl sub_00025120(int);

namespace AICommandWaits {

class Wait_AttackedBy
{
public:
    virtual void vfunc_00(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

void Wait_AttackedBy::vfunc_00(int a1, int a2)
{
    int local_4, r_eax;

    ((Object*)(int)(&local_4))->sub_00024AB0(10);
    r_eax = sub_00025120(92);
    if (r_eax) {
        r_eax = ((Object*)r_eax)->sub_00102D50();
    } else {
        r_eax = 0;
    }
    m_Field0C = r_eax;
    r_eax = sub_00025120(16);
    if (r_eax) {
        r_eax = ((Object*)r_eax)->sub_00102C10(40, m_Field0C);
    } else {
        r_eax = 0;
    }
    m_Field10 = r_eax;
    ((Object*)r_eax)->vfunc_01(a2);
    ((Object*)(int)(&local_4))->sub_00024AD0();
}

}

