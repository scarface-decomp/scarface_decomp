// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AITask_VehicleGetIn.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 6 functions matched (33.33%). NOT COMPLETE YET.
// The 4 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_VehicleGetIn::vfunc_00 (0x0010E1A0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// AITask_VehicleGetIn::vfunc_00 (0x0010E1A0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004290B0[];

class AITask_VehicleGetIn
{
public:
    virtual void* vfunc_00();
};

void* AITask_VehicleGetIn::vfunc_00()
{
    return DAT_004290B0;
}

// ============================================================================
// [VERIFIED] AITask_VehicleGetIn::vfunc_01 (0x0010E3C0, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
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

extern "C" char DAT_003ACE84[];
extern "C" void __cdecl sub_00027600(void* p);

class AITask_VehicleGetIn
{
public:
    virtual void vfunc_00();
    virtual AITask_VehicleGetIn* vfunc_01(unsigned int flags);
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
AITask_VehicleGetIn* AITask_VehicleGetIn::vfunc_01(unsigned int flags)
{
    *(void* volatile*)this = DAT_003ACE84;
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

