// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/ParamEnum_SoundPlayTrack_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] fight::ParamEnum<SoundPlayTrack>::vfunc_06 (0x000E9F80, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Invokes the SoundPlayTrack member-function pointer at +0x0C on the given track.
// ============================================================================
// bin: xb
// va: 0x000E9F80
// what: Invokes the SoundPlayTrack member-function pointer at +0x0C on the given track.
// tool: Gemini 4 Neon

class SoundPlayTrack {};

namespace fight {

template<class T>
class ParamEnum
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06(T* target);
    char m_pad04[0x8];
    int (T::*m_Getter)(); // +0x0C
};

template<class T>
int ParamEnum<T>::vfunc_06(T* target)
{
    return (target->*m_Getter)();
}

template class ParamEnum<SoundPlayTrack>;

}

