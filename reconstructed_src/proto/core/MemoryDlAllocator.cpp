// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/MemoryDlAllocator.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 12 functions matched (16.67%). NOT COMPLETE YET.
// The 10 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::MemoryDlAllocator::vfunc_03 (0x0024B1C0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::MemoryDlAllocator::vfunc_03 (0x0024B1C0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00429338;
extern "C" void __cdecl sub_00201990(int, int);
extern "C" void __cdecl sub_0024B1F0(void);

namespace core {

class MemoryDlAllocator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual MemoryDlAllocator* vfunc_03(int a1);
};

MemoryDlAllocator* MemoryDlAllocator::vfunc_03(int a1)
{
    sub_0024B1F0();
    if (a1 & 1) {
        sub_00201990(DAT_00429338, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] core::MemoryDlAllocator::vfunc_00 (0x0024B220, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::MemoryDlAllocator::vfunc_00 (0x0024B220, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x0024B1C0. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_0024B1C0(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_0024B1C0(); };

class MemoryDlAllocator : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    MemoryDlAllocator();
    virtual void sub_0024B1C0();          // the real function; the thunk jumps here
};

MemoryDlAllocator::MemoryDlAllocator() {}                  // building one is what makes the compiler write its tables and the thunk
}

