// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/TriggerVolumeObject.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 6 functions matched (66.67%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] TriggerVolumeObject::vfunc_00 (0x001D7BA0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// TriggerVolumeObject::vfunc_00 (0x001D7BA0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00425A60[];

class TriggerVolumeObject
{
public:
    virtual void* vfunc_00();
};

void* TriggerVolumeObject::vfunc_00()
{
    return DAT_00425A60;
}

// ============================================================================
// [VERIFIED] TriggerVolumeObject::vfunc_28 (0x001D7BB0, 32 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// TriggerVolumeObject::vfunc_28 (Proto 0x001D7BB0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field78
{
    void sub_0008C830(int);
};

extern "C" void __stdcall sub_00026F90(int);

class TriggerVolumeObject
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
    virtual void vfunc_28(int a1);
    char m_pad04[0x74];
    Field78* m_Field78; // +0x78
};

void TriggerVolumeObject::vfunc_28(int a1)
{
    sub_00026F90(a1);
    if (m_Field78) {
        m_Field78->sub_0008C830(a1);
    }
}

// ============================================================================
// [VERIFIED] TriggerVolumeObject::vfunc_30 (0x001D7BD0, 32 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// TriggerVolumeObject::vfunc_30 (Proto 0x001D7BD0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field78
{
    void sub_0008C960(int);
};

extern "C" void __stdcall sub_00026F40(int);

class TriggerVolumeObject
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
    virtual void vfunc_30(int a1);
    char m_pad04[0x74];
    Field78* m_Field78; // +0x78
};

void TriggerVolumeObject::vfunc_30(int a1)
{
    sub_00026F40(a1);
    if (m_Field78) {
        m_Field78->sub_0008C960(a1);
    }
}

// ============================================================================
// [VERIFIED] TriggerVolumeObject::vfunc_01 (0x001D7C70, 61 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// TriggerVolumeObject::vfunc_01 (Proto 0x001D7C70, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A9234[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_0008B8D0(int);

class TriggerVolumeObject
{
public:
    virtual void vfunc_00();
    virtual TriggerVolumeObject* vfunc_01(int a1);
    void sub_000277E0();
    char m_pad04[0x74];
    int m_Field78; // +0x78
};

TriggerVolumeObject* TriggerVolumeObject::vfunc_01(int a1)
{
    int t1;

    t1 = m_Field78;
    *(int*)this = (int)DAT_003A9234;
    if (m_Field78) {
        sub_0008B8D0(t1);
        m_Field78 = 0;
    }
    sub_000277E0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

