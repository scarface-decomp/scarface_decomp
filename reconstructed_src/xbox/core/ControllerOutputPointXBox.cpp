// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/ControllerOutputPointXBox.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 2 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::ControllerOutputPointXBox::vfunc_05 (0x00247FC0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerXBox::vfunc_05 (0x00247C10), which was matched first;
// its addresses and names were swapped for this function's.
// core::ControllerOutputPointXBox::vfunc_05 (0x00247FC0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039E14C[];

namespace core {

class ControllerOutputPointXBox
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void* vfunc_05();
};

void* ControllerOutputPointXBox::vfunc_05()
{
    return DAT_0039E14C;
}

}

// ============================================================================
// [VERIFIED] core::ControllerOutputPointXBox::vfunc_07 (0x00247FD0, 64 B)
// By: lemiur | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Stores a number in the controller output, kept between zero and one.
// ============================================================================
// bin: xb
// va: 0x00247FD0
// what: Stores a number in the controller output, kept between zero and one.
// tool: Claude Opus 5.5 (symcov hint: Reward::SetScale)
// core::ControllerOutputPointXBox::vfunc_07 (0x00247FD0, 64 bytes)

namespace core {

class ControllerOutputPointXBox
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void* vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(float value);

    char m_pad04[0x8];
    float m_Field0C; // +0x0C
};

// Clamps the value to [0, 1] and stores it.
void ControllerOutputPointXBox::vfunc_07(float value)
{
    if (value < 0.0f)
    {
        m_Field0C = 0.0f;
    }
    else if (value > 1.0f)
    {
        m_Field0C = 1.0f;
    }
    else
    {
        m_Field0C = value;
    }
}

}

