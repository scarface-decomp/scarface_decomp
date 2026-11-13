// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/PropAttachToObjectBehaviour.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] PropAttachToObjectBehaviour::vfunc_00 (0x0008F890, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// PropAttachToObjectBehaviour::vfunc_00 (0x0008F890, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A42A8[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00087E70(void);

class PropAttachToObjectBehaviour
{
public:
    virtual void vfunc_00();
    virtual PropAttachToObjectBehaviour* vfunc_00(int a1);
};

PropAttachToObjectBehaviour* PropAttachToObjectBehaviour::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003A42A8;
    sub_00087E70();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] PropAttachToObjectBehaviour::vfunc_03 (0x0008F8D0, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// PropAttachToObjectBehaviour::vfunc_03 (0x0008F8D0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class PropAttachToObjectBehaviour
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

int PropAttachToObjectBehaviour::vfunc_03()
{
    if (m_Field04) {
        if (!sub_0002AC90(m_Field08)) goto L_1D;
        return 1;
    }
L_1D:
    return 0;
}

// ============================================================================
// [VERIFIED] PropAttachToObjectBehaviour::vfunc_01 (0x0008FAF0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// PropAttachToObjectBehaviour::vfunc_01 (0x0008FAF0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0008F8F0(void);

class PropAttachToObjectBehaviour
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void PropAttachToObjectBehaviour::vfunc_01()
{
    sub_0008F8F0();
}

// ============================================================================
// [VERIFIED] PropAttachToObjectBehaviour::vfunc_04 (0x0008FB00, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_04 (0x0002B700), which was matched first;
// its addresses and names were swapped for this function's.
// PropAttachToObjectBehaviour::vfunc_04 (0x0008FB00, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0008F8F0(void);

class PropAttachToObjectBehaviour
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
};

void PropAttachToObjectBehaviour::vfunc_04(int a1)
{
    sub_0008F8F0();
}

