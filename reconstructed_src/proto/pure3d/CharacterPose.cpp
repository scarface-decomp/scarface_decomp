// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, pure3d/CharacterPose.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 5 of 7 functions matched (71.43%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
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
// [VERIFIED] pure3d::CharacterPose::vfunc_09 (0x0023D9D0, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x0023D9D0
// what: 
// tool: the portal's starter code (no AI)

// pure3d::CharacterPose::vfunc_09 (Proto 0x0023D9D0, 32 bytes)
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
    virtual void vfunc_09(bool a1);
    char m_pad04[0x19];
    unsigned char m_Field1D; // +0x1D
    char m_pad1E[0xE];
    unsigned char m_Field2C; // +0x2C
};

void CharacterPose::vfunc_09(bool a1)
{
    if (a1) {
        m_Field1D |= 1;
        m_Field2C = (unsigned char)(((unsigned char)(m_Field2C & 254)) | 6);
        return;
    }
    m_Field2C &= 254;
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
// [VERIFIED] pure3d::CharacterPose::vfunc_06 (0x0023DA00, 81 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x0023DA00
// what: 
// tool: the portal's starter code (no AI)

// pure3d::CharacterPose::vfunc_06 (Proto 0x0023DA00, 81 bytes)
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
    virtual void vfunc_06(int a1);
    virtual void vfunc_07(int);
    void sub_0023D540(int);
    void sub_0023D5A0(int);
    void sub_0023D680(int);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0xD];
    unsigned char m_Field1D; // +0x1D
    char m_pad1E[0xA];
    int m_Field28; // +0x28
    unsigned char m_Field2C; // +0x2C
};

void CharacterPose::vfunc_06(int a1)
{
    if (!(m_Field2C & 5)) {
        if (a1) goto L_1F;
        if (m_Field1D & 1) goto L_1F;
        if (!m_Field28) goto L_22;
    }
L_1F:
    m_Field0C += 1;
L_22:
    if (m_Field1D & 2) {
        sub_0023D5A0(a1);
        sub_0023D540(a1);
        vfunc_07(a1);
        sub_0023D680(a1);
        m_Field1D &= 253;
    }
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

