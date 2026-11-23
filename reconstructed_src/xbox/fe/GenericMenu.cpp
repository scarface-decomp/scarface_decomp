// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/GenericMenu.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 5 functions matched (40.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GenericMenu::vfunc_00 (0x001973F0, 67 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x001973F0
// what: 
// tool: the portal's starter code (no AI)

// GenericMenu::vfunc_00 (0x001973F0, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int);
};

class GenericMenu
{
public:
    virtual void vfunc_00(int a1);
};

void GenericMenu::vfunc_00(int a1)
{
    int r_ebx, r_edi, r_esi, t1;

    r_edi = (int)this;
    r_esi = *(int*)(r_edi + 4);
    r_ebx = *(int*)(r_edi + 8);
    if (r_esi != r_ebx) {
        do {
            t1 = *(int*)r_esi;
            if (*(int*)r_esi) {
                ((Object*)t1)->vfunc_04(a1);
            }
            r_esi += 4;
        } while (r_esi != r_ebx);
    }
    if (*(bool*)(r_edi + 32)) {
        r_edi = *(int*)(r_edi + 24);
        if (!r_edi) goto L_3C;
        ((Object*)r_edi)->vfunc_00(a1);
    }
L_3C:
    ;
}

// ============================================================================
// [VERIFIED] GenericMenu::vfunc_05 (0x00197440, 10 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GenericMenu::vfunc_05 (Proto 0x0016FC80), which was matched first;
// its addresses and names were swapped for this function's.
// GenericMenu::vfunc_05 (Proto 0x00197440, 10 bytes)
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

