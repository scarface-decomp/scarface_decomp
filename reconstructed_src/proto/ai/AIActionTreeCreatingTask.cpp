// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, ai/AIActionTreeCreatingTask.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 11 functions matched (36.36%). NOT COMPLETE YET.
// The 7 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIActionTreeCreatingTask::vfunc_37 (0x000DBF50, 78 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIActionTreeCreatingTask::vfunc_37 (Proto 0x000DBF50, 78 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field58
{
    int sub_00105220();
};

extern "C" int DAT_0045A0EC;
extern "C" bool __cdecl sub_0010CDD0(int);
extern "C" int __cdecl sub_0010CE10(void);

class AIActionTreeCreatingTask
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
    virtual int vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual int vfunc_41();
    char m_pad04[0x50];
    int m_Field54; // +0x54
    Field58 m_Field58; // +0x58
    char m_pad59[0x3];
    int m_Field5C; // +0x5C
};

int AIActionTreeCreatingTask::vfunc_37()
{
    int r_edi, t5;

    r_edi = vfunc_41();
    if (r_edi > 0) {
        if (!m_Field54) goto L_49;
        if (!sub_0010CDD0((int)(&m_Field5C))) {
            t5 = *(int*)(DAT_0045A0EC + 44);
            if (m_Field58.sub_00105220() <= t5) goto L_49;
        }
        return sub_0010CE10() + 1;
    }
L_49:
    return r_edi;
}

// ============================================================================
// [VERIFIED] AIActionTreeCreatingTask::vfunc_00 (0x000DC4D0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionTreeCreatingTask::vfunc_00 (0x000DC4D0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00403D18[];

class AIActionTreeCreatingTask
{
public:
    virtual void* vfunc_00();
};

void* AIActionTreeCreatingTask::vfunc_00()
{
    return DAT_00403D18;
}

// ============================================================================
// [VERIFIED] AIActionTreeCreatingTask::vfunc_01 (0x000DC4E0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// AIActionTreeCreatingTask::vfunc_01 (0x000DC4E0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000DC500(void);
extern "C" void __cdecl sub_00025160(int);

class AIActionTreeCreatingTask
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual AIActionTreeCreatingTask* vfunc_01(int a1);
};

AIActionTreeCreatingTask* AIActionTreeCreatingTask::vfunc_01(int a1)
{
    sub_000DC500();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] AIActionTreeCreatingTask::vfunc_32 (0x000EFDC0, 51 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIActionTreeCreatingTask::vfunc_32 (Proto 0x000EFDC0, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01(int);
};

extern "C" int __cdecl sub_00028120(int);

class AIActionTreeCreatingTask
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
};

void AIActionTreeCreatingTask::vfunc_32()
{
    int r_ebx, r_edi, r_esi, t2;

    r_esi = (int)this;
    t2 = sub_00028120(*(int*)(r_esi + 32));
    r_edi = *(int*)(r_esi + 60);
    r_esi = *(int*)(r_esi + 56);
    r_ebx = t2;
    if (r_esi != r_edi) {
        do {
            ((Object*)*(int*)r_esi)->vfunc_01(r_ebx);
            r_esi += 4;
        } while (r_esi != r_edi);
    }
}

