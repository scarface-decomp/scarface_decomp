// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/HalRsdFileStream.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 12 functions matched (25.00%). NOT COMPLETE YET.
// The 9 still to do are listed in their place in Original_Binary_Order_PC_1002.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] audio::HalRsdFileStream::vfunc_03 (0x006F3540, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::HalRsdFileStream::vfunc_03 (0x002D64B0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::HalRsdFileStream::vfunc_03 (0x006F3540, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F1390(int);
extern "C" int __cdecl sub_006F13A0(int);

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
    if (sub_006F1390(m_Field28 & 15)) {
        return sub_006F13A0((int)(&m_Field28));
    }
    return 2048;
}

}

// ============================================================================
// [VERIFIED] audio::HalRsdFileStream::vfunc_09 (0x006F3570, 32 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::HalRsdFileStream::vfunc_09 (Proto 0x002AD670), which was matched first;
// its addresses and names were swapped for this function's.
// audio::HalRsdFileStream::vfunc_09 (Proto 0x006F3570, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772AD4[];

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
        r_eax = (int)DAT_00772AD4;
        return r_eax;
    }
    r_eax = (a1 << 4) + r_eax + 164;
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] audio::HalRsdFileStream::vfunc_10 (0x006F3590, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CementLibrary::vfunc_01 (0x002ACEB0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::HalRsdFileStream::vfunc_10 (0x006F3590, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006EB6D0();
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
    ((Object*)(int)this + 16)->sub_006EB6D0();
}

}

