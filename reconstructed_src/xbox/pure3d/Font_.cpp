// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/Font_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] content::LoadInventory::DynamicCaster<pure3d::Font>::vfunc_00 (0x00249390, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Casts an object to pure3d::Font at run time (null if it is something else).
// ============================================================================
// The dynamic cast helper: (object, offset, from type, to type, is a reference).
extern "C" void* __cdecl sub_002FC034(void* object, int offset, void* from, void* to, int isReference);
extern "C" char DAT_004194F4[];
extern "C" char DAT_0045865C[];

namespace pure3d { class Font; }

namespace content { namespace LoadInventory {

template <class T0> class DynamicCaster
{
public:
    virtual T0* vfunc_00(void* object);
};

} }

#pragma optimize("y", off)
template <> pure3d::Font* content::LoadInventory::DynamicCaster<pure3d::Font>::vfunc_00(void* object)
{
    return (pure3d::Font*)sub_002FC034(object, 0, DAT_004194F4, DAT_0045865C, 0);
}
#pragma optimize("", on)

