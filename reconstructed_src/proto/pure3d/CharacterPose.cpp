// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/CharacterPose.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 7 functions matched (42.86%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::CharacterPose::vfunc_04 (0x0023D9B0, 17 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CharacterPose::vfunc_04 (Proto 0x0023D9B0, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class CharacterPose
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04(int a1);
    char m_pad04[0x20];
    int m_Field24; // +0x24
};

int CharacterPose::vfunc_04(int a1)
{
    return (a1 << 6) + m_Field24 + 48;
}

}

// ============================================================================
// [VERIFIED] pure3d::CharacterPose::vfunc_10 (0x0023D9F0, 9 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::CharacterPose::vfunc_10 (Proto 0x0023D9F0, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class CharacterPose
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
    char m_pad04[0x19];
    unsigned char m_Field1D; // +0x1D
    char m_pad1E[0xE];
    unsigned char m_Field2C; // +0x2C
};

void CharacterPose::vfunc_10()
{
    m_Field1D &= 254;
    m_Field2C &= 248;
}

}

// ============================================================================
// [VERIFIED] pure3d::CharacterPose::vfunc_03 (0x0023DBC0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::CharacterPose::vfunc_03 (0x0023DBC0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0023D920(void);
extern "C" void __cdecl sub_00025160(int);

namespace pure3d {

class CharacterPose
{
public:
    virtual CharacterPose* vfunc_03(int a1);
};

CharacterPose* CharacterPose::vfunc_03(int a1)
{
    sub_0023D920();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

