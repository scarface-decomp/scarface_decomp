// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ExplosionTemplate.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 5 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ExplosionTemplate::vfunc_00 (0x001FBAD0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns ExplosionTemplate's static class record (ConcreteClassRep<ExplosionTemplate>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// ExplosionTemplate::vfunc_00 (0x001FBAD0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043FD90[];

class ExplosionTemplate
{
public:
    virtual void* vfunc_00();
};

void* ExplosionTemplate::vfunc_00()
{
    return DAT_0043FD90;
}

// ============================================================================
// [VERIFIED] ExplosionTemplate::vfunc_01 (0x001FBC40, 52 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: ExplosionTemplate's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as ExplosionTemplate::vfunc_01 (Proto 0x001C0750), which was matched first;
// its addresses and names were swapped for this function's.
// ExplosionTemplate::vfunc_01 (Proto 0x001FBC40, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field28
{
    void sub_00021620();
};

extern "C" char DAT_0039FE34[];
extern "C" char DAT_003CAD4C[];
extern "C" void __cdecl sub_00027600(int);

class ExplosionTemplate
{
public:
    virtual void vfunc_00();
    virtual ExplosionTemplate* vfunc_01(int a1);
    void sub_0002C720();
    char m_pad04[0x24];
    Field28 m_Field28; // +0x28
};

ExplosionTemplate* ExplosionTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003CAD4C;
    m_Field28.sub_00021620();
    *(int*)this = (int)DAT_0039FE34;
    sub_0002C720();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] ExplosionTemplate::vfunc_11 (0x001FBC80, 21 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ExplosionTemplate::vfunc_12 (Proto 0x001C0790), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x001FBC80
// what: 
// tool: the portal's starter code (no AI)

// ExplosionTemplate::vfunc_11 (Proto 0x001FBC80, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001FBB90(void);

class ExplosionTemplate
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
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
};

void ExplosionTemplate::vfunc_11()
{
    if (m_Field22) {
        sub_001FBB90();
        m_Field22 = false;
    }
}

// ============================================================================
// [VERIFIED] ExplosionTemplate::vfunc_04 (0x001FBE20, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ExplosionTemplate::vfunc_05 (Proto 0x001C0930), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x001FBE20
// what: 
// tool: the portal's starter code (no AI)

// ExplosionTemplate::vfunc_04 (Proto 0x001FBE20, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field28
{
    void sub_000216D0();
};

extern "C" void __stdcall sub_0002B700(int);

class ExplosionTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    void sub_001FBB90();
    void sub_001FBCA0();
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
    char m_pad23[0x5];
    Field28 m_Field28; // +0x28
};

void ExplosionTemplate::vfunc_04(int a1)
{
    sub_0002B700(a1);
    m_Field28.sub_000216D0();
    if (m_Field22) {
        sub_001FBB90();
        sub_001FBCA0();
    }
}

// ============================================================================
// [VERIFIED] ExplosionTemplate::vfunc_10 (0x001FBE50, 69 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x001FBE50
// what: 
// tool: the portal's starter code (no AI)

// ExplosionTemplate::vfunc_10 (0x001FBE50, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field28
{
    int sub_00021640();
};

class ExplosionTemplate
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
    void sub_001FBCA0();
    char m_pad04[0x1C];
    short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x5];
    Field28 m_Field28; // +0x28
    char m_pad29[0x33];
    int m_Field5C; // +0x5C
    char m_pad60[0x24];
    int m_Field84; // +0x84
};

void ExplosionTemplate::vfunc_10()
{
    int r_eax;

    r_eax = m_Field22;
    if ((unsigned char)r_eax) goto L_43;
    r_eax = m_Field84;
    if (r_eax) {
        if (*(unsigned char*)r_eax) goto L_1C;
    }
    r_eax = m_Field5C;
L_1C:
    if (r_eax) {
        if (*(unsigned char*)r_eax) goto L_38;
    }
    if (m_Field20 < 0) {
        r_eax = m_Field28.sub_00021640();
        if ((unsigned char)r_eax) goto L_43;
    }
L_38:
    sub_001FBCA0();
    m_Field22 = true;
L_43:
    ;
}

