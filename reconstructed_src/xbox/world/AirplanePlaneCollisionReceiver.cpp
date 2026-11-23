// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, world/AirplanePlaneCollisionReceiver.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AirplanePlaneCollisionReceiver::vfunc_00 (0x0009B2D0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AirplanePlaneCollisionReceiver::vfunc_00 (0x0009B2D0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
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
};

class AirplanePlaneCollisionReceiver
{
public:
    virtual void vfunc_00();
    Field04* m_Field04; // +0x04
};

void AirplanePlaneCollisionReceiver::vfunc_00()
{
    m_Field04->vfunc_09();
}

// ============================================================================
// [VERIFIED] AirplanePlaneCollisionReceiver::vfunc_03 (0x0009B2E0, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x0009B2E0
// what: 
// tool: the portal's starter code (no AI)

// AirplanePlaneCollisionReceiver::vfunc_03 (0x0009B2E0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
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
    virtual bool vfunc_10();
};

class AirplanePlaneCollisionReceiver
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual bool vfunc_03();
    Field04* m_Field04; // +0x04
    char m_pad08[0x8];
    bool m_Field10; // +0x10
};

bool AirplanePlaneCollisionReceiver::vfunc_03()
{
    if (m_Field10) {
        return m_Field04->vfunc_10();
    }
    return true;
}

