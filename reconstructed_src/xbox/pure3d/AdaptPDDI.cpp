// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/AdaptPDDI.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::AdaptPDDI::vfunc_00 (0x00292230, 19 B)
// By: lemiur | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dExtUnLitColourTint::vfunc_01 (0x00269B30), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00292230
// what: Sets a global on/off switch used by the colour-tint extension.
// tool: Claude Opus 5.5 (symcov hint: EARS::Modules::ChatterPlaybackManager::GetChatGroupHash, link-order)
// pure3d::AdaptPDDI::vfunc_00 (0x00292230, 19 bytes)
// pure3d is built with frame pointers (push ebp; mov ebp, esp), like the other pure3d functions.
#pragma optimize("y", off)

extern "C" void __cdecl sub_002A9290(bool value);

namespace pure3d {

class AdaptPDDI
{
public:
    virtual void vfunc_00(bool value);
};

// Forwards the value to the global setter.
void AdaptPDDI::vfunc_00(bool value)
{
    sub_002A9290(value);
}

}

// ============================================================================
// [VERIFIED] pure3d::AdaptPDDI::vfunc_02 (0x00292250, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// pure3d::AdaptPDDI::vfunc_02 (0x00292250, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
#pragma optimize("y", off)

extern "C" void __cdecl sub_00250F80(int, int, int);

namespace pure3d {

class AdaptPDDI
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1, int a2, int a3);
};

void AdaptPDDI::vfunc_02(int a1, int a2, int a3)
{
    sub_00250F80(a1, a2, a3);
}

}

