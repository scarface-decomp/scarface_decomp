// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/ScatteredEnemyCharacterGeneratorSpawnObject.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 6 functions matched (66.67%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ScatteredEnemyCharacterGeneratorSpawnObject::vfunc_00 (0x001E5300, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// ScatteredEnemyCharacterGeneratorSpawnObject::vfunc_00 (0x001E5300, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043DA74[];

class ScatteredEnemyCharacterGeneratorSpawnObject
{
public:
    virtual void* vfunc_00();
};

void* ScatteredEnemyCharacterGeneratorSpawnObject::vfunc_00()
{
    return DAT_0043DA74;
}

// ============================================================================
// [VERIFIED] ScatteredEnemyCharacterGeneratorSpawnObject::vfunc_39 (0x001E5310, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ScatteredEnemyCharacterGeneratorSpawnObject::vfunc_39 (0x001E5310, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class ScatteredEnemyCharacterGeneratorSpawnObject
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
    virtual float vfunc_39(int a1, int a2);
    char m_pad04[0xA0];
    float m_FieldA4; // +0xA4
};

float ScatteredEnemyCharacterGeneratorSpawnObject::vfunc_39(int a1, int a2)
{
    return m_FieldA4;
}

// ============================================================================
// [VERIFIED] ScatteredEnemyCharacterGeneratorSpawnObject::vfunc_37 (0x001E5420, 66 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// ScatteredEnemyCharacterGeneratorSpawnObject::vfunc_37 (0x001E5420, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001DE370(int);
};

class ScatteredEnemyCharacterGeneratorSpawnObject
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
    char m_pad04[0x74];
    int m_Field78; // +0x78
    char m_pad7C[0x30];
    int m_FieldAC; // +0xAC
    char m_padB0[0x1A];
    bool m_FieldCA; // +0xCA
};

void ScatteredEnemyCharacterGeneratorSpawnObject::vfunc_37()
{
    int r_eax, r_edi, r_esi;

    r_eax = m_FieldCA;
    if ((unsigned char)r_eax) {
        r_eax = m_FieldAC;
        r_esi = 0;
        if (r_eax > 0) {
            r_edi = (int)(&m_Field78);
            do {
                ((Object*)*(int*)r_edi)->sub_001DE370(64);
                r_eax = m_FieldAC;
                r_esi += 1;
                r_edi += 4;
            } while (r_esi < r_eax);
        }
        m_FieldCA = false;
    }
}

// ============================================================================
// [VERIFIED] ScatteredEnemyCharacterGeneratorSpawnObject::vfunc_01 (0x001E5640, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// ScatteredEnemyCharacterGeneratorSpawnObject::vfunc_01 (0x001E5640, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001E53D0(void);
extern "C" void __cdecl sub_00027600(int);

class ScatteredEnemyCharacterGeneratorSpawnObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ScatteredEnemyCharacterGeneratorSpawnObject* vfunc_01(int a1);
};

ScatteredEnemyCharacterGeneratorSpawnObject* ScatteredEnemyCharacterGeneratorSpawnObject::vfunc_01(int a1)
{
    sub_001E53D0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

