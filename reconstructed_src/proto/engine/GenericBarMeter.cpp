// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/GenericBarMeter.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 8 functions matched (25.00%). NOT COMPLETE YET.
// The 6 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GenericBarMeter::vfunc_01 (0x0016B9E0, 66 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// bin: proto
// va: 0x0016B9E0
// what: 
// tool: the portal's starter code (no AI)

// GenericBarMeter::vfunc_01 (Proto 0x0016B9E0, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0040F2BC;

class GenericBarMeter
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(float a1);
    float m_Field04; // +0x04
    char m_pad08[0x18];
    float m_Field20; // +0x20
    float m_Field24; // +0x24
    bool m_Field28; // +0x28
};

void GenericBarMeter::vfunc_01(float a1)
{
    if (m_Field28) {
        m_Field04 = ((m_Field24 / DAT_0040F2BC) * m_Field20) + m_Field04;
        m_Field24 = 0.0f;
    }
    m_Field20 = a1 - m_Field04;
    m_Field28 = true;
}

// ============================================================================
// [VERIFIED] GenericBarMeter::vfunc_00 (0x0016BC70, 60 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: GenericBarMeter's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// GenericBarMeter::vfunc_00 (Proto 0x0016BC70, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039758C[];
extern "C" char DAT_003975F4[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __stdcall sub_0016BA30(int);

class GenericBarMeter
{
public:
    virtual GenericBarMeter* vfunc_00(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    char m_pad0C[0x4];
    int m_Field10; // +0x10
};

GenericBarMeter* GenericBarMeter::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003975F4;
    if (m_Field10) {
        sub_0016BA30(m_Field08);
        m_Field10 = 0;
    }
    *(int*)this = (int)DAT_0039758C;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

