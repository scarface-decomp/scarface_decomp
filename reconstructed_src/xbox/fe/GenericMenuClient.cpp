// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/GenericMenuClient.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 11 functions matched (45.45%). NOT COMPLETE YET.
// The 6 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GenericMenuClient::vfunc_06 (0x001970C0, 22 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GenericMenuClient::vfunc_06 (0x001970C0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_000802E0(int);

class GenericMenuClient
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(bool a1, int a2);
};

void GenericMenuClient::vfunc_06(bool a1, int a2)
{
    int r_eax;

    r_eax = a1;
    if (!a1) {
        r_eax = a2;
        r_eax = sub_000802E0(a2);
    }
}

// ============================================================================
// [VERIFIED] GenericMenuClient::vfunc_02 (0x001982A0, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GenericMenuClient::vfunc_02 (0x001982A0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_000802E0(int);
extern "C" void __stdcall sub_00197AA0(int);

class GenericMenuClient
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(bool a1, int a2);
};

void GenericMenuClient::vfunc_02(bool a1, int a2)
{
    int r_eax;

    sub_00197AA0(1);
    r_eax = a1;
    if (!a1) {
        r_eax = a2;
        r_eax = sub_000802E0(a2);
    }
}

// ============================================================================
// [VERIFIED] GenericMenuClient::vfunc_03 (0x001982C0, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GenericMenuClient::vfunc_03 (0x001982C0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_000802E0(int);
extern "C" void __stdcall sub_00197AA0(int);

class GenericMenuClient
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(bool a1, int a2);
};

void GenericMenuClient::vfunc_03(bool a1, int a2)
{
    int r_eax;

    sub_00197AA0(0);
    r_eax = a1;
    if (!a1) {
        r_eax = a2;
        r_eax = sub_000802E0(a2);
    }
}

// ============================================================================
// [VERIFIED] GenericMenuClient::vfunc_07 (0x00198B50, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GenericMenuClient::vfunc_07 (0x00198B50, 15 bytes)
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
    char m_pad2C[0xC];
    int m_Field38; // +0x38
};

int GenericMenuClient::vfunc_07()
{
    return *(int*)(m_Field04 + ((m_Field38 + m_Field28) * 4));
}

// ============================================================================
// [VERIFIED] GenericMenuClient::vfunc_00 (0x00198B60, 63 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GenericMenuClient::vfunc_00 (0x00198B60, 63 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_00198A70();
};

extern "C" char DAT_003BBCF4[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00197D90(void);

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

    *(int*)this = (int)DAT_003BBCF4;
    sub_00197D90();
    m_Field14.sub_00198A70();
    t3 = m_Field04;
    m_Field08 = m_Field04;
    if (m_Field04) {
        sub_00027600(t3);
    }
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

