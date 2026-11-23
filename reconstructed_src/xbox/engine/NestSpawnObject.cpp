// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/NestSpawnObject.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] NestSpawnObject::vfunc_00 (0x001E3410, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns NestSpawnObject's static class record (ConcreteClassRep<NestSpawnObject>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// NestSpawnObject::vfunc_00 (0x001E3410, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043D890[];

class NestSpawnObject
{
public:
    virtual void* vfunc_00();
};

void* NestSpawnObject::vfunc_00()
{
    return DAT_0043D890;
}

// ============================================================================
// [VERIFIED] NestSpawnObject::vfunc_04 (0x001E3440, 31 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as NestSpawnObject::vfunc_05 (Proto 0x001AA030), which was matched first;
// its addresses and names were swapped for this function's.
// NestSpawnObject::vfunc_04 (Proto 0x001E3440, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00224A50(int);
};

extern "C" int DAT_00491EF8;

class NestSpawnObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    void sub_0020C440(int);
};

void NestSpawnObject::vfunc_04(int a1)
{
    ((Object*)DAT_00491EF8)->sub_00224A50((int)this);
    sub_0020C440(a1);
}

// ============================================================================
// [VERIFIED] NestSpawnObject::vfunc_35 (0x001E3480, 47 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x001E3480
// what: 
// tool: the portal's starter code (no AI)

// NestSpawnObject::vfunc_35 (0x001E3480, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_002240E0();
};

extern "C" int DAT_00491EF8;
extern "C" bool __cdecl sub_0021FD20(void);

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
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual int vfunc_35();
    char m_pad04[0x44];
    bool m_Field48; // +0x48
    bool m_Field49; // +0x49
};

int NestSpawnObject::vfunc_35()
{
    if (m_Field48) {
        if (!m_Field49) goto L_2C;
        if (!((Object*)DAT_00491EF8)->sub_002240E0()) goto L_2C;
        if (!sub_0021FD20()) goto L_2C;
        return 1;
    }
L_2C:
    return 0;
}

// ============================================================================
// [VERIFIED] NestSpawnObject::vfunc_01 (0x001E34C0, 50 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: NestSpawnObject's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// NestSpawnObject::vfunc_01 (0x001E34C0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00224A60(int);
};

extern "C" char DAT_003C7F7C[];
extern "C" int DAT_00491EF8;
extern "C" void __cdecl sub_00027600(int);

class NestSpawnObject
{
public:
    virtual void vfunc_00();
    virtual NestSpawnObject* vfunc_01(int a1);
    void sub_000290C0();
};

NestSpawnObject* NestSpawnObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003C7F7C;
    ((Object*)DAT_00491EF8)->sub_00224A60((int)this);
    sub_000290C0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

