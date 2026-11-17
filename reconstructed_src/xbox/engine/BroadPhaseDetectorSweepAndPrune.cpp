// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/BroadPhaseDetectorSweepAndPrune.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 14 functions matched (21.43%). NOT COMPLETE YET.
// The 11 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] ravenphysics::BroadPhaseDetectorSweepAndPrune::vfunc_07 (0x002EC080, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ravenphysics::BroadPhaseDetectorSweepAndPrune::vfunc_07 (Proto 0x002B9880), which was matched first;
// its addresses and names were swapped for this function's.
// ravenphysics::BroadPhaseDetectorSweepAndPrune::vfunc_07 (Proto 0x002EC080, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace ravenphysics {

class BroadPhaseDetectorSweepAndPrune
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_07();
    char m_pad04[0x9C];
    int m_FieldA0; // +0xA0
};

void* BroadPhaseDetectorSweepAndPrune::vfunc_07()
{
    return &m_FieldA0;
}

}

// ============================================================================
// [VERIFIED] ravenphysics::BroadPhaseDetectorSweepAndPrune::vfunc_08 (0x002EC090, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as ravenphysics::BroadPhaseDetectorSweepAndPrune::vfunc_08 (Proto 0x002B9890), which was matched first;
// its addresses and names were swapped for this function's.
// ravenphysics::BroadPhaseDetectorSweepAndPrune::vfunc_08 (Proto 0x002EC090, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace ravenphysics {

class BroadPhaseDetectorSweepAndPrune
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void* vfunc_08();
    char m_pad04[0xAC];
    int m_FieldB0; // +0xB0
};

void* BroadPhaseDetectorSweepAndPrune::vfunc_08()
{
    return &m_FieldB0;
}

}

// ============================================================================
// [VERIFIED] ravenphysics::BroadPhaseDetectorSweepAndPrune::vfunc_03 (0x002ECB50, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// ravenphysics::BroadPhaseDetectorSweepAndPrune::vfunc_03 (0x002ECB50, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_002EC0A0(void);
extern "C" void __cdecl sub_0023F7A0(int);

namespace ravenphysics {

class BroadPhaseDetectorSweepAndPrune
{
public:
    virtual BroadPhaseDetectorSweepAndPrune* vfunc_03(int a1);
};

BroadPhaseDetectorSweepAndPrune* BroadPhaseDetectorSweepAndPrune::vfunc_03(int a1)
{
    sub_002EC0A0();
    if (a1 & 1) {
        sub_0023F7A0((int)this);
    }
    return this;
}

}

