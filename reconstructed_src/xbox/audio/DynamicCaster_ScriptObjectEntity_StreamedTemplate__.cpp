// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/DynamicCaster_ScriptObjectEntity_StreamedTemplate__.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] content::LoadInventory::DynamicCaster<ScriptObjectEntity<StreamedTemplate>>::vfunc_00 (0x001DE410, 30 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Checks a loaded object's type: dynamic_cast to ScriptObjectEntity<StreamedTemplate> (the C++ run-time cast; null if it is something else).
// ============================================================================
// Same machine code as content::LoadInventory::DynamicCaster<ScriptObjectEntity<StreamedTemplate>>::vfunc_00 (Proto 0x001A6580), which was matched first;
// its addresses and names were swapped for this function's.
// content::LoadInventory::DynamicCaster<ScriptObjectEntity<StreamedTemplate>>::vfunc_00 (Proto 0x001DE410, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004194F4[];
extern "C" char DAT_0041B55C[];
extern "C" void __cdecl sub_002FC034(int, int, int, int, int);

namespace content { namespace LoadInventory {

class DynamicCaster_ScriptObjectEntity_StreamedTemplate__
{
public:
    virtual void vfunc_00(int a1);
};

void DynamicCaster_ScriptObjectEntity_StreamedTemplate__::vfunc_00(int a1)
{
    sub_002FC034(a1, 0, (int)DAT_004194F4, (int)DAT_0041B55C, 0);
}

} }

