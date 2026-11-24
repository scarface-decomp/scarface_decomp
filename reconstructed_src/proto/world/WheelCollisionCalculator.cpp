// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, world/WheelCollisionCalculator.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] WheelCollisionCalculator::vfunc_02 (0x0007CEB0, 4 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// WheelCollisionCalculator::vfunc_02 (Proto 0x0007CEB0, 4 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class WheelCollisionCalculator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    char m_pad04[0x24];
    int m_Field28; // +0x28
};

int WheelCollisionCalculator::vfunc_02()
{
    return m_Field28;
}

// ============================================================================
// [VERIFIED] WheelCollisionCalculator::vfunc_00 (0x000A4B80, 22 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as WheelCollisionCalculator::vfunc_00 (0x000B2080), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x000A4B80
// what: If m_Field04 is non-null, calls sub_000AF370 and stores its negated float result at +0x08.
// tool: Gemini 4 Neon

class WheelCollisionCalculator
{
public:
    virtual void vfunc_00();
    float sub_000AF370();
    int m_Field04; // +0x04
    float m_Field08; // +0x08
};

void WheelCollisionCalculator::vfunc_00()
{
    if (m_Field04) {
        m_Field08 = -sub_000AF370();
    }
}

