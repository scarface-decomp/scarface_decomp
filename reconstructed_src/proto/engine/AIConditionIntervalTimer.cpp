// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/AIConditionIntervalTimer.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIConditionIntervalTimer::vfunc_04 (0x001066C0, 71 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// AIConditionIntervalTimer::vfunc_04 (Proto 0x001066C0, 71 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04();
};

extern "C" int DAT_0045A0EC;

class AIConditionIntervalTimer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    unsigned char m_Field18; // +0x18
};

int AIConditionIntervalTimer::vfunc_04()
{
    int r_eax, r_edi;

    r_eax = DAT_0045A0EC;
    r_edi = *(int*)(r_eax + 44);
    if (r_edi != m_Field14) {
        r_eax = m_Field08->vfunc_04();
        if ((unsigned char)r_eax) {
            if (m_Field18) {
                m_Field0C = m_Field0C + (m_Field10 - r_edi);
            }
            m_Field10 = r_edi;
        }
        m_Field18 = (unsigned char)r_eax;
        m_Field14 = r_edi;
    }
    r_eax = 0;
    r_eax = m_Field0C <= 0;
    return r_eax;
}

