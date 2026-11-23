// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/EnemyCharacterGeneratorSpawnObject.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] EnemyCharacterGeneratorSpawnObject::vfunc_00 (0x001A6F80, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// EnemyCharacterGeneratorSpawnObject::vfunc_00 (0x001A6F80, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00417188[];

class EnemyCharacterGeneratorSpawnObject
{
public:
    virtual void* vfunc_00();
};

void* EnemyCharacterGeneratorSpawnObject::vfunc_00()
{
    return DAT_00417188;
}

// ============================================================================
// [VERIFIED] EnemyCharacterGeneratorSpawnObject::vfunc_01 (0x001A6F90, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// EnemyCharacterGeneratorSpawnObject::vfunc_01 (0x001A6F90, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A1B0C[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_001A9F10(void);

class EnemyCharacterGeneratorSpawnObject
{
public:
    virtual void vfunc_00();
    virtual EnemyCharacterGeneratorSpawnObject* vfunc_01(int a1);
};

EnemyCharacterGeneratorSpawnObject* EnemyCharacterGeneratorSpawnObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A1B0C;
    sub_001A9F10();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] EnemyCharacterGeneratorSpawnObject::vfunc_45 (0x001A81A0, 110 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// bin: proto
// va: 0x001A81A0
// what: 
// tool: the portal's starter code (no AI)

// EnemyCharacterGeneratorSpawnObject::vfunc_45 (Proto 0x001A81A0, 110 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001E7F40(int, int, int);
    int sub_001E9CD0(int, int, int, int);
};

extern "C" float DAT_003902F0;
extern "C" int DAT_00462ED0;

class EnemyCharacterGeneratorSpawnObject
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
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual int vfunc_45(int a1, int a2, int a3, int a4, int a5);
    char m_pad04[0xA4];
    int m_FieldA8; // +0xA8
    char m_padAC[0x4];
    int m_FieldB0; // +0xB0
};

int EnemyCharacterGeneratorSpawnObject::vfunc_45(int a1, int a2, int a3, int a4, int a5)
{
    int r_eax, t1;

    r_eax = m_FieldB0;
    if (r_eax > 0) {
        r_eax = 1;
        t1 = *(int*)m_FieldA8;
        if (*(int*)m_FieldA8) {
            r_eax = *(char*)(t1 + 22);
        }
        r_eax = ((Object*)DAT_00462ED0)->sub_001E9CD0(r_eax, a2, a3, a4);
        if (!a5) goto L_6B;
        *(float*)a5 = DAT_003902F0;
        return r_eax;
    }
    r_eax = a3;
    r_eax = ((Object*)DAT_00462ED0)->sub_001E7F40(a1, a2, a3);
L_6B:
    return r_eax;
}

