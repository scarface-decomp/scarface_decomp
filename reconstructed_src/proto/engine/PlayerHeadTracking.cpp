// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/PlayerHeadTracking.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] PlayerHeadTracking::vfunc_00 (0x00144E30, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// PlayerHeadTracking::vfunc_00 (0x00144E30, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0040AEE8[];

class PlayerHeadTracking
{
public:
    virtual void* vfunc_00();
};

void* PlayerHeadTracking::vfunc_00()
{
    return DAT_0040AEE8;
}

// ============================================================================
// [VERIFIED] PlayerHeadTracking::vfunc_09 (0x00145960, 118 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// PlayerHeadTracking::vfunc_09 (Proto 0x00145960, 118 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0008D4E0(int);
    void sub_001467E0();
    bool sub_00147370();
    int sub_0014A290();
};

extern "C" Object DAT_00462DD4;
extern "C" int DAT_00462DD8;

class PlayerHeadTracking
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
    virtual void vfunc_09(int a1);
    bool sub_00145370(int);
    bool sub_00145410(int);
    bool sub_001457B0(int);
    char m_pad04[0x2C];
    int m_Field30; // +0x30
    int m_Field34; // +0x34
};

void PlayerHeadTracking::vfunc_09(int a1)
{
    int r_ebx, r_edi;

    r_edi = DAT_00462DD4.sub_0008D4E0(DAT_00462DD8);
    r_ebx = 0;
    if (r_edi) {
        if (!((Object*)r_edi)->sub_00147370()) {
            m_Field30 = 0;
            m_Field34 = 0;
            return;
        }
        r_ebx = r_edi + 396;
        if (!((Object*)r_edi)->sub_0014A290()) {
            if (sub_00145370(r_ebx)) goto L_70;
            if (sub_001457B0(r_ebx)) goto L_70;
            if (sub_00145410(r_ebx)) goto L_70;
        }
        ((Object*)r_ebx)->sub_001467E0();
    }
L_70:
    ;
}

