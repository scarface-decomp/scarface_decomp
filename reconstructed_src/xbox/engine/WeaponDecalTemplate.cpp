// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/WeaponDecalTemplate.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] WeaponDecalTemplate::vfunc_00 (0x001FF470, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// WeaponDecalTemplate::vfunc_00 (0x001FF470, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00440BA8[];

class WeaponDecalTemplate
{
public:
    virtual void* vfunc_00();
};

void* WeaponDecalTemplate::vfunc_00()
{
    return DAT_00440BA8;
}

// ============================================================================
// [VERIFIED] WeaponDecalTemplate::vfunc_11 (0x001FF530, 91 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as WeaponDecalTemplate::vfunc_12 (Proto 0x001C3FD0), which was matched first;
// its addresses and names were swapped for this function's.
// WeaponDecalTemplate::vfunc_11 (Proto 0x001FF530, 91 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00048680(int);
extern "C" void __cdecl sub_002A9290(int);

class WeaponDecalTemplate
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
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
    char m_pad23[0x15];
    int m_Field38; // +0x38
};

void WeaponDecalTemplate::vfunc_11()
{
    int r_edi, r_esi;

    r_esi = (int)(&m_Field38);
    r_edi = 9;
    do {
        if (*(int*)(r_esi + -4)) {
            sub_00048680(r_esi + -4);
        }
        if (*(int*)r_esi) {
            sub_00048680(r_esi);
        }
        if (*(int*)(r_esi + 16)) {
            sub_00048680(r_esi + 16);
        }
        r_esi += 40;
        r_edi -= 1;
    } while (r_edi);
    sub_002A9290((int)this);
    m_Field22 = false;
}

