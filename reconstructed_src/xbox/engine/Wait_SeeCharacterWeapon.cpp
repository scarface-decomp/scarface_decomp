// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Wait_SeeCharacterWeapon.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommandWaits::Wait_SeeCharacterWeapon::vfunc_00 (0x001387C0, 103 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Wait-until-character-sees-weapon: builds its two sub-objects (a 92-byte check and a 16-byte watcher of type 6) and starts the watcher.
// ============================================================================
// Same machine code as AICommandWaits::Wait_SeeCharacterWeapon::vfunc_00 (Proto 0x0011D9E0), which was matched first;
// its addresses and names were swapped for this function's.
// AICommandWaits::Wait_SeeCharacterWeapon::vfunc_00 (Proto 0x001387C0, 103 bytes)
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

class Wait_SeeCharacterWeapon
{
public:
    virtual void vfunc_00(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

void Wait_SeeCharacterWeapon::vfunc_00(int a1, int a2)
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
        r_eax = ((Object*)r_eax)->sub_0011DDE0(6, m_Field0C);
    } else {
        r_eax = 0;
    }
    m_Field10 = r_eax;
    ((Object*)r_eax)->vfunc_01(a2);
    ((Object*)(int)(&local_4))->sub_00026EE0();
}

}

// ============================================================================
// [VERIFIED] AICommandWaits::Wait_SeeCharacterWeapon::vfunc_03 (0x00138CB0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: AICommandWaits::Wait_SeeCharacterWeapon's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// AICommandWaits::Wait_SeeCharacterWeapon::vfunc_03 (0x00138CB0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00138770(void);
extern "C" void __cdecl sub_00027600(int);

namespace AICommandWaits {

class Wait_SeeCharacterWeapon
{
public:
    virtual Wait_SeeCharacterWeapon* vfunc_03(int a1);
};

Wait_SeeCharacterWeapon* Wait_SeeCharacterWeapon::vfunc_03(int a1)
{
    sub_00138770();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

