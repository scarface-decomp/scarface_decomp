// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/NISManager.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 4 functions matched (50.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] NISManager::vfunc_02 (0x000BD120, 116 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// NISManager::vfunc_02 (Proto 0x000BD120, 116 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000D7D80(int);
};

extern "C" int DAT_0045A0EC;

class NISManager
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02(int a1, int a2, int a3);
    void sub_000BC010(int, int);
    void sub_000BC060(int, int);
    int sub_000BC360(int, int);
    void sub_000BCB90(int, int);
    char m_pad04[0xE0];
    int m_FieldE4; // +0xE4
};

int NISManager::vfunc_02(int a1, int a2, int a3)
{
    int r_eax, r_ebx, r_edi;

    r_eax = m_FieldE4;
    if (r_eax == 1) {
        r_eax = ((Object*)DAT_0045A0EC)->sub_000D7D80(16);
        return r_eax;
    }
    r_ebx = a1;
    r_edi = a2;
    if (r_eax == 2) {
        sub_000BC010(a1, a2);
    }
    if (m_FieldE4 == 3) {
        sub_000BC060(r_ebx, r_edi);
    }
    if (m_FieldE4 == 4) {
        sub_000BCB90(r_ebx, r_edi);
    }
    r_eax = m_FieldE4;
    if (!r_eax) {
        r_eax = sub_000BC360(r_ebx, r_edi);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] NISManager::vfunc_00 (0x000BD270, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// NISManager::vfunc_00 (0x000BD270, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000BD070(void);
extern "C" void __cdecl sub_00025160(int);

class NISManager
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual NISManager* vfunc_00(int a1);
};

NISManager* NISManager::vfunc_00(int a1)
{
    sub_000BD070();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

