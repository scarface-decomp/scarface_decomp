// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/GameMemorySegmentCollection.cpp (9 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 9 of 13 functions matched (69.23%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GameMemorySegmentCollection::vfunc_07 (0x000245C0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GameMemorySegmentCollection::vfunc_07 (0x00026950), which was matched first;
// its addresses and names were swapped for this function's.
// GameMemorySegmentCollection::vfunc_07 (0x000245C0, 13 bytes)
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
// [VERIFIED] GameMemorySegmentCollection::vfunc_08 (0x000245D0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GameMemorySegmentCollection::vfunc_08 (0x00026960), which was matched first;
// its addresses and names were swapped for this function's.
// GameMemorySegmentCollection::vfunc_08 (0x000245D0, 5 bytes)
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
// [VERIFIED] GameMemorySegmentCollection::vfunc_09 (0x000245E0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GameMemorySegmentCollection::vfunc_09 (0x00026970), which was matched first;
// its addresses and names were swapped for this function's.
// GameMemorySegmentCollection::vfunc_09 (0x000245E0, 5 bytes)
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
// [VERIFIED] GameMemorySegmentCollection::vfunc_12 (0x000245F0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GameMemorySegmentCollection::vfunc_12 (0x00026980), which was matched first;
// its addresses and names were swapped for this function's.
// GameMemorySegmentCollection::vfunc_12 (0x000245F0, 8 bytes)
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
// [VERIFIED] GameMemorySegmentCollection::vfunc_10 (0x00024810, 171 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GameMemorySegmentCollection::vfunc_10 (0x00026BD0), which was matched first;
// its addresses and names were swapped for this function's.
// One fixed-size segment slot: free when both words are zero.
struct Segment
{
    int m_00;
    int m_04;
};

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
    virtual bool vfunc_10(unsigned int* freeBytes, unsigned int* largestUsed, unsigned int* usedCount,
                          unsigned int* usedBytes);

    char m_pad04[0xC];
    Segment* m_segments;       // +0x10
    unsigned int m_count;      // +0x14
    unsigned int m_segmentSize; // +0x18
};

// Memory statistics: counts the free and used segments and reports them in bytes. Every
// output is optional. With no segments it reports zeros and returns false.
bool GameMemorySegmentCollection::vfunc_10(unsigned int* freeBytes, unsigned int* largestUsed,
                                           unsigned int* usedCount, unsigned int* usedBytes)
{
    if (!m_segments) {
        if (freeBytes)
            *freeBytes = 0;
        if (largestUsed)
            *largestUsed = 0;
        if (usedCount)
            *usedCount = 0;
        if (usedBytes)
            *usedBytes = 0;
        return false;
    }
    unsigned int free = 0;
    unsigned int used = 0;
    Segment* segment = m_segments;
    for (unsigned int i = 0; i < m_count; i++, segment++) {
        if (segment->m_00 == 0 && segment->m_04 == 0)
            free += m_segmentSize;
        else
            used++;
    }
    if (freeBytes)
        *freeBytes = free;
    if (largestUsed)
        *largestUsed = used > 0 ? m_segmentSize : 0;
    if (usedCount)
        *usedCount = used;
    if (usedBytes)
        *usedBytes = m_segmentSize * used;
    return true;
}

// ============================================================================
// [VERIFIED] GameMemorySegmentCollection::vfunc_03 (0x00024A60, 78 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GameMemorySegmentCollection::vfunc_03 (0x00026E70), which was matched first;
// its addresses and names were swapped for this function's.
// GameMemorySegmentCollection::vfunc_03 (0x00024A60, 78 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037D85C[];
extern "C" char DAT_0037E6E4[];
extern "C" char DAT_0037E794[];
extern "C" char DAT_0037E79C[];
extern "C" int DAT_00429338;
extern "C" void __cdecl sub_00024650(void);
extern "C" void __cdecl sub_00201990(int, int);

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
    *(int*)this = (int)DAT_0037E79C;
    m_Field04 = (int)DAT_0037E794;
    if (m_Field10) {
        sub_00024650();
    }
    DAT_00429338 = m_Field08;
    m_Field04 = (int)DAT_0037E6E4;
    *(int*)this = (int)DAT_0037D85C;
    if (a1 & 1) {
        sub_00201990(DAT_00429338, (int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] GameMemorySegmentCollection::vfunc_02 (0x00084DA0, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GameMemorySegmentCollection::vfunc_02 (PC 0x006E9820), which was matched first;
// its addresses and names were swapped for this function's.
// GameMemorySegmentCollection::vfunc_02 (PC 0x00084DA0, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GameMemorySegmentCollection
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

int GameMemorySegmentCollection::vfunc_02()
{
    return m_Field0C;
}

// ============================================================================
// [VERIFIED] GameMemorySegmentCollection::vfunc_00 (0x002057D0, 4 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GameMemorySegmentCollection::vfunc_00 (0x00026D80), which was matched first;
// its addresses and names were swapped for this function's.
// GameMemorySegmentCollection::vfunc_00 (0x002057D0, 4 bytes)
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
// [VERIFIED] GameMemorySegmentCollection::vfunc_01 (0x002B02C0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GameMemorySegmentCollection::vfunc_01 (0x00026D90), which was matched first;
// its addresses and names were swapped for this function's.
// GameMemorySegmentCollection::vfunc_01 (0x002B02C0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00024990();
};

class GameMemorySegmentCollection
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void GameMemorySegmentCollection::vfunc_01()
{
    ((Object*)(int)this + 4)->sub_00024990();
}

