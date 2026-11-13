// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/PresentationState.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 13 functions matched (15.38%). NOT COMPLETE YET.
// The 11 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] PresentationState::vfunc_02 (0x001ED3F0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as PropAttachToObjectBehaviour::vfunc_01 (0x0008FAF0), which was matched first;
// its addresses and names were swapped for this function's.
// PresentationState::vfunc_02 (0x001ED3F0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001ECD90(void);

class PresentationState
{
public:
    virtual void vfunc_00();
    virtual void vfunc_02();
};

void PresentationState::vfunc_02()
{
    sub_001ECD90();
}

// ============================================================================
// [VERIFIED] PresentationState::vfunc_00 (0x001EE0D0, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundSequenceLoader::vfunc_03 (0x00065190), which was matched first;
// its addresses and names were swapped for this function's.
// PresentationState::vfunc_00 (0x001EE0D0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AB82C[];
extern "C" void __cdecl sub_00025160(int);

class PresentationState
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual PresentationState* vfunc_00(int a1);
};

PresentationState* PresentationState::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003AB82C;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

