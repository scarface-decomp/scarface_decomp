// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/Pure3dObject.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 8 functions matched (62.50%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::frontend::Pure3dObject::vfunc_15 (0x00207B00, 20 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::frontend::Pure3dObject::vfunc_15 (Proto 0x00207B00, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field48
{
    void sub_002003C0();
};

namespace pure3d { namespace frontend {

class Pure3dObject
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
    char m_pad04[0x44];
    Field48 m_Field48; // +0x48
    char m_pad49[0x4B];
    unsigned char m_Field94; // +0x94
};

void Pure3dObject::vfunc_15()
{
    m_Field48.sub_002003C0();
    m_Field94 &= 247;
}

} }

// ============================================================================
// [VERIFIED] pure3d::frontend::Pure3dObject::vfunc_12 (0x00207C70, 5 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::frontend::Pure3dObject::vfunc_12 (Proto 0x00207C70, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d { namespace frontend {

class Pure3dObject
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
};

void Pure3dObject::vfunc_12()
{
    vfunc_11();
}

} }

// ============================================================================
// [VERIFIED] pure3d::frontend::Pure3dObject::vfunc_11 (0x00207C80, 81 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::frontend::Pure3dObject::vfunc_11 (Proto 0x00207C80, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
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
    virtual void vfunc_10(int, int);
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17(int);
    virtual void vfunc_18(int);
    virtual void vfunc_19(int, int);
};

extern "C" int DAT_00464C9C;

namespace pure3d { namespace frontend {

class Pure3dObject
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
    char m_pad04[0x40];
    int m_Field44; // +0x44
    char m_pad48[0x4C];
    int m_Field94; // +0x94
};

void Pure3dObject::vfunc_11()
{
    int r_edi;

    r_edi = m_Field44;
    if (r_edi) {
        ((Object*)*(int*)DAT_00464C9C)->vfunc_17(0);
        if (m_Field94 & 8) {
            ((Object*)*(int*)DAT_00464C9C)->vfunc_19(0, (int)this + 72);
        }
        ((Object*)r_edi)->vfunc_10(0, 0);
        ((Object*)*(int*)DAT_00464C9C)->vfunc_18(0);
    }
}

} }

// ============================================================================
// [VERIFIED] pure3d::frontend::Pure3dObject::vfunc_14 (0x00207CE0, 10 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::frontend::Pure3dObject::vfunc_14 (Proto 0x00207CE0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00205F30(int);

namespace pure3d { namespace frontend {

class Pure3dObject
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
    char m_pad04[0x40];
    int m_Field44; // +0x44
};

void Pure3dObject::vfunc_14()
{
    sub_00205F30(m_Field44);
}

} }

// ============================================================================
// [VERIFIED] pure3d::frontend::Pure3dObject::vfunc_03 (0x00207F60, 43 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::frontend::Pure3dObject::vfunc_03 (Proto 0x00207F60, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AE32C[];
extern "C" void __cdecl sub_001FCF60(int);
extern "C" void __cdecl sub_00207E60(void);

namespace pure3d { namespace frontend {

class Pure3dObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Pure3dObject* vfunc_03(int a1);
    void sub_00205D60();
};

Pure3dObject* Pure3dObject::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_003AE32C;
    sub_00207E60();
    sub_00205D60();
    if (a1 & 1) {
        sub_001FCF60((int)this);
    }
    return this;
}

} }

