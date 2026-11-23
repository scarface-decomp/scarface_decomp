// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/OmHalStream.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 8 functions matched (62.50%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::OmHalStream::vfunc_10 (0x00298A30, 11 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::OmHalStream::vfunc_10 (Proto 0x00298A30, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00291030();
};

namespace audio {

class OmHalStream
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
    virtual void vfunc_09();
    virtual void vfunc_10();
};

void OmHalStream::vfunc_10()
{
    ((Object*)(int)this + 444)->sub_00291030();
}

}

// ============================================================================
// [VERIFIED] audio::OmHalStream::vfunc_08 (0x00298C00, 36 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::OmHalStream::vfunc_08 (Proto 0x00298C00, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class OmHalStream
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
    virtual bool vfunc_08(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    char m_pad0C[0x1A8];
    int m_Field1B4; // +0x1B4
};

bool OmHalStream::vfunc_08(int a1)
{
    *(int*)a1 = m_Field1B4;
    m_Field08 -= m_Field1B4;
    m_Field1B4 = 0;
    return true;
}

}

// ============================================================================
// [VERIFIED] audio::OmHalStream::vfunc_09 (0x00298C30, 17 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::OmHalStream::vfunc_09 (Proto 0x00298C30, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class OmHalStream
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
    virtual int vfunc_09(int a1);
};

int OmHalStream::vfunc_09(int a1)
{
    return (a1 << 4) + (int)this + 180;
}

}

// ============================================================================
// [VERIFIED] audio::OmHalStream::vfunc_03 (0x00298C80, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::OmHalStream::vfunc_03 (PC 0x006EC020), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x00298C80
// what: 
// tool: the portal's starter code (no AI)

// audio::OmHalStream::vfunc_03 (PC 0x00298C80, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00298620(int);

namespace audio {

class OmHalStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int OmHalStream::vfunc_03()
{
    return sub_00298620((int)this + 12);
}

}

// ============================================================================
// [VERIFIED] audio::OmHalStream::vfunc_12 (0x002998E0, 40 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::OmHalStream::vfunc_12 (Proto 0x002998E0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field1BC
{
    void sub_00291040();
};

extern "C" char DAT_003B979C[];
extern "C" char DAT_00490D5C[];
extern "C" void __cdecl sub_002935D0(int, int);

namespace audio {

class OmHalStream
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
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    char m_pad04[0x1B8];
    Field1BC m_Field1BC; // +0x1BC
};

void OmHalStream::vfunc_12()
{
    if (this) {
        *(int*)this = (int)DAT_003B979C;
        m_Field1BC.sub_00291040();
        sub_002935D0((int)DAT_00490D5C, (int)this);
    }
}

}

