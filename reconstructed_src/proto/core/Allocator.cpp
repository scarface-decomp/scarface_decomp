// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, core/Allocator.cpp (11 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 11 of 13 functions matched (84.62%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] MemoryManager::Allocator::vfunc_04 (0x00025020, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as MemoryManager::Allocator::vfunc_04 (0x00027470), which was matched first;
// its addresses and names were swapped for this function's.
// MemoryManager::Allocator::vfunc_04 (0x00025020, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04(int);
};

namespace MemoryManager {

class Allocator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    char m_pad04[0x2C];
    Field30* m_Field30; // +0x30
    char m_pad34[0x4];
    int m_Field38; // +0x38
};

void Allocator::vfunc_04(int a1)
{
    if (m_Field30->vfunc_04(a1)) {
        m_Field38 += 1;
    }
}

}

// ============================================================================
// [VERIFIED] MemoryManager::Allocator::vfunc_06 (0x00025060, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as MemoryManager::Allocator::vfunc_06 (0x000274B0), which was matched first;
// its addresses and names were swapped for this function's.
// MemoryManager::Allocator::vfunc_06 (0x00025060, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
};

namespace MemoryManager {

class Allocator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    char m_pad04[0x2C];
    Field30* m_Field30; // +0x30
};

void Allocator::vfunc_06()
{
    m_Field30->vfunc_06();
}

}

// ============================================================================
// [VERIFIED] MemoryManager::Allocator::vfunc_07 (0x00025070, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as MemoryManager::Allocator::vfunc_07 (0x000274C0), which was matched first;
// its addresses and names were swapped for this function's.
// MemoryManager::Allocator::vfunc_07 (0x00025070, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07(int, int);
};

namespace MemoryManager {

class Allocator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int a1, int a2);
    char m_pad04[0x2C];
    Field30* m_Field30; // +0x30
    char m_pad34[0x4];
    int m_Field38; // +0x38
};

void Allocator::vfunc_07(int a1, int a2)
{
    if (m_Field30->vfunc_07(a1, a2)) {
        m_Field38 += 1;
    }
}

}

// ============================================================================
// [VERIFIED] MemoryManager::Allocator::vfunc_09 (0x000250B0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as MemoryManager::Allocator::vfunc_09 (0x00027500), which was matched first;
// its addresses and names were swapped for this function's.
// MemoryManager::Allocator::vfunc_09 (0x000250B0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
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

namespace MemoryManager {

class Allocator
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
    char m_pad04[0x2C];
    Field30* m_Field30; // +0x30
};

void Allocator::vfunc_09()
{
    m_Field30->vfunc_09();
}

}

// ============================================================================
// [VERIFIED] MemoryManager::Allocator::vfunc_10 (0x000250C0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as MemoryManager::Allocator::vfunc_10 (0x00027510), which was matched first;
// its addresses and names were swapped for this function's.
// MemoryManager::Allocator::vfunc_10 (0x000250C0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
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

namespace MemoryManager {

class Allocator
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
    char m_pad04[0x2C];
    Field30* m_Field30; // +0x30
};

void Allocator::vfunc_10()
{
    m_Field30->vfunc_10();
}

}

// ============================================================================
// [VERIFIED] MemoryManager::Allocator::vfunc_11 (0x000250D0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as MemoryManager::Allocator::vfunc_11 (0x00027520), which was matched first;
// its addresses and names were swapped for this function's.
// MemoryManager::Allocator::vfunc_11 (0x000250D0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
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
};

namespace MemoryManager {

class Allocator
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
    char m_pad04[0x2C];
    Field30* m_Field30; // +0x30
};

void Allocator::vfunc_11()
{
    m_Field30->vfunc_11();
}

}

// ============================================================================
// [VERIFIED] MemoryManager::Allocator::vfunc_12 (0x000250E0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as MemoryManager::Allocator::vfunc_12 (0x00027530), which was matched first;
// its addresses and names were swapped for this function's.
// MemoryManager::Allocator::vfunc_12 (0x000250E0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
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

namespace MemoryManager {

class Allocator
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
    char m_pad04[0x2C];
    Field30* m_Field30; // +0x30
};

void Allocator::vfunc_12()
{
    m_Field30->vfunc_12();
}

}

// ============================================================================
// [VERIFIED] MemoryManager::Allocator::vfunc_00 (0x000250F0, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as MemoryManager::Allocator::vfunc_00 (0x00027560), which was matched first;
// its addresses and names were swapped for this function's.
// MemoryManager::Allocator::vfunc_00 (0x000250F0, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    virtual void vfunc_00();
};

namespace MemoryManager {

class Allocator
{
public:
    virtual void vfunc_00();
    char m_pad04[0x2C];
    Field30* m_Field30; // +0x30
};

void Allocator::vfunc_00()
{
    m_Field30->vfunc_00();
}

}

// ============================================================================
// [VERIFIED] MemoryManager::Allocator::vfunc_01 (0x00025100, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as MemoryManager::Allocator::vfunc_01 (0x00027570), which was matched first;
// its addresses and names were swapped for this function's.
// MemoryManager::Allocator::vfunc_01 (0x00025100, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

namespace MemoryManager {

class Allocator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    char m_pad04[0x2C];
    Field30* m_Field30; // +0x30
};

void Allocator::vfunc_01()
{
    m_Field30->vfunc_01();
}

}

// ============================================================================
// [VERIFIED] MemoryManager::Allocator::vfunc_02 (0x00025110, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as MemoryManager::Allocator::vfunc_02 (0x00027580), which was matched first;
// its addresses and names were swapped for this function's.
// MemoryManager::Allocator::vfunc_02 (0x00025110, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

namespace MemoryManager {

class Allocator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    char m_pad04[0x2C];
    Field30* m_Field30; // +0x30
};

void Allocator::vfunc_02()
{
    m_Field30->vfunc_02();
}

}

// ============================================================================
// [VERIFIED] MemoryManager::Allocator::vfunc_03 (0x00025260, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::BaseObject::vfunc_00 (0x00026BB0), which was matched first;
// its addresses and names were swapped for this function's.
// MemoryManager::Allocator::vfunc_03 (0x00025260, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037D85C[];
extern "C" void __cdecl sub_00201A80(int);

namespace MemoryManager {

class Allocator
{
public:
    virtual Allocator* vfunc_03(int a1);
};

Allocator* Allocator::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_0037D85C;
    if (a1 & 1) {
        sub_00201A80((int)this);
    }
    return this;
}

}

