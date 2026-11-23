// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/GenericAnimation.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 4 functions matched (50.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GenericAnimation::vfunc_03 (0x001C4A60, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4 /arch:SSE
// ============================================================================
// bin: xb
// va: 0x001C4A60
// what: 
// tool: the portal's starter code (no AI)

// GenericAnimation::vfunc_03 (0x001C4A60, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GenericAnimation
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    char m_pad04[0x4];
    int m_Field08; // +0x08
    char m_pad0C[0x4];
    int m_Field10; // +0x10
    char m_pad14[0x4];
    float m_Field18; // +0x18
};

void GenericAnimation::vfunc_03()
{
    int t1;

    t1 = m_Field10;
    m_Field18 = 0.0f;
    m_Field08 = t1;
    vfunc_04();
}

// ============================================================================
// [VERIFIED] GenericAnimation::vfunc_00 (0x001C5500, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: GenericAnimation's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as SoundSequenceLoader::vfunc_03 (0x00065190), which was matched first;
// its addresses and names were swapped for this function's.
// GenericAnimation::vfunc_00 (0x001C5500, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C324C[];
extern "C" void __cdecl sub_00027600(int);

class GenericAnimation
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual GenericAnimation* vfunc_00(int a1);
};

GenericAnimation* GenericAnimation::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003C324C;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

