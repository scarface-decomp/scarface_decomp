// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/SeqEvent.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 6 functions matched (83.33%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::SeqEvent::vfunc_00 (0x0029E710, 20 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEvent::vfunc_00 (Proto 0x0029E710, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002AE3F0(int, int);

namespace audio {

class SeqEvent
{
public:
    virtual void vfunc_00(int a1);
};

void SeqEvent::vfunc_00(int a1)
{
    sub_002AE3F0(a1, (int)this + 8);
}

}

// ============================================================================
// [VERIFIED] audio::SeqEvent::vfunc_01 (0x0029E730, 20 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEvent::vfunc_01 (Proto 0x0029E730, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002AE080(int, int);

namespace audio {

class SeqEvent
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1);
};

void SeqEvent::vfunc_01(int a1)
{
    sub_002AE080(a1, (int)this + 8);
}

}

// ============================================================================
// [VERIFIED] audio::SeqEvent::vfunc_02 (0x0029E750, 22 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEvent::vfunc_02 (Proto 0x0029E750, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002AE390(int, int);

namespace audio {

class SeqEvent
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual bool vfunc_02(int a1);
};

bool SeqEvent::vfunc_02(int a1)
{
    sub_002AE390(a1, (int)this + 8);
    return true;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEvent::vfunc_03 (0x0029E770, 20 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEvent::vfunc_03 (Proto 0x0029E770, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002AE030(int, int);

namespace audio {

class SeqEvent
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1);
};

void SeqEvent::vfunc_03(int a1)
{
    sub_002AE030(a1, (int)this + 8);
}

}

// ============================================================================
// [VERIFIED] audio::SeqEvent::vfunc_06 (0x0029E860, 39 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::SeqEvent::vfunc_06 (Proto 0x0029E860, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_002AE240();
};

extern "C" char DAT_003B9A18[];
extern "C" void __cdecl sub_00025160(int);

namespace audio {

class SeqEvent
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual SeqEvent* vfunc_06(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

SeqEvent* SeqEvent::vfunc_06(int a1)
{
    *(int*)this = (int)DAT_003B9A18;
    m_Field08.sub_002AE240();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

