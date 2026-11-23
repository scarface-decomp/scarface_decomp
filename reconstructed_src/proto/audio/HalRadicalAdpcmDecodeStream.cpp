// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, audio/HalRadicalAdpcmDecodeStream.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 13 functions matched (46.15%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::HalRadicalAdpcmDecodeStream::vfunc_10 (0x002AD200, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::HalRadicalAdpcmDecodeStream::vfunc_10 (Proto 0x002AD200, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
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

namespace audio {

class HalRadicalAdpcmDecodeStream
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
    Field04* m_Field04; // +0x04
};

void HalRadicalAdpcmDecodeStream::vfunc_10()
{
    m_Field04->vfunc_10();
}

}

// ============================================================================
// [VERIFIED] audio::HalRadicalAdpcmDecodeStream::vfunc_12 (0x002AD210, 12 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::HalRadicalAdpcmDecodeStream::vfunc_12 (Proto 0x002AD210, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class HalRadicalAdpcmDecodeStream
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
    virtual void vfunc_13(int);
};

void HalRadicalAdpcmDecodeStream::vfunc_12()
{
    if (this) {
        vfunc_13(1);
    }
}

}

// ============================================================================
// [VERIFIED] audio::HalRadicalAdpcmDecodeStream::vfunc_09 (0x002AD340, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::HalRadicalAdpcmDecodeStream::vfunc_09 (Proto 0x002AD340, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
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
};

namespace audio {

class HalRadicalAdpcmDecodeStream
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
    Field04* m_Field04; // +0x04
};

void HalRadicalAdpcmDecodeStream::vfunc_09()
{
    m_Field04->vfunc_09();
}

}

// ============================================================================
// [VERIFIED] audio::HalRadicalAdpcmDecodeStream::vfunc_00 (0x002AD350, 32 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::HalRadicalAdpcmDecodeStream::vfunc_00 (Proto 0x002AD350, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
    virtual void vfunc_00();
};

struct Object
{
    virtual void vfunc_00();
    virtual int vfunc_01();
};

namespace audio {

class HalRadicalAdpcmDecodeStream
{
public:
    virtual void vfunc_00();
    Field04* m_Field04; // +0x04
    char m_pad08[0x14];
    int m_Field1C; // +0x1C
};

void HalRadicalAdpcmDecodeStream::vfunc_00()
{
    Field04* t1;

    t1 = m_Field04;
    m_Field1C = 1;
    if (!((Object*)(int)t1)->vfunc_01()) {
        m_Field04->vfunc_00();
        return;
    }
}

}

// ============================================================================
// [VERIFIED] audio::HalRadicalAdpcmDecodeStream::vfunc_02 (0x002AD3B0, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::HalRadicalAdpcmDecodeStream::vfunc_02 (Proto 0x002AD3B0, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class HalRadicalAdpcmDecodeStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void* vfunc_02();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

void* HalRadicalAdpcmDecodeStream::vfunc_02()
{
    return &m_Field08;
}

}

// ============================================================================
// [VERIFIED] audio::HalRadicalAdpcmDecodeStream::vfunc_13 (0x002AD500, 44 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: audio::HalRadicalAdpcmDecodeStream's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// audio::HalRadicalAdpcmDecodeStream::vfunc_13 (Proto 0x002AD500, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
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
};

extern "C" char DAT_003BB248[];
extern "C" char DAT_00491458[];
extern "C" void __cdecl sub_002935D0(int, int);

namespace audio {

class HalRadicalAdpcmDecodeStream
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
    virtual HalRadicalAdpcmDecodeStream* vfunc_13(int a1);
    int m_Field04; // +0x04
};

HalRadicalAdpcmDecodeStream* HalRadicalAdpcmDecodeStream::vfunc_13(int a1)
{
    int t1;

    t1 = m_Field04;
    *(int*)this = (int)DAT_003BB248;
    ((Object*)t1)->vfunc_12();
    if (a1 & 1) {
        sub_002935D0((int)DAT_00491458, (int)this);
    }
    return this;
}

}

