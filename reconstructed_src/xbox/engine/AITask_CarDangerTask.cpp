// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AITask_CarDangerTask.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AITask_CarDangerTask::vfunc_00 (0x001226A0, 57 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AITask_CarDangerTask::vfunc_00 (0x001226A0, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
    void sub_000CA330();
};

struct FieldM54
{
    bool sub_00104F70();
};

struct Object
{
    int sub_00104FD0();
    int sub_002D5920();
};

class AITask_CarDangerTask
{
public:
    virtual void vfunc_00(int a1);
    Field04 m_Field04; // +0x04
    char m_pad05[0x7];
    int m_Field0C; // +0x0C
};

void AITask_CarDangerTask::vfunc_00(int a1)
{
    int r_edi;

    r_edi = (int)(((char*)this - 0x54));
    if (!((FieldM54*)(int)(((char*)this - 0x54)))->sub_00104F70()) {
        m_Field0C = ((Object*)a1)->sub_002D5920();
    }
    *(bool*)(((Object*)r_edi)->sub_00104FD0() + 1394) = true;
    m_Field04.sub_000CA330();
}

