// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/d3dExtUnLitColourTint.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] pure3d::d3dExtUnLitColourTint::vfunc_01 (0x00269B30, 19 B)
// By: lemiur | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Sets a global on/off switch used by the colour-tint extension.
// ============================================================================
// bin: xb
// va: 0x00269B30
// what: Sets a global on/off switch used by the colour-tint extension.
// tool: Claude Opus 5.5 (symcov hint: EARS::Modules::ChatterPlaybackManager::GetChatGroupHash, link-order)
// pure3d::d3dExtUnLitColourTint::vfunc_01 (0x00269B30, 19 bytes)
// pure3d is built with frame pointers (push ebp; mov ebp, esp), like the other pure3d functions.
#pragma optimize("y", off)

extern "C" void __cdecl sub_0029F7B0(bool value);

namespace pure3d {

class d3dExtUnLitColourTint
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(bool value);
};

// Forwards the value to the global setter.
void d3dExtUnLitColourTint::vfunc_01(bool value)
{
    sub_0029F7B0(value);
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dExtUnLitColourTint::vfunc_02 (0x00269B50, 19 B)
// By: lemiur | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dExtUnLitColourTint::vfunc_01 (0x00269B30), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00269B50
// what: Sets a global on/off switch used by the colour-tint extension.
// tool: Claude Opus 5.5 (symcov hint: EARS::Modules::ChatterPlaybackManager::GetChatGroupHash, link-order)
// pure3d::d3dExtUnLitColourTint::vfunc_02 (0x00269B50, 19 bytes)
// pure3d is built with frame pointers (push ebp; mov ebp, esp), like the other pure3d functions.
#pragma optimize("y", off)

extern "C" void __cdecl sub_0029F7C0(bool value);

namespace pure3d {

class d3dExtUnLitColourTint
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(bool value);
};

// Forwards the value to the global setter.
void d3dExtUnLitColourTint::vfunc_02(bool value)
{
    sub_0029F7C0(value);
}

}

