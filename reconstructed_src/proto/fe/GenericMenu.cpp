// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/GenericMenu.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 5 functions matched (40.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GenericMenu::vfunc_00 (0x0016FC40, 42 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GenericMenu::vfunc_00 (Proto 0x0016FC40, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int);
};

class GenericMenu
{
public:
    virtual void vfunc_00(int a1);
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

void GenericMenu::vfunc_00(int a1)
{
    int r_ebx, r_edi, r_esi, t1;

    r_esi = m_Field04;
    r_edi = m_Field08;
    if (r_esi != r_edi) {
        r_ebx = a1;
        do {
            t1 = *(int*)r_esi;
            if (*(int*)r_esi) {
                ((Object*)t1)->vfunc_04(r_ebx);
            }
            r_esi += 4;
        } while (r_esi != r_edi);
    }
}

// ============================================================================
// [VERIFIED] GenericMenu::vfunc_05 (0x0016FC80, 10 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GenericMenu::vfunc_05 (Proto 0x0016FC80, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GenericMenu
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
    int m_Field04; // +0x04
    char m_pad08[0xC];
    int m_Field14; // +0x14
};

int GenericMenu::vfunc_05()
{
    return *(int*)(m_Field04 + (m_Field14 * 4));
}

