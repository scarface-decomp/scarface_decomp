// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, pure3d/DrawableContainer_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] content::LoadInventory::DynamicCaster<pure3d::DrawableContainer>::vfunc_00 (0x00276BB0, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as content::LoadInventory::DynamicCaster<pure3d::Font>::vfunc_00 (0x00249390), which was matched first;
// its addresses and names were swapped for this function's.
// The dynamic cast helper: (object, offset, from type, to type, is a reference).
extern "C" void* __cdecl sub_002FC034(void* object, int offset, void* from, void* to, int isReference);
extern "C" char DAT_004194F4[];
extern "C" char DAT_0041D3DC[];

namespace pure3d { class DrawableContainer; }

namespace content { namespace LoadInventory {

template <class T0> class DynamicCaster
{
public:
    virtual T0* vfunc_00(void* object);
};

} }

#pragma optimize("y", off)
template <> pure3d::DrawableContainer* content::LoadInventory::DynamicCaster<pure3d::DrawableContainer>::vfunc_00(void* object)
{
    return (pure3d::DrawableContainer*)sub_002FC034(object, 0, DAT_004194F4, DAT_0041D3DC, 0);
}
#pragma optimize("", on)

