// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AITask_WaitWhenTonyIsNear.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 7 functions matched (57.14%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_WaitWhenTonyIsNear::vfunc_38 (0x0010E410, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_WaitWhenTonyIsNear::vfunc_35 (Proto 0x000F6FF0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_WaitWhenTonyIsNear::vfunc_38 (Proto 0x0010E410, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class AITask_WaitWhenTonyIsNear
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
    char m_pad04[0x48];
    int m_Field4C; // +0x4C
};

void AITask_WaitWhenTonyIsNear::vfunc_38()
{
    m_Field4C = 0;
}

// ============================================================================
// [VERIFIED] AITask_WaitWhenTonyIsNear::vfunc_39 (0x0010E470, 62 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AITask_WaitWhenTonyIsNear::vfunc_36 (Proto 0x000F7050), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_WaitWhenTonyIsNear::vfunc_39 (Proto 0x0010E470, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000F2770(int, int);
    int sub_00163D50();
    void sub_00166020(int);
};

extern "C" int __cdecl sub_0002AC90(int);

class AITask_WaitWhenTonyIsNear
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
    int sub_00104FD0();
};

void AITask_WaitWhenTonyIsNear::vfunc_39()
{
    int r_esi, t2;

    r_esi = (int)this;
    t2 = sub_0002AC90(*(int*)(r_esi + 32));
    r_esi = sub_00104FD0();
    if (((Object*)t2)->sub_00163D50() >= 90) {
        ((Object*)t2)->sub_00166020(0);
    }
    ((Object*)r_esi)->sub_000F2770(1, 0);
}

// ============================================================================
// [VERIFIED] AITask_WaitWhenTonyIsNear::vfunc_00 (0x0010E830, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns AITask_WaitWhenTonyIsNear's static class record (ConcreteClassRep<AITask_WaitWhenTonyIsNear>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_WaitWhenTonyIsNear::vfunc_00 (0x0010E830, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00429084[];

class AITask_WaitWhenTonyIsNear
{
public:
    virtual void* vfunc_00();
};

void* AITask_WaitWhenTonyIsNear::vfunc_00()
{
    return DAT_00429084;
}

// ============================================================================
// [VERIFIED] AITask_WaitWhenTonyIsNear::vfunc_01 (0x0010E870, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Wait-when-Tony-is-near task's deleting destructor: tells its driver to let go of the target, shuts the driver down, then frees itself when asked.
// ============================================================================
// Same machine code as AITask_ChallengeTony::vfunc_01 (0x00105D40), which was matched first;
// its addresses and names were swapped for this function's.
struct Driver
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int target);
};

extern "C" char DAT_003ACF8C[];
extern "C" void __cdecl sub_00027600(void* p);

class AITask_WaitWhenTonyIsNear
{
public:
    virtual void vfunc_00();
    virtual AITask_WaitWhenTonyIsNear* vfunc_01(unsigned int flags);
    void sub_0002C720();

    char m_pad04[0x34];
    int m_target;     // +0x38
    int m_lastTarget; // +0x3C
    char m_pad40[0x4];
    Driver* m_driver; // +0x44
};

// Deleting destructor: lets go of the target it was challenging, tells the driver, runs the
// base destructor and frees itself when asked. The volatile accesses keep the vtable store
// ahead of the read, as the compiler does in a real destructor.
AITask_WaitWhenTonyIsNear* AITask_WaitWhenTonyIsNear::vfunc_01(unsigned int flags)
{
    *(void* volatile*)this = DAT_003ACF8C;
    int target = *(int volatile*)&m_target;
    m_lastTarget = target;
    if (target)
        m_driver->vfunc_05(target);
    m_driver->vfunc_01();
    sub_0002C720();
    if (flags & 1)
        sub_00027600(this);
    return this;
}

