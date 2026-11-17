// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/AIStimulusMonitor.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AIStimulusMonitor::vfunc_00 (0x0011E020, 18 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIStimulusMonitor::vfunc_00 (Proto 0x00102E50), which was matched first;
// its addresses and names were swapped for this function's.
// AIStimulusMonitor::vfunc_00 (Proto 0x0011E020, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004879E8;

class AIStimulusMonitor
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    bool m_Field0C; // +0x0C
};

int AIStimulusMonitor::vfunc_00(int a1)
{
    int t1;

    m_Field0C = true;
    t1 = DAT_004879E8;
    m_Field08 = *(int*)(DAT_004879E8 + 44);
    return t1;
}

// ============================================================================
// [VERIFIED] AIStimulusMonitor::vfunc_02 (0x0011E040, 5 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AIStimulusMonitor::vfunc_02 (Proto 0x00102E70), which was matched first;
// its addresses and names were swapped for this function's.
// AIStimulusMonitor::vfunc_02 (Proto 0x0011E040, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class AIStimulusMonitor
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    char m_pad04[0x4];
    bool m_Field08; // +0x08
};

void AIStimulusMonitor::vfunc_02()
{
    m_Field08 = false;
}

