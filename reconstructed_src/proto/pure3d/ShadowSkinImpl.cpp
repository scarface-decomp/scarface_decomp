// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/ShadowSkinImpl.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::ShadowSkinImpl::vfunc_05 (0x002145D0, 34 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::ShadowSkinImpl::vfunc_05 (Proto 0x002145D0, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00214450(int);
};

extern "C" int __cdecl sub_001FCF20(int);

namespace pure3d {

class ShadowSkinImpl
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
};

int ShadowSkinImpl::vfunc_05()
{
    int t1;

    t1 = sub_001FCF20(156);
    if (t1) {
        return ((Object*)t1)->sub_00214450((int)this);
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::ShadowSkinImpl::vfunc_03 (0x002153A0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::ShadowSkinImpl::vfunc_03 (0x002153A0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00214550(void);
extern "C" void __cdecl sub_001FCF60(int);

namespace pure3d {

class ShadowSkinImpl
{
public:
    virtual ShadowSkinImpl* vfunc_03(int a1);
};

ShadowSkinImpl* ShadowSkinImpl::vfunc_03(int a1)
{
    sub_00214550();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] pure3d::ShadowSkinImpl::vfunc_08 (0x00215EF0, 75 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::ShadowSkinImpl::vfunc_08 (Proto 0x00215EF0, 75 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field8C
{
    int sub_0022A190();
};

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

namespace pure3d {

class ShadowSkinImpl
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
    void sub_00215530(int);
    char m_pad04[0x88];
    Field8C* m_Field8C; // +0x8C
    char m_pad90[0x8];
    int m_Field98; // +0x98
};

void ShadowSkinImpl::vfunc_08()
{
    int r_edi, t4;

    if (!m_Field98) {
        r_edi = m_Field8C->sub_0022A190();
        if (r_edi) {
            ((Object*)r_edi)->vfunc_00();
        }
        t4 = m_Field98;
        if (m_Field98) {
            ((Object*)t4)->vfunc_01();
        }
        m_Field98 = r_edi;
    }
    sub_00215530(m_Field98);
}

}

