// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/DriveManager.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] DriveManager::vfunc_00 (0x00060B70, 84 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// DriveManager::vfunc_00 (0x00060B70, 84 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EC0F0();
};

extern "C" int DAT_0048E54C;
extern "C" int __stdcall sub_000EB680(int, int, int);

class DriveManager
{
public:
    virtual bool vfunc_00(int a1, int a2, int a3, int a4, int a5);
};

bool DriveManager::vfunc_00(int a1, int a2, int a3, int a4, int a5)
{
    int r_eax, r_ecx, t1;

    r_ecx = (int)this;
    r_eax = a1;
    if (!a1) {
        *(int*)(r_ecx + 892) = a1;
        r_eax = 1;
        return r_eax;
    }
    if (r_eax == 1) {
        r_eax = 0;
        return r_eax;
    }
    if (*(int*)(r_ecx + 892) != r_eax) {
        t1 = DAT_0048E54C;
        if (!DAT_0048E54C) goto L_4F;
        if (*(int*)(t1 + 96) & 8) goto L_4F;
        *(int*)(r_ecx + 892) = r_eax;
        r_eax = sub_000EB680(225, r_eax, 0);
        r_ecx = r_eax;
        ((Object*)r_ecx)->sub_000EC0F0();
    }
L_4F:
    r_eax = 1;
    return r_eax;
}

// ============================================================================
// [VERIFIED] DriveManager::vfunc_01 (0x000610A0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// DriveManager::vfunc_01 (0x000610A0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00060CC0(void);
extern "C" void __cdecl sub_00027600(int);

class DriveManager
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual DriveManager* vfunc_01(int a1);
};

DriveManager* DriveManager::vfunc_01(int a1)
{
    sub_00060CC0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

