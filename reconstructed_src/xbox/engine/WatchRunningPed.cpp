// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/WatchRunningPed.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 2 functions matched (50.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] WatchRunningPed::vfunc_07 (0x000F05C0, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x000F05C0
// what: 
// tool: the portal's starter code (no AI)

// WatchRunningPed::vfunc_07 (0x000F05C0, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    bool sub_000CA1C0();
    void sub_000CA300(int, int);
};

extern "C" int __cdecl sub_0002AC90(int);

class WatchRunningPed
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07();
    bool sub_000F0390(int, int);
    char m_pad04[0xC];
    int m_Field10; // +0x10
    Field14 m_Field14; // +0x14
};

int WatchRunningPed::vfunc_07()
{
    int t2;

    t2 = sub_0002AC90(m_Field10);
    if (sub_000F0390(t2, t2 + 100)) {
        m_Field14.sub_000CA300(700, 1500);
    }
    return !m_Field14.sub_000CA1C0();
}

