// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/SocketComm.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 8 functions matched (50.00%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::SocketComm::vfunc_00 (0x002807C0, 38 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::SocketComm::vfunc_00 (Proto 0x002807C0, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_0028E140(int);

namespace core {

class SocketComm
{
public:
    virtual void vfunc_00(int a1, int a2);
    char m_pad04[0x10880];
    unsigned char m_Field10884; // +0x10884
    char m_pad10885[0xB];
    unsigned short m_Field10890; // +0x10890
};

void SocketComm::vfunc_00(int a1, int a2)
{
    m_Field10890 = (unsigned short)a1;
    m_Field10884 = sub_0028E140(a2);
}

}

// ============================================================================
// [VERIFIED] core::SocketComm::vfunc_01 (0x002807F0, 83 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::SocketComm::vfunc_01 (Proto 0x002807F0, 83 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0028E1E0(void);
extern "C" void __cdecl sub_0028E270(int, int);

namespace core {

class SocketComm
{
public:
    virtual void vfunc_00();
    virtual bool vfunc_01();
    char m_pad04[0x10880];
    bool m_Field10884; // +0x10884
    char m_pad10885[0x3];
    int m_Field10888; // +0x10888
    int m_Field1088C; // +0x1088C
};

bool SocketComm::vfunc_01()
{
    int t1, t3;

    t1 = m_Field1088C;
    if (m_Field1088C != -1) {
        sub_0028E270(t1, 0);
        m_Field1088C = -1;
    }
    t3 = m_Field10888;
    if (m_Field10888 != -1) {
        sub_0028E270(t3, 0);
        m_Field10888 = -1;
    }
    sub_0028E1E0();
    m_Field10884 = false;
    return true;
}

}

// ============================================================================
// [VERIFIED] core::SocketComm::vfunc_05 (0x00280A60, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::SocketComm::vfunc_05 (Proto 0x00280A60, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class SocketComm
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void* vfunc_05();
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

void* SocketComm::vfunc_05()
{
    return &m_Field10;
}

}

// ============================================================================
// [VERIFIED] core::SocketComm::vfunc_03 (0x00280D30, 45 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// core::SocketComm::vfunc_03 (Proto 0x00280D30, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0023F180(int);
extern "C" void __cdecl sub_0023F190(int);

namespace core {

class SocketComm
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    void sub_00280C50();
    char m_pad04[0x1088E];
    bool m_Field10892; // +0x10892
    char m_pad10893[0x15];
    int m_Field108A8; // +0x108A8
};

void SocketComm::vfunc_03()
{
    sub_0023F190((int)(&m_Field108A8));
    m_Field10892 = true;
    sub_00280C50();
    sub_0023F180((int)(&m_Field108A8));
}

}

