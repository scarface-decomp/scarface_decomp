// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/HalRsdFileStream.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 12 functions matched (41.67%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::HalRsdFileStream::vfunc_03 (0x002D64B0, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::HalRsdFileStream::vfunc_03 (0x002D64B0, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_002D3500(int);
extern "C" int __cdecl sub_002D3510(int);

namespace audio {

class HalRsdFileStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
    char m_pad04[0x24];
    int m_Field28; // +0x28
};

int HalRsdFileStream::vfunc_03()
{
    if (sub_002D3500(m_Field28 & 15)) {
        return sub_002D3510((int)(&m_Field28));
    }
    return 2048;
}

}

// ============================================================================
// [VERIFIED] audio::HalRsdFileStream::vfunc_09 (0x002D64E0, 32 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::HalRsdFileStream::vfunc_09 (Proto 0x002AD670), which was matched first;
// its addresses and names were swapped for this function's.
// audio::HalRsdFileStream::vfunc_09 (Proto 0x002D64E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003E038C[];

namespace audio {

class HalRsdFileStream
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
    char m_pad04[0x20];
    int m_Field24; // +0x24
};

int HalRsdFileStream::vfunc_09(int a1)
{
    int r_eax;

    r_eax = m_Field24;
    if (!r_eax) {
        r_eax = (int)DAT_003E038C;
        return r_eax;
    }
    r_eax = (a1 << 4) + r_eax + 164;
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] audio::HalRsdFileStream::vfunc_10 (0x002D6500, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CementLibrary::vfunc_01 (0x002ACEB0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::HalRsdFileStream::vfunc_10 (0x002D6500, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002CE4D0();
};

namespace audio {

class HalRsdFileStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_10();
};

void HalRsdFileStream::vfunc_10()
{
    ((Object*)(int)this + 16)->sub_002CE4D0();
}

}

// ============================================================================
// [VERIFIED] audio::HalRsdFileStream::vfunc_15 (0x002D6860, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::HalRsdFileStream::vfunc_15 (0x002D6860, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004C0444;

namespace audio {

class HalRsdFileStream
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
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual int vfunc_15(int a1);
    char m_pad04[0x3D];
    unsigned char m_Field41; // +0x41
    char m_pad42[0x6];
    int m_Field48; // +0x48
};

int HalRsdFileStream::vfunc_15(int a1)
{
    int r_eax;

    r_eax = DAT_004C0444;
    if (r_eax) {
        if (!m_Field41) goto L_2A;
        r_eax = ((int (__cdecl*)(int, int, int, int, int))r_eax)((int)(&m_Field48), a1, 0, 0, 0);
        m_Field41 = (unsigned char)r_eax;
    }
L_2A:
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] audio::HalRsdFileStream::vfunc_12 (0x002D6930, 78 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// audio::HalRsdFileStream::vfunc_12 (0x002D6930, 78 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_002CE560();
};

struct Field20
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_00463A94[];
extern "C" char DAT_00463A9C[];
extern "C" void __cdecl sub_002CF980(int, int);

namespace audio {

class HalRsdFileStream
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
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15(int);
    Field10 m_Field04; // +0x04
    char m_pad05[0xB];
    Field10 m_Field10; // +0x10
    char m_pad11[0xF];
    Field20* m_Field20; // +0x20
    int m_Field24; // +0x24
};

void HalRsdFileStream::vfunc_12()
{
    int t3;

    if (m_Field20) {
        vfunc_15(4);
        m_Field20->vfunc_01();
    }
    t3 = m_Field24;
    if (m_Field24) {
        sub_002CF980((int)DAT_00463A94, t3);
    }
    m_Field10.sub_002CE560();
    m_Field04.sub_002CE560();
    sub_002CF980((int)DAT_00463A9C, (int)this);
}

}

