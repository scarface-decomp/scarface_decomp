// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/AITask_BasicInVehicle.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 4 functions matched (50.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_BasicInVehicle::vfunc_37 (0x000F5E20, 56 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Looks a value up the first time, keeps it, and returns the kept value after that.
// ============================================================================
// bin: proto
// va: 0x000F5E20
// what: Looks a value up the first time, keeps it, and returns the kept value after that.
// tool: Claude Fable 5.2 (look-alike of proto 0x000F5EB0, names and addresses swapped)
// AITask_BasicInVehicle::vfunc_37 (0x000F5E20, 56 bytes)
extern "C" char DAT_0038AB84[];
extern "C" int DAT_0045BB58;
extern "C" bool DAT_0045BB5C;
extern "C" int __cdecl sub_00065CF0(int, int);

class AITask_BasicInVehicle
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
};

int AITask_BasicInVehicle::vfunc_37()
{
    int t1;

    if (!(1 & DAT_0045BB5C)) {
        *(int*)&DAT_0045BB5C = *(int*)&DAT_0045BB5C | 1;
        t1 = sub_00065CF0((int)DAT_0038AB84, 0);
        DAT_0045BB58 = t1;
        return t1;
    }
    return DAT_0045BB58;
}

// ============================================================================
// [VERIFIED] AITask_BasicInVehicle::vfunc_00 (0x000F6230, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_BasicInVehicle::vfunc_00 (0x000F6230, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004041E8[];

class AITask_BasicInVehicle
{
public:
    virtual void* vfunc_00();
};

void* AITask_BasicInVehicle::vfunc_00()
{
    return DAT_004041E8;
}

