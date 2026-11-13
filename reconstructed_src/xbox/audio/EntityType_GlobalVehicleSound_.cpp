// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, audio/EntityType_GlobalVehicleSound_.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] om::EntityType<GlobalVehicleSound>::vfunc_03 (0x000653B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// om::EntityType<GlobalVehicleSound>::vfunc_03 (0x000653B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0041E4B8[];

class GlobalVehicleSound;

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void* vfunc_03();
};
}

template <> void* om::EntityType<GlobalVehicleSound>::vfunc_03()
{
    return DAT_0041E4B8;
}

// ============================================================================
// [VERIFIED] om::EntityType<GlobalVehicleSound>::vfunc_02 (0x000653C0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// om::EntityType<GlobalVehicleSound>::vfunc_02 (0x000653C0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0047639C;

class GlobalVehicleSound;

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
};
}

template <> int om::EntityType<GlobalVehicleSound>::vfunc_02()
{
    return DAT_0047639C;
}

// ============================================================================
// [VERIFIED] om::EntityType<GlobalVehicleSound>::vfunc_00 (0x000653D0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// om::EntityType<GlobalVehicleSound>::vfunc_00 (0x000653D0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_002CF4C0(void);

class GlobalVehicleSound;

namespace om { 
template <class T0> class EntityType
{
public:
    virtual EntityType<GlobalVehicleSound>* vfunc_00(int a1);
};
}

template <> om::EntityType<GlobalVehicleSound>* om::EntityType<GlobalVehicleSound>::vfunc_00(int a1)
{
    sub_002CF4C0();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

