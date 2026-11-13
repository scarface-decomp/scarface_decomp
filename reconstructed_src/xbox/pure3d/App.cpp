// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/App.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::frontend::App::vfunc_00 (0x0024E1B0, 42 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::frontend::App::vfunc_00 (0x0024E1B0, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

struct Object
{
    void sub_0024FA50(int);
};

namespace pure3d { namespace frontend {

class App
{
public:
    virtual void vfunc_00(int a1);
    char m_pad04[0x10];
    int m_Field14; // +0x14
};

void App::vfunc_00(int a1)
{
    int r_ebx, r_edi, r_esi;

    r_ebx = a1;
    r_esi = (int)(&m_Field14);
    r_edi = 5;
    do {
        if (*(int*)r_esi) {
            ((Object*)*(int*)r_esi)->sub_0024FA50(r_ebx);
        }
        r_esi += 4;
        r_edi -= 1;
    } while (r_edi);
}

} }

