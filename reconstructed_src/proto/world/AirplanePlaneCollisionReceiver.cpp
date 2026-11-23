// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, world/AirplanePlaneCollisionReceiver.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AirplanePlaneCollisionReceiver::vfunc_00 (0x0008FB90, 8 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AirplanePlaneCollisionReceiver::vfunc_00 (Proto 0x0008FB90, 8 bytes)
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
    virtual void vfunc_10();
    virtual void vfunc_11();
};

class AirplanePlaneCollisionReceiver
{
public:
    virtual void vfunc_00();
    Field04* m_Field04; // +0x04
};

void AirplanePlaneCollisionReceiver::vfunc_00()
{
    m_Field04->vfunc_11();
}

// ============================================================================
// [VERIFIED] AirplanePlaneCollisionReceiver::vfunc_03 (0x0008FBA0, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x0008FBA0
// what: 
// tool: the portal's starter code (no AI)

// AirplanePlaneCollisionReceiver::vfunc_03 (Proto 0x0008FBA0, 18 bytes)
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual bool vfunc_12();
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
        return m_Field04->vfunc_12();
    }
    return true;
}

