// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/GlanceAtOvertakingPed.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 9 functions matched (44.44%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] GlanceAtOvertakingPed::vfunc_01 (0x000EFD00, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GlanceAtOvertakingPed::vfunc_01 (0x000EFD00, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000CA300(int, int);
};

class GlanceAtOvertakingPed
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void GlanceAtOvertakingPed::vfunc_01()
{
    ((Object*)(int)this + 20)->sub_000CA300(350, 600);
}

// ============================================================================
// [VERIFIED] GlanceAtOvertakingPed::vfunc_08 (0x000EFD20, 7 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// GlanceAtOvertakingPed::vfunc_08 (0x000EFD20, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003B2314;

class GlanceAtOvertakingPed
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
    virtual float vfunc_08();
};

float GlanceAtOvertakingPed::vfunc_08()
{
    return DAT_003B2314;
}

// ============================================================================
// [VERIFIED] GlanceAtOvertakingPed::vfunc_10 (0x000EFE30, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GlanceAtOvertakingPed::vfunc_10 (Proto 0x0026CAA0), which was matched first;
// its addresses and names were swapped for this function's.
// GlanceAtOvertakingPed::vfunc_10 (Proto 0x000EFE30, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GlanceAtOvertakingPed
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
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual int vfunc_10();
};

int GlanceAtOvertakingPed::vfunc_10()
{
    return 13;
}

// ============================================================================
// [VERIFIED] GlanceAtOvertakingPed::vfunc_00 (0x000F0540, 41 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GlanceAtOvertakingPed::vfunc_00 (Proto 0x000DCE50), which was matched first;
// its addresses and names were swapped for this function's.
// GlanceAtOvertakingPed::vfunc_00 (Proto 0x000F0540, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class GlanceAtOvertakingPed
{
public:
    virtual int vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual bool vfunc_07();
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

int GlanceAtOvertakingPed::vfunc_00()
{
    if (sub_0002AC90(m_Field10)) {
        if (!vfunc_07()) goto L_25;
        return 1;
    }
L_25:
    return 0;
}

