// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, audio/NISStreamDataLoader.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] NISStreamDataLoader::vfunc_04 (0x006E9E70, 27 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GameGroupLoader::vfunc_04 (Proto 0x001FE150), which was matched first;
// its addresses and names were swapped for this function's.
// NISStreamDataLoader::vfunc_04 (Proto 0x006E9E70, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class NISStreamDataLoader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1, int a2, int a3, int a4, int a5);
    virtual void vfunc_05();
    virtual void vfunc_06(int, int, int, int);
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

void NISStreamDataLoader::vfunc_04(int a1, int a2, int a3, int a4, int a5)
{
    vfunc_06(a1, a2, m_Field10, a5);
}

