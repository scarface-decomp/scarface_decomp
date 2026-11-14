// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/DriveThread.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 5 functions matched (80.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::DriveThread::vfunc_00 (0x00285070, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::DriveThread::vfunc_00 (0x002C1460), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveThread::vfunc_00 (0x00285070, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0023F190(int);

namespace core {

class DriveThread
{
public:
    virtual void vfunc_00();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

void DriveThread::vfunc_00()
{
    sub_0023F190(m_Field08);
}

}

// ============================================================================
// [VERIFIED] core::DriveThread::vfunc_01 (0x00285080, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::DriveThread::vfunc_00 (0x002C1460), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveThread::vfunc_01 (0x00285080, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0023F180(int);

namespace core {

class DriveThread
{
public:
    virtual void vfunc_01();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

void DriveThread::vfunc_01()
{
    sub_0023F180(m_Field08);
}

}

// ============================================================================
// [VERIFIED] core::DriveThread::vfunc_00 (0x002852F0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveThread::vfunc_00 (0x002852F0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x00285670. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_00285670(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_00285670(); };

class DriveThread : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    DriveThread();
    virtual void sub_00285670();          // the real function; the thunk jumps here
};

DriveThread::DriveThread() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::DriveThread::vfunc_03 (0x00285670, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveThread::vfunc_03 (0x00285670, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00429338;
extern "C" void __cdecl sub_00201990(int, int);
extern "C" void __cdecl sub_00285000(void);

namespace core {

class DriveThread
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual DriveThread* vfunc_03(int a1);
};

DriveThread* DriveThread::vfunc_03(int a1)
{
    sub_00285000();
    if (a1 & 1) {
        sub_00201990(DAT_00429338, (int)this);
    }
    return this;
}

}

