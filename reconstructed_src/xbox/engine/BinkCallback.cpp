// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/BinkCallback.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] movie::BinkCallback::vfunc_03 (0x002E4070, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CementLibrary::vfunc_00 (0x002ACF00), which was matched first;
// its addresses and names were swapped for this function's.
// movie::BinkCallback::vfunc_03 (Proto 0x002E4070, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 8 bytes to the start of the object and jumps to the real function at
// 0x002E4080. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (8 bytes).

namespace movie {
class CementLibrary_Base0 { public: virtual void sub_002E4080(); char m_pad04[0x4]; };
class CementLibrary_Base1 { public: virtual void sub_002E4080(); };

class BinkCallback : public CementLibrary_Base0, public CementLibrary_Base1
{
public:
    BinkCallback();
    virtual void sub_002E4080();          // the real function; the thunk jumps here
};

BinkCallback::BinkCallback() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] movie::BinkCallback::vfunc_00 (0x002E4080, 63 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as movie::BinkCallback::vfunc_00 (Proto 0x002B12F0), which was matched first;
// its addresses and names were swapped for this function's.
// movie::BinkCallback::vfunc_00 (Proto 0x002E4080, 63 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039E22C[];
extern "C" char DAT_0039F08C[];
extern "C" int DAT_0045894C;
extern "C" void __cdecl sub_002444F0(int, int);

namespace movie {

class BinkCallback
{
public:
    virtual int vfunc_00(int a1);
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

int BinkCallback::vfunc_00(int a1)
{
    int r_eax;

    if (this) {
        r_eax = (int)(&m_Field08);
    } else {
        r_eax = 0;
    }
    *(int*)r_eax = (int)DAT_0039E22C;
    r_eax = m_Field04;
    DAT_0045894C = r_eax;
    *(int*)this = (int)DAT_0039F08C;
    if (a1 & 1) {
        sub_002444F0(DAT_0045894C, (int)this);
    }
    r_eax = (int)this;
    return r_eax;
}

}

