// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/GameMemorySegmentCollection.cpp (8 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 8 of 15 functions matched (53.33%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GameMemorySegmentCollection::vfunc_07 (0x00026950, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GameMemorySegmentCollection::vfunc_07 (0x00026950, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GameMemorySegmentCollection
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int);
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int a1, int a2);
};

void GameMemorySegmentCollection::vfunc_07(int a1, int a2)
{
    vfunc_04(a1);
}

// ============================================================================
// [VERIFIED] GameMemorySegmentCollection::vfunc_08 (0x00026960, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GameMemorySegmentCollection::vfunc_08 (0x00026960, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GameMemorySegmentCollection
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
};

void GameMemorySegmentCollection::vfunc_08()
{
    vfunc_05();
}

// ============================================================================
// [VERIFIED] GameMemorySegmentCollection::vfunc_09 (0x00026970, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GameMemorySegmentCollection::vfunc_09 (0x00026970, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GameMemorySegmentCollection
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

void GameMemorySegmentCollection::vfunc_09()
{
    vfunc_06();
}

// ============================================================================
// [VERIFIED] GameMemorySegmentCollection::vfunc_12 (0x00026980, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GameMemorySegmentCollection::vfunc_12 (0x00026980, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GameMemorySegmentCollection
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
    virtual int vfunc_12();
    char m_pad04[0x10];
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

int GameMemorySegmentCollection::vfunc_12()
{
    return m_Field18 * m_Field14;
}

// ============================================================================
// [VERIFIED] GameMemorySegmentCollection::vfunc_14 (0x00026C80, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GameMemorySegmentCollection::vfunc_14 (0x00026C80, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00250E80(int, int);

class GameMemorySegmentCollection
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
    virtual int vfunc_14();
    char m_pad04[0xC];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    char m_pad18[0x4];
    int m_Field1C; // +0x1C
};

int GameMemorySegmentCollection::vfunc_14()
{
    int t2;

    t2 = m_Field10;
    return sub_00250E80(m_Field14 << 3, m_Field1C) + t2;
}

// ============================================================================
// [VERIFIED] GameMemorySegmentCollection::vfunc_00 (0x00026D80, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GameMemorySegmentCollection::vfunc_00 (0x00026D80, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GameMemorySegmentCollection
{
public:
    virtual void vfunc_00();
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

void GameMemorySegmentCollection::vfunc_00()
{
    m_Field0C += 1;
}

// ============================================================================
// [VERIFIED] GameMemorySegmentCollection::vfunc_01 (0x00026D90, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GameMemorySegmentCollection::vfunc_01 (0x00026D90, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00026DA0();
};

class GameMemorySegmentCollection
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void GameMemorySegmentCollection::vfunc_01()
{
    ((Object*)(int)this + 4)->sub_00026DA0();
}

// ============================================================================
// [VERIFIED] GameMemorySegmentCollection::vfunc_03 (0x00026E70, 78 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GameMemorySegmentCollection::vfunc_03 (0x00026E70, 78 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039E22C[];
extern "C" char DAT_0039F08C[];
extern "C" char DAT_0039F13C[];
extern "C" char DAT_0039F144[];
extern "C" int DAT_0045894C;
extern "C" void __cdecl sub_000269F0(void);
extern "C" void __cdecl sub_002444F0(int, int);

class GameMemorySegmentCollection
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual GameMemorySegmentCollection* vfunc_03(int a1);
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    char m_pad0C[0x4];
    int m_Field10; // +0x10
};

GameMemorySegmentCollection* GameMemorySegmentCollection::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_0039F144;
    m_Field04 = (int)DAT_0039F13C;
    if (m_Field10) {
        sub_000269F0();
    }
    DAT_0045894C = m_Field08;
    m_Field04 = (int)DAT_0039F08C;
    *(int*)this = (int)DAT_0039E22C;
    if (a1 & 1) {
        sub_002444F0(DAT_0045894C, (int)this);
    }
    return this;
}

