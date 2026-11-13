// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/PlayerVehicleIntention.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] PlayerVehicleIntention::vfunc_00 (0x000A5860, 44 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// PlayerVehicleIntention::vfunc_00 (0x000A5860, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
    bool sub_000AC800(int);
};

class PlayerVehicleIntention
{
public:
    virtual void vfunc_00(int a1);
    virtual bool vfunc_01(int);
    Field04* m_Field04; // +0x04
    unsigned char m_Field08; // +0x08
};

void PlayerVehicleIntention::vfunc_00(int a1)
{
    m_Field08 = 0;
    if (m_Field04) {
        if (!m_Field04->sub_000AC800(0)) goto L_28;
        m_Field08 = vfunc_01(a1);
    }
L_28:
    ;
}

