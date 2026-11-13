// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/FEMeshBroadcast.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 6 functions matched (50.00%). NOT COMPLETE YET.
// The 3 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] FEMeshBroadcast::vfunc_06 (0x000231A0, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FEMeshBroadcast::vfunc_06 (0x000231A0, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;

class FEMeshBroadcast
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual float vfunc_06();
    char m_pad04[0xC];
    float m_Field10; // +0x10
    int m_Field14; // +0x14
};

float FEMeshBroadcast::vfunc_06()
{
    if (m_Field14 & 1) {
        return m_Field10;
    }
    return DAT_0039D664;
}

// ============================================================================
// [VERIFIED] FEMeshBroadcast::vfunc_05 (0x00023800, 57 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// FEMeshBroadcast::vfunc_05 (0x00023800, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int, int);
    virtual void vfunc_07(int, int);
};

class FEMeshBroadcast
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05(int a1);
    char m_pad04[0x10];
    int m_Field14; // +0x14
};

int FEMeshBroadcast::vfunc_05(int a1)
{
    if (m_Field14 & 2) {
        ((Object*)*(int*)(a1 + 12))->vfunc_06(0x444D4345, 0);
    }
    if (m_Field14 & 1) {
        ((Object*)*(int*)(a1 + 12))->vfunc_07(0x45444146, 0);
    }
    return a1;
}

// ============================================================================
// [VERIFIED] FEMeshBroadcast::vfunc_03 (0x001225B0, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundSequenceLoader::vfunc_03 (0x00065190), which was matched first;
// its addresses and names were swapped for this function's.
// FEMeshBroadcast::vfunc_03 (0x001225B0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039E22C[];
extern "C" void __cdecl sub_00027600(int);

class FEMeshBroadcast
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual FEMeshBroadcast* vfunc_03(int a1);
};

FEMeshBroadcast* FEMeshBroadcast::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_0039E22C;
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

