// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, engine/BinkCallback.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 3 functions matched (33.33%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] movie::BinkCallback::vfunc_03 (0x00702680, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CementLibrary::vfunc_00 (Proto 0x0026F620), which was matched first;
// its addresses and names were swapped for this function's.
// movie::BinkCallback::vfunc_03 (Proto 0x00702680, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 8 bytes to the start of the object and jumps to the real function at
// 0x00702690. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (8 bytes).

namespace movie {
class CementLibrary_Base0 { public: virtual void sub_00702690(); char m_pad04[0x4]; };
class CementLibrary_Base1 { public: virtual void sub_00702690(); };

class BinkCallback : public CementLibrary_Base0, public CementLibrary_Base1
{
public:
    BinkCallback();
    virtual void sub_00702690();          // the real function; the thunk jumps here
};

BinkCallback::BinkCallback() {}                  // building one is what makes the compiler write its tables and the thunk
}

