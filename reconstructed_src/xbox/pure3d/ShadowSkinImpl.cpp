// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/ShadowSkinImpl.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::ShadowSkinImpl::vfunc_05 (0x002582C0, 34 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::ShadowSkinImpl::vfunc_05 (Proto 0x002145D0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::ShadowSkinImpl::vfunc_05 (Proto 0x002582C0, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00258140(int);
};

extern "C" int __cdecl sub_0023F760(int);

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

    t1 = sub_0023F760(156);
    if (t1) {
        return ((Object*)t1)->sub_00258140((int)this);
    }
    return 0;
}

}

// ============================================================================
// [VERIFIED] pure3d::ShadowSkinImpl::vfunc_03 (0x00259140, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: pure3d::ShadowSkinImpl's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as fight::Branch::vfunc_03 (0x0023B160), which was matched first;
// its addresses and names were swapped for this function's.
extern "C" void __cdecl sub_0023F7A0(void* p);

namespace pure3d {

class ShadowSkinImpl
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ShadowSkinImpl* vfunc_03(unsigned int flags);
    void sub_00258240();
};

#pragma optimize("y", off)
ShadowSkinImpl* ShadowSkinImpl::vfunc_03(unsigned int flags)
{
    sub_00258240();
    if (flags & 1)
        sub_0023F7A0(this);
    return this;
}
#pragma optimize("", on)

}

// ============================================================================
// [VERIFIED] pure3d::ShadowSkinImpl::vfunc_08 (0x00259C30, 75 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::ShadowSkinImpl::vfunc_08 (Proto 0x00215EF0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::ShadowSkinImpl::vfunc_08 (Proto 0x00259C30, 75 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field8C
{
    int sub_002786F0();
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
    void sub_002592F0(int);
    char m_pad04[0x88];
    Field8C* m_Field8C; // +0x8C
    char m_pad90[0x8];
    int m_Field98; // +0x98
};

void ShadowSkinImpl::vfunc_08()
{
    int r_edi, t4;

    if (!m_Field98) {
        r_edi = m_Field8C->sub_002786F0();
        if (r_edi) {
            ((Object*)r_edi)->vfunc_00();
        }
        t4 = m_Field98;
        if (m_Field98) {
            ((Object*)t4)->vfunc_01();
        }
        m_Field98 = r_edi;
    }
    sub_002592F0(m_Field98);
}

}

