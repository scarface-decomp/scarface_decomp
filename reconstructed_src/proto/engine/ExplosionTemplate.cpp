// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/ExplosionTemplate.cpp (5 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 5 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ExplosionTemplate::vfunc_00 (0x001C05E0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// ExplosionTemplate::vfunc_00 (0x001C05E0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00419508[];

class ExplosionTemplate
{
public:
    virtual void* vfunc_00();
};

void* ExplosionTemplate::vfunc_00()
{
    return DAT_00419508;
}

// ============================================================================
// [VERIFIED] ExplosionTemplate::vfunc_01 (0x001C0750, 52 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: ExplosionTemplate's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// ExplosionTemplate::vfunc_01 (Proto 0x001C0750, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field28
{
    void sub_0001F430();
};

extern "C" char DAT_0037F29C[];
extern "C" char DAT_003A494C[];
extern "C" void __cdecl sub_00025160(int);

class ExplosionTemplate
{
public:
    virtual void vfunc_00();
    virtual ExplosionTemplate* vfunc_01(int a1);
    void sub_00029C00();
    char m_pad04[0x24];
    Field28 m_Field28; // +0x28
};

ExplosionTemplate* ExplosionTemplate::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A494C;
    m_Field28.sub_0001F430();
    *(int*)this = (int)DAT_0037F29C;
    sub_00029C00();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] ExplosionTemplate::vfunc_12 (0x001C0790, 21 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001C0790
// what: 
// tool: the portal's starter code (no AI)

// ExplosionTemplate::vfunc_12 (Proto 0x001C0790, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001C06A0(void);

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
    virtual void vfunc_12();
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
};

void ExplosionTemplate::vfunc_12()
{
    if (m_Field22) {
        sub_001C06A0();
        m_Field22 = false;
    }
}

// ============================================================================
// [VERIFIED] ExplosionTemplate::vfunc_05 (0x001C0930, 46 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001C0930
// what: 
// tool: the portal's starter code (no AI)

// ExplosionTemplate::vfunc_05 (Proto 0x001C0930, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field28
{
    void sub_0001F4E0();
};

extern "C" void __stdcall sub_00028C40(int);

class ExplosionTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    void sub_001C06A0();
    void sub_001C07B0();
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
    char m_pad23[0x5];
    Field28 m_Field28; // +0x28
};

void ExplosionTemplate::vfunc_05(int a1)
{
    sub_00028C40(a1);
    m_Field28.sub_0001F4E0();
    if (m_Field22) {
        sub_001C06A0();
        sub_001C07B0();
    }
}

// ============================================================================
// [VERIFIED] ExplosionTemplate::vfunc_11 (0x001C0960, 69 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001C0960
// what: 
// tool: the portal's starter code (no AI)

// ExplosionTemplate::vfunc_11 (Proto 0x001C0960, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field28
{
    int sub_0001F450();
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
    virtual void vfunc_11();
    void sub_001C07B0();
    char m_pad04[0x1C];
    short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x5];
    Field28 m_Field28; // +0x28
    char m_pad29[0x33];
    int m_Field5C; // +0x5C
    char m_pad60[0x28];
    int m_Field88; // +0x88
};

void ExplosionTemplate::vfunc_11()
{
    int r_eax;

    r_eax = m_Field22;
    if ((unsigned char)r_eax) goto L_43;
    r_eax = m_Field88;
    if (r_eax) {
        if (*(unsigned char*)r_eax) goto L_1C;
    }
    r_eax = m_Field5C;
L_1C:
    if (r_eax) {
        if (*(unsigned char*)r_eax) goto L_38;
    }
    if (m_Field20 < 0) {
        r_eax = m_Field28.sub_0001F450();
        if ((unsigned char)r_eax) goto L_43;
    }
L_38:
    sub_001C07B0();
    m_Field22 = true;
L_43:
    ;
}

