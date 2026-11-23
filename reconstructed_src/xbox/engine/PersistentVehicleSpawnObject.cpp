// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/PersistentVehicleSpawnObject.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] PersistentVehicleSpawnObject::vfunc_00 (0x001E3610, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns PersistentVehicleSpawnObject's static class record (ConcreteClassRep<PersistentVehicleSpawnObject>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// PersistentVehicleSpawnObject::vfunc_00 (0x001E3610, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043DACC[];

class PersistentVehicleSpawnObject
{
public:
    virtual void* vfunc_00();
};

void* PersistentVehicleSpawnObject::vfunc_00()
{
    return DAT_0043DACC;
}

// ============================================================================
// [VERIFIED] PersistentVehicleSpawnObject::vfunc_57 (0x001E3620, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x001E3620
// what: 
// tool: the portal's starter code (no AI)

// PersistentVehicleSpawnObject::vfunc_57 (0x001E3620, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field208
{
    void sub_000BA4B0(int);
};

struct Object
{
    int sub_00217470();
};

class PersistentVehicleSpawnObject
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
    virtual bool vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57(int a1);
    char m_pad04[0x204];
    Field208 m_Field208; // +0x208
    char m_pad209[0x7B];
    bool m_Field284; // +0x284
};

void PersistentVehicleSpawnObject::vfunc_57(int a1)
{
    int t1;

    if (!a1) goto L_3C;
    t1 = ((Object*)a1)->sub_00217470();
    if (t1) {
        if (!vfunc_43()) goto L_3B;
        if (!m_Field284) goto L_3B;
        m_Field208.sub_000BA4B0(t1);
    }
L_3B:
L_3C:
    ;
}

// ============================================================================
// [VERIFIED] PersistentVehicleSpawnObject::vfunc_53 (0x001E3660, 74 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x001E3660
// what: 
// tool: the portal's starter code (no AI)

// PersistentVehicleSpawnObject::vfunc_53 (0x001E3660, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field208
{
    void sub_000B8E90(int);
};

struct Object
{
    int sub_00217470();
};

class PersistentVehicleSpawnObject
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
    virtual bool vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53(int a1, int a2);
    char m_pad04[0x204];
    Field208 m_Field208; // +0x208
    char m_pad209[0x7B];
    bool m_Field284; // +0x284
};

void PersistentVehicleSpawnObject::vfunc_53(int a1, int a2)
{
    int t1;

    if (!a2) goto L_46;
    if (a2 >= 5) goto L_46;
    if (!a1) goto L_46;
    t1 = ((Object*)a1)->sub_00217470();
    if (t1) {
        if (!vfunc_43()) goto L_45;
        m_Field208.sub_000B8E90(t1);
        m_Field284 = true;
    }
L_45:
L_46:
    ;
}

// ============================================================================
// [VERIFIED] PersistentVehicleSpawnObject::vfunc_01 (0x001E3850, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: PersistentVehicleSpawnObject's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// PersistentVehicleSpawnObject::vfunc_01 (0x001E3850, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C8104[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_001E2B80(void);

class PersistentVehicleSpawnObject
{
public:
    virtual void vfunc_00();
    virtual PersistentVehicleSpawnObject* vfunc_01(int a1);
};

PersistentVehicleSpawnObject* PersistentVehicleSpawnObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003C8104;
    sub_001E2B80();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

