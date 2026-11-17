// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ScriptReader.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 11 functions matched (36.36%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] fight::ScriptReader::vfunc_04 (0x0023CA20, 35 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::ScriptReader::vfunc_04 (Proto 0x001FA480), which was matched first;
// its addresses and names were swapped for this function's.
// fight::ScriptReader::vfunc_04 (Proto 0x0023CA20, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0023C8E0(void);

namespace fight {

class ScriptReader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual bool vfunc_04();
    char m_pad04[0xC];
    bool m_Field10; // +0x10
    char m_pad11[0x107];
    int m_Field118; // +0x118
};

bool ScriptReader::vfunc_04()
{
    sub_0023C8E0();
    if (m_Field10) {
        return false;
    }
    return m_Field118 == 2;
}

}

// ============================================================================
// [VERIFIED] fight::ScriptReader::vfunc_05 (0x0023CA50, 28 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::ScriptReader::vfunc_05 (Proto 0x001FA4B0), which was matched first;
// its addresses and names were swapped for this function's.
// fight::ScriptReader::vfunc_05 (Proto 0x0023CA50, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D520[];

namespace fight {

class ScriptReader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
    char m_pad04[0xC];
    bool m_Field10; // +0x10
    char m_pad11[0x107];
    int m_Field118; // +0x118
    int m_Field11C; // +0x11C
};

int ScriptReader::vfunc_05()
{
    int r_eax;

    r_eax = m_Field10;
    if (!((unsigned char)r_eax)) {
        r_eax = (int)(&m_Field11C);
        if (m_Field118 == 2) goto L_1B;
    }
    r_eax = (int)DAT_0039D520;
L_1B:
    return r_eax;
}

}

// ============================================================================
// [VERIFIED] fight::ScriptReader::vfunc_09 (0x0023CEA0, 18 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::ScriptReader::vfunc_09 (Proto 0x001FA8F0), which was matched first;
// its addresses and names were swapped for this function's.
// fight::ScriptReader::vfunc_09 (Proto 0x0023CEA0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace fight {

class ScriptReader
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
    char m_pad04[0x218];
    int m_Field21C; // +0x21C
    char m_pad220[0x100];
    bool m_Field320; // +0x320
};

void ScriptReader::vfunc_09()
{
    m_Field21C += 1;
    m_Field320 = false;
    vfunc_08();
}

}

// ============================================================================
// [VERIFIED] fight::ScriptReader::vfunc_03 (0x0023D9B0, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// fight::ScriptReader::vfunc_03 (0x0023D9B0, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_0039E22C[];
extern "C" char DAT_003D3EC4[];
extern "C" void __cdecl sub_00027600(int);

namespace fight {

class ScriptReader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ScriptReader* vfunc_03(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

ScriptReader* ScriptReader::vfunc_03(int a1)
{
    int t1;

    t1 = m_Field08;
    *(int*)this = (int)DAT_003D3EC4;
    ((Object*)t1)->vfunc_01();
    *(int*)this = (int)DAT_0039E22C;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

}

