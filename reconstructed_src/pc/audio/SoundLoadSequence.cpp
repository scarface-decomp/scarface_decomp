// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/SoundLoadSequence.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] SoundLoadSequence::vfunc_00 (0x006FD9F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G7 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: pc
// va: 0x006FD9F0
// what: 
// tool: the portal's starter code (no AI)

// SoundLoadSequence::vfunc_00 (PC 0x006FD9F0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class SoundLoadSequence
{
public:
    virtual void vfunc_00();
    char m_pad04[0x30];
    unsigned short m_Field34; // +0x34
};

void SoundLoadSequence::vfunc_00()
{
    m_Field34 += 1;
}

