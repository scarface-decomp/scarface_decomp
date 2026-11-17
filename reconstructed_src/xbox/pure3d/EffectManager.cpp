// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/EffectManager.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::prop::EffectManager::vfunc_09 (0x00253650, 63 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::prop::EffectManager::vfunc_09 (0x00253650, 63 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Field18
{
    void sub_00253140(int, int, int);
};

extern "C" int __cdecl sub_00244410(void);
extern "C" void __cdecl sub_00244420(int);

namespace pure3d { namespace prop {

class EffectManager
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
    virtual void vfunc_09(int a1, int a2, int a3);
    char m_pad04[0xC];
    int m_Field10; // +0x10
    char m_pad14[0x4];
    Field18* m_Field18; // +0x18
};

void EffectManager::vfunc_09(int a1, int a2, int a3)
{
    int t1, t2;

    t1 = m_Field10;
    t2 = sub_00244410();
    sub_00244420(t1);
    m_Field18->sub_00253140(a1, a2, a3);
    sub_00244420(t2);
}

} }

// ============================================================================
// [VERIFIED] pure3d::prop::EffectManager::vfunc_07 (0x00254470, 35 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::prop::EffectManager::vfunc_07 (Proto 0x002104C0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::prop::EffectManager::vfunc_07 (Proto 0x00254470, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00253AA0(int);
};

namespace pure3d { namespace prop {

class EffectManager
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
    char m_pad04[0x14];
    int m_Field18; // +0x18
};

int EffectManager::vfunc_07()
{
    int r_eax, r_edi, r_esi;

    r_edi = m_Field18;
    r_eax = *(int*)(r_edi + 12);
    r_esi = 0;
    if (r_eax > 0) {
        do {
            ((Object*)r_edi)->sub_00253AA0(r_esi);
            r_eax = *(int*)(r_edi + 12);
            r_esi += 1;
        } while (r_esi < r_eax);
    }
    return r_eax;
}

} }

// ============================================================================
// [VERIFIED] pure3d::prop::EffectManager::vfunc_08 (0x002544A0, 55 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::prop::EffectManager::vfunc_08 (0x002544A0, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Field18
{
    void sub_00254200(int);
};

extern "C" int __cdecl sub_00244410(void);
extern "C" void __cdecl sub_00244420(int);

namespace pure3d { namespace prop {

class EffectManager
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
    virtual void vfunc_08(int a1);
    char m_pad04[0xC];
    int m_Field10; // +0x10
    char m_pad14[0x4];
    Field18* m_Field18; // +0x18
};

void EffectManager::vfunc_08(int a1)
{
    int t1, t2;

    t1 = m_Field10;
    t2 = sub_00244410();
    sub_00244420(t1);
    m_Field18->sub_00254200(a1);
    sub_00244420(t2);
}

} }

