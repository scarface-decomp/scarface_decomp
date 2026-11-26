// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/XboxSaveDrive.cpp (18 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 18 of 21 functions matched (85.71%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_00 (0x002BF800, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_00 (0x002AAF50), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxSaveDrive::vfunc_00 (0x002BF800, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004BFE18[];
extern "C" void __cdecl sub_00283B80(int);

namespace core {

class XboxSaveDrive
{
public:
    virtual void vfunc_00();
};

void XboxSaveDrive::vfunc_00()
{
    sub_00283B80((int)DAT_004BFE18);
}

}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_01 (0x002BF810, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_00 (0x002AAF50), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxSaveDrive::vfunc_01 (0x002BF810, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004BFE18[];
extern "C" void __cdecl sub_00283B70(int);

namespace core {

class XboxSaveDrive
{
public:
    virtual void vfunc_01();
};

void XboxSaveDrive::vfunc_01()
{
    sub_00283B70((int)DAT_004BFE18);
}

}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_05 (0x002BF830, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::XboxSaveDrive::vfunc_05 (Proto 0x002834A0), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxSaveDrive::vfunc_05 (Proto 0x002BF830, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class XboxSaveDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void* vfunc_05();
    char m_pad04[0xE4];
    int m_FieldE8; // +0xE8
};

void* XboxSaveDrive::vfunc_05()
{
    return &m_FieldE8;
}

}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_12 (0x002BF840, 61 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::XboxSaveDrive::vfunc_12 (Proto 0x002834B0), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxSaveDrive::vfunc_12 (Proto 0x002BF840, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004BFE3C;
extern "C" int DAT_004BFE44;
extern "C" void __stdcall sub_00233A9F(int);

namespace core {

class XboxSaveDrive
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
    virtual int vfunc_12(int a1, int a2);
    virtual void vfunc_13(int, int);
    char m_pad04[0xE0];
    int m_FieldE4; // +0xE4
};

int XboxSaveDrive::vfunc_12(int a1, int a2)
{
    vfunc_13(a1, a2);
    if (DAT_004BFE3C == a1) {
        DAT_004BFE44 = 0;
    }
    sub_00233A9F(a1);
    m_FieldE4 -= 1;
    return 1;
}

}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_01 (0x002BF880, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::XboxSaveDrive: Always returns 8172.
// ============================================================================
// Same machine code as core::XboxSaveDrive::vfunc_01 (Proto 0x00283500), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxSaveDrive::vfunc_01 (Proto 0x002BF880, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class XboxSaveDrive
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};

int XboxSaveDrive::vfunc_01()
{
    return 8172;
}

}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_02 (0x002BF890, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::XboxSaveDrive: Always returns 4.
// ============================================================================
// Same machine code as core::XboxSaveDrive::vfunc_02 (Proto 0x002834F0), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxSaveDrive::vfunc_02 (Proto 0x002BF890, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class XboxSaveDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02(int a1);
};

int XboxSaveDrive::vfunc_02(int a1)
{
    return 4;
}

}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_06 (0x002BF8A0, 72 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// What it does: Gives the space a new save of a given size needs on the memory unit, rounded to 0x4000 with room for the directory.
// ============================================================================
// bin: xb
// va: 0x002BF8A0
// what: Gives the space a new save of a given size needs on the memory unit, rounded to 0x4000 with room for the directory.
// tool: Claude (from SPEC-016)

const unsigned int BLOCK_DATA = 0x2000 - 20;     // a block less its signature

extern "C" unsigned int __cdecl sub_00250E80(unsigned int value, unsigned int step);

inline unsigned int SizeOnDisk(unsigned int size)
{
    return size + 4 + 20 * ((size + 4 + BLOCK_DATA - 1) / BLOCK_DATA);
}

struct SaveInfo
{
    int m_Field0; // +0x0
};

namespace core
{
    class XboxSaveDrive
    {
    public:
        unsigned int vfunc_06(SaveInfo* info, unsigned int size);
    };
}

unsigned int core::XboxSaveDrive::vfunc_06(SaveInfo* info, unsigned int size)
{
    unsigned int needed = sub_00250E80(SizeOnDisk(size), 0x4000) + 0x8000;
    if (info->m_Field0 != 0)
    {
        needed += 0x4000;
    }
    return needed;
}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_14 (0x002BFCF0, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// What it does: Reads from a signed save file by handing the request to the signed-read helper, with this drive supplying the blocks.
// ============================================================================
// bin: xb
// va: 0x002BFCF0
// what: Reads from a signed save file by handing the request to the signed-read helper, with this drive supplying the blocks.
// tool: Claude (from SPEC-016)

namespace core
{
    class XboxSaveDrive;

    // The part of the object in front of the two interfaces (SPEC-016 section 9).
    class DriveFront
    {
    public:
        virtual void Front00();

        char m_pad04[0xD4];
    };

    // The signed-read interface, at +0xD8.
    class SignedRead
    {
    public:
        virtual int Read00() = 0;

        int sub_002CC160(XboxSaveDrive* drive, void* file, const char* name, unsigned int position, void* to,
                         unsigned int count, unsigned int* done, int space);
    };

    class XboxSaveDrive : public DriveFront, public SignedRead
    {
    public:
        virtual int Read00();
        int vfunc_14(void* file, const char* name, int unused, unsigned int position, void* to, unsigned int count,
                     unsigned int* done, int space);
    };
}

int core::XboxSaveDrive::vfunc_14(void* file, const char* name, int unused, unsigned int position, void* to,
                                  unsigned int count, unsigned int* done, int space)
{
    return SignedRead::sub_002CC160(this, file, name, position, to, count, done, space);
}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_15 (0x002BFD10, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::XboxSaveDrive::vfunc_15 (Proto 0x00283980), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x002BFD10
// what: 
// tool: the portal's starter code (no AI)

// core::XboxSaveDrive::vfunc_15 (Proto 0x002BFD10, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_002CC250(int, int, int);
};

namespace core {

class XboxSaveDrive
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
    virtual int vfunc_15(int a1, int a2, int a3);
};

int XboxSaveDrive::vfunc_15(int a1, int a2, int a3)
{
    a3 = a2;
    a2 = a1;
    a1 = (int)this;
    return ((Object*)(int)this + 220)->sub_002CC250(a1, a2, a3);
}

}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_00 (0x002BFD30, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_00 (0x00248810), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxSaveDrive::vfunc_00 (0x002BFD30, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 4 bytes to the start of the object and jumps to the real function at
// 0x002C00D0. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (4 bytes).

namespace core {
class ControllerSystemXBox_Base0 { public: virtual void sub_002C00D0(); };
class ControllerSystemXBox_Base1 { public: virtual void sub_002C00D0(); };

class XboxSaveDrive : public ControllerSystemXBox_Base0, public ControllerSystemXBox_Base1
{
public:
    XboxSaveDrive();
    virtual void sub_002C00D0();          // the real function; the thunk jumps here
};

XboxSaveDrive::XboxSaveDrive() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_02 (0x002BFD40, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::Drive::vfunc_02 (Proto 0x0026EEC0), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxSaveDrive::vfunc_02 (Proto 0x002BFD40, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 12 bytes to the start of the object and jumps to the real function at
// 0x002C00D0. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (12 bytes).

namespace core {
class Drive_Base0 { public: virtual void sub_002C00D0(); char m_pad04[0x8]; };
class Drive_Base1 { public: virtual void sub_002C00D0(); };

class XboxSaveDrive : public Drive_Base0, public Drive_Base1
{
public:
    XboxSaveDrive();
    virtual void sub_002C00D0();          // the real function; the thunk jumps here
};

XboxSaveDrive::XboxSaveDrive() {}                  // building one is what makes the compiler write its tables and the thunk
}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_22 (0x002BFD50, 63 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::XboxSaveDrive::vfunc_22 (Proto 0x002839C0), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxSaveDrive::vfunc_22 (Proto 0x002BFD50, 63 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_0030A4EB(int);

namespace core {

class XboxSaveDrive
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
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual int vfunc_22(int a1);
};

int XboxSaveDrive::vfunc_22(int a1)
{
    int t1;

    t1 = *(int*)((*(int*)a1 * 520) + (int)this + 784);
    if (*(int*)((*(int*)a1 * 520) + (int)this + 784) != -1) {
        sub_0030A4EB(t1);
        *(int*)((*(int*)a1 * 520) + (int)this + 784) = -1;
    }
    return 1;
}

}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_03 (0x002C00D0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: core::XboxSaveDrive's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::XboxSaveDrive::vfunc_03 (0x002C00D0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045894C;
extern "C" void __cdecl sub_002444F0(int, int);
extern "C" void __cdecl sub_002BFD90(void);

namespace core {

class XboxSaveDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual XboxSaveDrive* vfunc_03(int a1);
};

XboxSaveDrive* XboxSaveDrive::vfunc_03(int a1)
{
    sub_002BFD90();
    if (a1 & 1) {
        sub_002444F0(DAT_0045894C, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_09 (0x002C0900, 181 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// What it does: Ends a save-drive operation: records wrong or no media if the unit was swapped with files open, else clears its changed mark; true if no error.
// ============================================================================
// bin: xb
// va: 0x002C0900
// what: Ends a save-drive operation: records wrong or no media if the unit was swapped with files open, else clears its changed mark; true if no error.
// tool: Claude (from the bytes; SPEC-016 sections 1 and 9)

// The memory units' state: which are present and which have changed (SPEC-016 section 1.2).
class MemoryUnits
{
public:
    bool IsPresent(int port, int slot)
    {
        if (port < 0 || slot < 0)
        {
            return true;
        }
        return (m_Present & (unsigned char)(1 << (port + slot * 4))) != 0;
    }

    bool HasChanged(int port, int slot)
    {
        if (port < 0 || slot < 0)
        {
            return false;
        }
        return (m_Changed & (unsigned char)(1 << (port + slot * 4))) != 0;
    }

    void ClearChanged(int port, int slot)
    {
        if (port < 0 || slot < 0)
        {
            return;
        }
        m_Changed &= ~(unsigned char)(1 << (port + slot * 4));
    }

    unsigned char m_Present; // +0x0
    unsigned char m_Changed; // +0x1
};

extern "C" MemoryUnits DAT_004BDDF0;

namespace core
{
    class XboxSaveDrive
    {
    public:
        void sub_002C04C0();
        int vfunc_09();

        void GetPortAndSlot(int* port, int* slot)
        {
            if (m_Name[0] == 'U')
            {
                *port = -1;
                *slot = -1;
            }
            else
            {
                *port = m_Name[7] - '1';
                *slot = m_Name[8] - 'A';
            }
        }

        char m_pad00[0x7C];
        int m_Field7C;              // +0x7C: a copy of the error, kept in the base part of the object
        char m_pad80[0x50];
        int m_LastError;            // +0xD0
        char m_padD4[0x10];
        unsigned int m_OpenFiles;   // +0xE4
        char m_Name[0x11];          // +0xE8
        bool m_Mounted;             // +0xF9
        char m_DriveLetter;         // +0xFA
    };
}

int core::XboxSaveDrive::vfunc_09()
{
    sub_002C04C0();
    if (m_DriveLetter != 'U')
    {
        int port;
        int slot;
        GetPortAndSlot(&port, &slot);
        if (m_OpenFiles != 0)
        {
            if (DAT_004BDDF0.HasChanged(port, slot))
            {
                if (DAT_004BDDF0.IsPresent(port, slot))
                {
                    m_Field7C = 3;
                    m_LastError = 3;
                }
                else
                {
                    m_Field7C = 4;
                    m_LastError = 4;
                }
                return 0;
            }
        }
        else
        {
            DAT_004BDDF0.ClearChanged(port, slot);
        }
    }
    return m_LastError == 0;
}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_13 (0x002C0EC0, 182 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// What it does: Commits a save file: writes the cached block back and, for a file whose first block still needs it, stores the file's size in block 0.
// ============================================================================
// bin: xb
// va: 0x002C0EC0
// what: Commits a save file: writes the cached block back and, for a file whose first block still needs it, stores the file's size in block 0.
// tool: Claude (from SPEC-016)

extern "C" char* DAT_004BFE38;          // the transfer buffer: one block, 0x2000 bytes
extern "C" void* DAT_004BFE3C;          // the file whose block is in the buffer
extern "C" int DAT_004BFE44;            // 0 = nothing valid, 1 = valid and unchanged, 2 = changed and not yet written

extern "C" unsigned int __stdcall sub_00233A64(void* file, unsigned int* high);     // GetFileSize
extern "C" unsigned int __stdcall sub_00234B47();                                   // GetLastError

namespace core
{
    class XboxSaveDrive
    {
    public:
        int sub_002BFE10(unsigned int code);
        bool sub_002BFF10();
        bool sub_002C0030(unsigned int code);
        bool sub_002C0100();
        bool sub_002C0760(void* file, unsigned int block);
        int vfunc_13(void* file, const char* name);

        char m_pad00[0xD0];
        int m_LastError;            // +0xD0
        char m_padD4[0x28];
        void* m_NeedSize[4];        // +0xFC: files whose first block still needs its size written
    };
}

bool core::XboxSaveDrive::sub_002C0030(unsigned int code)
{
    m_LastError = sub_002BFE10(code);
    return m_LastError == 0;
}

int core::XboxSaveDrive::vfunc_13(void* file, const char* name)
{
    if (!sub_002BFF10())
    {
        return 0;
    }
    if (!sub_002C0100())
    {
        return 0;
    }
    bool found = false;
    unsigned int i;
    for (i = 0; i < 4; i++)
    {
        if (DAT_004BFE3C == m_NeedSize[i])
        {
            found = true;
            break;
        }
    }
    if (found)
    {
        if (!sub_002C0760(file, 0))
        {
            return 0;
        }
        unsigned int size = sub_00233A64(file, 0);
        if (size == 0xFFFFFFFF)
        {
            sub_002C0030(sub_00234B47());
            return 0;
        }
        *(unsigned int*)DAT_004BFE38 = size;
        DAT_004BFE44 = 2;
        if (!sub_002C0100())
        {
            return 0;
        }
        m_NeedSize[i] = (void*)0xFFFFFFFF;
    }
    m_LastError = 0;
    return 1;
}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_00 (0x002C0F80, 152 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// What it does: Reads part of one signed block of a save file: mounts the unit, loads the block into the shared buffer and copies the bytes out.
// ============================================================================
// bin: xb
// va: 0x002C0F80
// what: Reads part of one signed block of a save file: mounts the unit, loads the block into the shared buffer and copies the bytes out.
// tool: Claude (from SPEC-016)

extern "C" void* __cdecl memcpy(void* to, const void* from, unsigned int count);
#pragma intrinsic(memcpy)

extern "C" char* DAT_004BFE38;          // the transfer buffer: one block, 0x2000 bytes

extern "C" unsigned int __stdcall sub_00233A64(void* file, unsigned int* high);     // GetFileSize
extern "C" unsigned int __stdcall sub_00234B47();                                   // GetLastError

namespace core
{
    // The part of the object in front of the two interfaces (SPEC-016 section 9).
    class DriveFront
    {
    public:
        virtual void Front00();

        char m_pad04[0xCC];
        int m_LastError;            // +0xD0
        int m_FieldD4;              // +0xD4
    };

    // The signed-read interface, at +0xD8.
    class SignedRead
    {
    public:
        virtual int vfunc_00(void* file, const char* name, unsigned int block, unsigned int position,
                             unsigned int count, void* to, int space) = 0;
    };

    // The signed-write interface, at +0xDC.
    class SignedWrite
    {
    public:
        virtual int Write00() = 0;
    };

    class XboxSaveDrive : public DriveFront, public SignedRead, public SignedWrite
    {
    public:
        int sub_002BFE10(unsigned int code);
        bool sub_002BFF10();
        bool sub_002C0030(unsigned int code);
        bool sub_002C0760(void* file, unsigned int block);

        virtual int vfunc_00(void* file, const char* name, unsigned int block, unsigned int position,
                             unsigned int count, void* to, int space);
    };
}

bool core::XboxSaveDrive::sub_002C0030(unsigned int code)
{
    m_LastError = sub_002BFE10(code);
    return m_LastError == 0;
}

int core::XboxSaveDrive::vfunc_00(void* file, const char* name, unsigned int block, unsigned int position,
                                  unsigned int count, void* to, int space)
{
    if (!sub_002BFF10())
    {
        return 0;
    }

    unsigned int size = sub_00233A64(file, 0);
    if (size == 0xFFFFFFFF)
    {
        sub_002C0030(sub_00234B47());
        return 0;
    }

    if (block * 0x2000 < size)
    {
        if (!sub_002C0760(file, block))
        {
            return 0;
        }
        memcpy(to, DAT_004BFE38 + position, count);
    }
    m_LastError = 0;
    return 1;
}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_00 (0x002C1020, 190 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// What it does: Writes part of one signed block of a save file through the shared buffer, marks the block changed and reports the file's size less its signatures.
// ============================================================================
// bin: xb
// va: 0x002C1020
// what: Writes part of one signed block of a save file through the shared buffer, marks the block changed and reports the file's size less its signatures.
// tool: Claude (from SPEC-016)

extern "C" void* __cdecl memcpy(void* to, const void* from, unsigned int count);
#pragma intrinsic(memcpy)

extern "C" char* DAT_004BFE38;          // the transfer buffer: one block, 0x2000 bytes
extern "C" int DAT_004BFE44;            // 0 = nothing valid, 1 = valid and unchanged, 2 = changed and not yet written

extern "C" unsigned int __stdcall sub_00233A64(void* file, unsigned int* high);     // GetFileSize
extern "C" unsigned int __stdcall sub_00234B47();                                   // GetLastError

namespace core
{
    // The part of the object in front of the two interfaces (SPEC-016 section 9).
    class DriveFront
    {
    public:
        virtual void Front00();

        char m_pad04[0xCC];
        int m_LastError;            // +0xD0
        int m_FieldD4;              // +0xD4
    };

    // The signed-read interface, at +0xD8.
    class SignedRead
    {
    public:
        virtual int Read00() = 0;
    };

    // The signed-write interface, at +0xDC.
    class SignedWrite
    {
    public:
        virtual int vfunc_00(void* file, const char* name, unsigned int block, unsigned int position,
                             unsigned int count, const void* from, unsigned int* dataSize, int space) = 0;
    };

    class XboxSaveDrive : public DriveFront, public SignedRead, public SignedWrite
    {
    public:
        int sub_002BFE10(unsigned int code);
        bool sub_002BFF10();
        bool sub_002C0030(unsigned int code);
        bool sub_002C0760(void* file, unsigned int block);

        virtual int vfunc_00(void* file, const char* name, unsigned int block, unsigned int position,
                             unsigned int count, const void* from, unsigned int* dataSize, int space);
    };
}

bool core::XboxSaveDrive::sub_002C0030(unsigned int code)
{
    m_LastError = sub_002BFE10(code);
    return m_LastError == 0;
}

int core::XboxSaveDrive::vfunc_00(void* file, const char* name, unsigned int block, unsigned int position,
                                  unsigned int count, const void* from, unsigned int* dataSize, int space)
{
    if (!sub_002BFF10())
    {
        return 0;
    }

    unsigned int size = sub_00233A64(file, 0);
    if (size == 0xFFFFFFFF)
    {
        sub_002C0030(sub_00234B47());
        return 0;
    }

    if (!sub_002C0760(file, block))
    {
        return 0;
    }
    DAT_004BFE44 = 0;
    memcpy(DAT_004BFE38 + position, from, count);
    DAT_004BFE44 = 2;

    // one 20-byte signature for every 0x2000 bytes of file
    *dataSize = size - 20 * ((size + 0x1FFF) / 0x2000);
    m_LastError = 0;
    return 1;
}

// ============================================================================
// [VERIFIED] core::XboxSaveDrive::vfunc_19 (0x002C10E0, 145 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// What it does: Deletes a save by name from the memory unit: mounts the unit, turns the name into 16-bit text and asks the system to delete it.
// ============================================================================
// bin: xb
// va: 0x002C10E0
// what: Deletes a save by name from the memory unit: mounts the unit, turns the name into 16-bit text and asks the system to delete it.
// tool: Claude (from SPEC-016)

extern "C" bool __cdecl sub_002A93A0(const char* source, int* consumed, unsigned int* character, int c);
extern "C" int __cdecl sub_002A9610(unsigned int character, unsigned short* destination, int room, int a, int* produced, int c);
extern "C" unsigned int __stdcall sub_0030A2CA(const char* drive, const unsigned short* name);     // XDeleteSaveGame

// 8-bit text to 16-bit text, one character at a time (SPEC-016 section 10.2). File-local: the compiler
// passes its first two arguments in ECX and EAX.
static int sub_002BFAA0(unsigned short* destination, const char* source, int a, int capacity, int c)
{
    if ((const void*)source == (const void*)destination)
    {
        return -5;
    }
    const char* in = source;
    unsigned short* out = destination;
    int written = 0;
    while (*in != 0)
    {
        unsigned int character;
        int consumed;
        int produced;
        if (!sub_002A93A0(in, &consumed, &character, c))
        {
            return -2;
        }
        int result = sub_002A9610(character, out, capacity - written - 2, a, &produced, c);
        if (result != 0)
        {
            if (result == -1)
            {
                *out = 0;
                return -1;
            }
            return result;
        }
        in += consumed;
        out = (unsigned short*)((char*)out + produced);
        written += produced;
    }
    *out = 0;
    return 0;
}

namespace core
{
    class XboxSaveDrive
    {
    public:
        int sub_002BFE10(unsigned int code);
        bool sub_002BFF10();
        int vfunc_19(const char* name);

        char m_pad00[0xD0];
        int m_LastError;            // +0xD0
        char m_padD4[0x26];
        char m_DriveLetter;         // +0xFA
    };
}

int core::XboxSaveDrive::vfunc_19(const char* name)
{
    if (!sub_002BFF10())
    {
        return 0;
    }

    char drive[4];
    unsigned short wideName[0x102];
    drive[0] = m_DriveLetter;
    drive[1] = ':';
    drive[2] = '\\';
    drive[3] = 0;
    if (name != 0)
    {
        sub_002BFAA0(wideName, name, 0, 0x202, 0);
    }

    unsigned int code = sub_0030A2CA(drive, wideName);
    if (code != 0)
    {
        m_LastError = sub_002BFE10(code);
        return 0;
    }
    m_LastError = 0;
    return 1;
}

