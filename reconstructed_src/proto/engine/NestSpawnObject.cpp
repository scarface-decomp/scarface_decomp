// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/NestSpawnObject.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] NestSpawnObject::vfunc_00 (0x001AA000, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// NestSpawnObject::vfunc_00 (0x001AA000, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004170D8[];

class NestSpawnObject
{
public:
    virtual void* vfunc_00();
};

void* NestSpawnObject::vfunc_00()
{
    return DAT_004170D8;
}

// ============================================================================
// [VERIFIED] NestSpawnObject::vfunc_05 (0x001AA030, 31 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// NestSpawnObject::vfunc_05 (Proto 0x001AA030, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001E6E70(int);
};

extern "C" int DAT_00462ED0;

class NestSpawnObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    void sub_001C5520(int);
};

void NestSpawnObject::vfunc_05(int a1)
{
    ((Object*)DAT_00462ED0)->sub_001E6E70((int)this);
    sub_001C5520(a1);
}

// ============================================================================
// [VERIFIED] NestSpawnObject::vfunc_33 (0x001AA070, 38 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001AA070
// what: 
// tool: the portal's starter code (no AI)

// NestSpawnObject::vfunc_33 (Proto 0x001AA070, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_001E68E0();
};

extern "C" int DAT_00462ED0;

class NestSpawnObject
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
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual int vfunc_33();
    char m_pad04[0x40];
    bool m_Field44; // +0x44
    bool m_Field45; // +0x45
};

int NestSpawnObject::vfunc_33()
{
    if (m_Field44) {
        if (!m_Field45) goto L_23;
        if (!((Object*)DAT_00462ED0)->sub_001E68E0()) goto L_23;
        return 1;
    }
L_23:
    return 0;
}

// ============================================================================
// [VERIFIED] NestSpawnObject::vfunc_01 (0x001AA0A0, 50 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as NestSpawnObject::vfunc_01 (0x001E34C0), which was matched first;
// its addresses and names were swapped for this function's.
// NestSpawnObject::vfunc_01 (0x001AA0A0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001E6E80(int);
};

extern "C" char DAT_003A1FAC[];
extern "C" int DAT_00462ED0;
extern "C" void __cdecl sub_00025160(int);

class NestSpawnObject
{
public:
    virtual void vfunc_00();
    virtual NestSpawnObject* vfunc_01(int a1);
    void sub_00026AD0();
};

NestSpawnObject* NestSpawnObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A1FAC;
    ((Object*)DAT_00462ED0)->sub_001E6E80((int)this);
    sub_00026AD0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

