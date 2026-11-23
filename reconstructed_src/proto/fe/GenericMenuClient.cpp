// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, fe/GenericMenuClient.cpp (8 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 8 of 11 functions matched (72.73%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GenericMenuClient::vfunc_06 (0x0016FA90, 16 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x0016FA90
// what: 
// tool: the portal's starter code (no AI)

// GenericMenuClient::vfunc_06 (Proto 0x0016FA90, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GenericMenuClient
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(bool a1);
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
};

void GenericMenuClient::vfunc_06(bool a1)
{
    if (!a1) {
        vfunc_10();
    }
}

// ============================================================================
// [VERIFIED] GenericMenuClient::vfunc_09 (0x0016FAA0, 12 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GenericMenuClient::vfunc_09 (Proto 0x0016FAA0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00396D8C[];
extern "C" void __cdecl sub_00074210(int);

class GenericMenuClient
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
};

void GenericMenuClient::vfunc_09()
{
    sub_00074210((int)DAT_00396D8C);
}

// ============================================================================
// [VERIFIED] GenericMenuClient::vfunc_10 (0x0016FAB0, 12 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GenericMenuClient::vfunc_10 (Proto 0x0016FAB0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00398610[];
extern "C" void __cdecl sub_00074210(int);

class GenericMenuClient
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

void GenericMenuClient::vfunc_10()
{
    sub_00074210((int)DAT_00398610);
}

// ============================================================================
// [VERIFIED] GenericMenuClient::vfunc_08 (0x0016FC70, 13 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GenericMenuClient::vfunc_08 (Proto 0x0016FC70, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GenericMenuClient
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
    virtual int vfunc_08(int a1);
    int m_Field04; // +0x04
};

int GenericMenuClient::vfunc_08(int a1)
{
    return *(int*)(m_Field04 + (a1 * 4));
}

// ============================================================================
// [VERIFIED] GenericMenuClient::vfunc_02 (0x001707C0, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001707C0
// what: 
// tool: the portal's starter code (no AI)

// GenericMenuClient::vfunc_02 (Proto 0x001707C0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00170100(int);

class GenericMenuClient
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(bool a1);
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
};

void GenericMenuClient::vfunc_02(bool a1)
{
    sub_00170100(1);
    if (!a1) {
        vfunc_09();
    }
}

// ============================================================================
// [VERIFIED] GenericMenuClient::vfunc_03 (0x001707E0, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001707E0
// what: 
// tool: the portal's starter code (no AI)

// GenericMenuClient::vfunc_03 (Proto 0x001707E0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00170100(int);

class GenericMenuClient
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(bool a1);
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
};

void GenericMenuClient::vfunc_03(bool a1)
{
    sub_00170100(0);
    if (!a1) {
        vfunc_09();
    }
}

// ============================================================================
// [VERIFIED] GenericMenuClient::vfunc_07 (0x00170DA0, 15 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GenericMenuClient::vfunc_07 (Proto 0x00170DA0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GenericMenuClient
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07();
    int m_Field04; // +0x04
    char m_pad08[0x20];
    int m_Field28; // +0x28
    char m_pad2C[0x8];
    int m_Field34; // +0x34
};

int GenericMenuClient::vfunc_07()
{
    return *(int*)(m_Field04 + ((m_Field34 + m_Field28) * 4));
}

// ============================================================================
// [VERIFIED] GenericMenuClient::vfunc_00 (0x00170DB0, 65 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GenericMenuClient::vfunc_00 (Proto 0x00170DB0, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_00170CF0();
};

extern "C" char DAT_00398760[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00170830(void);
extern "C" void __cdecl sub_00201990(int, int);

class GenericMenuClient
{
public:
    virtual GenericMenuClient* vfunc_00(int a1);
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    char m_pad0C[0x8];
    Field14 m_Field14; // +0x14
};

GenericMenuClient* GenericMenuClient::vfunc_00(int a1)
{
    int t3;

    *(int*)this = (int)DAT_00398760;
    sub_00170830();
    m_Field14.sub_00170CF0();
    t3 = m_Field04;
    m_Field08 = m_Field04;
    if (m_Field04) {
        sub_00201990(7, t3);
    }
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

