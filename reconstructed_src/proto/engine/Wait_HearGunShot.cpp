// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/Wait_HearGunShot.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommandWaits::Wait_HearGunShot::vfunc_00 (0x0011D790, 103 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommandWaits::Wait_HearGunShot::vfunc_00 (Proto 0x0011D790, 103 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01(int);
    void sub_00024AB0(int);
    void sub_00024AD0();
    int sub_00102C10(int, int);
    int sub_00102E30();
};

extern "C" int __cdecl sub_00025120(int);

namespace AICommandWaits {

class Wait_HearGunShot
{
public:
    virtual void vfunc_00(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

void Wait_HearGunShot::vfunc_00(int a1, int a2)
{
    int local_4, r_eax;

    ((Object*)(int)(&local_4))->sub_00024AB0(10);
    r_eax = sub_00025120(16);
    if (r_eax) {
        r_eax = ((Object*)r_eax)->sub_00102E30();
    } else {
        r_eax = 0;
    }
    m_Field0C = r_eax;
    r_eax = sub_00025120(16);
    if (r_eax) {
        r_eax = ((Object*)r_eax)->sub_00102C10(2, m_Field0C);
    } else {
        r_eax = 0;
    }
    m_Field10 = r_eax;
    ((Object*)r_eax)->vfunc_01(a2);
    ((Object*)(int)(&local_4))->sub_00024AD0();
}

}

// ============================================================================
// [VERIFIED] AICommandWaits::Wait_HearGunShot::vfunc_01 (0x0011D800, 24 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AICommandWaits::Wait_HearGunShot::vfunc_01 (Proto 0x0011D800, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace AICommandWaits {

class Wait_HearGunShot
{
public:
    virtual void vfunc_00();
    virtual bool vfunc_01(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

bool Wait_HearGunShot::vfunc_01(int a1, int a2)
{
    int t1;

    t1 = m_Field0C;
    if (*(bool*)(m_Field0C + 12)) {
        *(bool*)(t1 + 12) = false;
        return true;
    }
    return false;
}

}

// ============================================================================
// [VERIFIED] AICommandWaits::Wait_HearGunShot::vfunc_03 (0x0011DE90, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// AICommandWaits::Wait_HearGunShot::vfunc_03 (0x0011DE90, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0011D740(void);
extern "C" void __cdecl sub_00025160(int);

namespace AICommandWaits {

class Wait_HearGunShot
{
public:
    virtual Wait_HearGunShot* vfunc_03(int a1);
};

Wait_HearGunShot* Wait_HearGunShot::vfunc_03(int a1)
{
    sub_0011D740();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

}

