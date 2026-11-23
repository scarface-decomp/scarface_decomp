// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/GenericP3DMeter.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 8 functions matched (50.00%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GenericP3DMeter::vfunc_08 (0x0016B5B0, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GenericP3DMeter::vfunc_08 (Proto 0x0016B5B0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
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
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
};

class GenericP3DMeter
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
    char m_pad04[0xC];
    Field10* m_Field10; // +0x10
};

void GenericP3DMeter::vfunc_08()
{
    m_Field10->vfunc_18();
}

// ============================================================================
// [VERIFIED] GenericP3DMeter::vfunc_11 (0x0016B5C0, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GenericP3DMeter::vfunc_11 (Proto 0x0016B5C0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_000217A0();
};

class GenericP3DMeter
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
    char m_pad04[0xC];
    Field10* m_Field10; // +0x10
};

void GenericP3DMeter::vfunc_11()
{
    m_Field10->sub_000217A0();
}

// ============================================================================
// [VERIFIED] GenericP3DMeter::vfunc_00 (0x0016B7E0, 39 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: GenericP3DMeter's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// GenericP3DMeter::vfunc_00 (Proto 0x0016B7E0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039758C[];
extern "C" void __cdecl sub_00025160(int);

class GenericP3DMeter
{
public:
    virtual GenericP3DMeter* vfunc_00(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

GenericP3DMeter* GenericP3DMeter::vfunc_00(int a1)
{
    m_Field0C = 0;
    m_Field10 = 0;
    *(int*)this = (int)DAT_0039758C;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] GenericP3DMeter::vfunc_01 (0x0016B810, 66 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// bin: proto
// va: 0x0016B810
// what: 
// tool: the portal's starter code (no AI)

// GenericP3DMeter::vfunc_01 (Proto 0x0016B810, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0040F2BC;

class GenericP3DMeter
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(float a1);
    float m_Field04; // +0x04
    char m_pad08[0x10];
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
    bool m_Field20; // +0x20
};

void GenericP3DMeter::vfunc_01(float a1)
{
    if (m_Field20) {
        m_Field04 = ((m_Field1C / DAT_0040F2BC) * m_Field18) + m_Field04;
        m_Field1C = 0.0f;
    }
    m_Field18 = a1 - m_Field04;
    m_Field20 = true;
}

