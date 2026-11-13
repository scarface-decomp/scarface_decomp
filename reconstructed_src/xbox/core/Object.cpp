// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/Object.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::Object::vfunc_00 (0x00026CD0, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::Object::vfunc_00 (0x00026CD0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039F08C[];
extern "C" int DAT_0045894C;
extern "C" void __cdecl sub_002444F0(int, int);

namespace core {

class Object
{
public:
    virtual Object* vfunc_00(int a1);
    int m_Field04; // +0x04
};

Object* Object::vfunc_00(int a1)
{
    DAT_0045894C = m_Field04;
    *(int*)this = (int)DAT_0039F08C;
    if (a1 & 1) {
        sub_002444F0(DAT_0045894C, (int)this);
    }
    return this;
}

}

