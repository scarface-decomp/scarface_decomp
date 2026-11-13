// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail PC Scarface.exe v1.00.2, every function in address order
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 412 of 1,516 functions matched (27.18%). NOT COMPLETE YET.
// The 1,104 still to do are listed in their place below as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// [TODO] 0x006DDC60 core::ControllerInputPointDirectInput::vfunc_01 (23 B)
// [TODO] 0x006DDC80 core::ControllerDirectInput::vfunc_05 (7 B)
// [TODO] 0x006DDC90 core::ControllerDirectInput::vfunc_09 (117 B)
// [TODO] 0x006DDD10 core::ControllerDirectInput::vfunc_14 (115 B)
// [TODO] 0x006DDD90 core::ControllerDirectInput::vfunc_11 (67 B)
// [TODO] 0x006DDDE0 core::ControllerDirectInput::vfunc_16 (103 B)
// [TODO] 0x006DDE50 core::ControllerDirectInput::vfunc_10 (115 B)
// [TODO] 0x006DDED0 core::ControllerDirectInput::vfunc_15 (115 B)
// [TODO] 0x006DDF50 core::ControllerDirectInput::vfunc_08 (7 B)
// [TODO] 0x006DDF60 core::ControllerDirectInput::vfunc_12 (38 B)
// [TODO] 0x006DDF90 core::ControllerDirectInput::vfunc_13 (7 B)
// [TODO] 0x006DDFA0 core::ControllerDirectInput::vfunc_17 (38 B)
// [TODO] 0x006DDFD0 core::ControllerDirectInput::vfunc_00 (8 B)
// [TODO] 0x006DDFE0 core::ControllerDirectInput::vfunc_04 (22 B)
// [TODO] 0x006DE000 core::ControllerDirectInput::vfunc_07 (21 B)
// [TODO] 0x006DE020 core::ControllerDirectInput::vfunc_21 (74 B)
// [TODO] 0x006DE070 core::ControllerDirectInput::vfunc_19 (256 B)
// [TODO] 0x006DE170 core::ControllerDirectInput::vfunc_20 (94 B)
// ============================================================================
// [VERIFIED] core::ControllerDirectInput::vfunc_03 (0x006DE1D0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::ControllerDirectInput::vfunc_03 (0x006DE1D0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);
extern "C" void __cdecl sub_006DE200(void);

namespace core {

class ControllerDirectInput
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ControllerDirectInput* vfunc_03(int a1);
};

ControllerDirectInput* ControllerDirectInput::vfunc_03(int a1)
{
    sub_006DE200();
    if (a1 & 1) {
        sub_006DC430(DAT_007F5A70, (int)this);
    }
    return this;
}

}

// [TODO] 0x006DE200 sub_006DE200 (272 B)
// [TODO] 0x006DE3C0 sub_006DE3C0 (393 B)
// [TODO] 0x006DE550 core::ControllerSystemDirectInput::vfunc_13 (55 B)
// [TODO] 0x006DE590 core::ControllerSystemDirectInput::vfunc_12 (19 B)
// [TODO] 0x006DE5B0 core::ControllerSystemDirectInput::vfunc_06 (103 B)
// [TODO] 0x006DE620 core::ControllerSystemDirectInput::vfunc_09 (44 B)
// [TODO] 0x006DE650 core::ControllerSystemDirectInput::vfunc_05 (38 B)
// [TODO] 0x006DE680 core::ControllerSystemDirectInput::vfunc_00 (8 B)
// ============================================================================
// [VERIFIED] core::ControllerSystemDirectInput::vfunc_03 (0x006DE690, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::ControllerSystemDirectInput::vfunc_03 (0x006DE690, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);
extern "C" void __cdecl sub_006DE6C0(void);

namespace core {

class ControllerSystemDirectInput
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ControllerSystemDirectInput* vfunc_03(int a1);
};

ControllerSystemDirectInput* ControllerSystemDirectInput::vfunc_03(int a1)
{
    sub_006DE6C0();
    if (a1 & 1) {
        sub_006DC430(DAT_007F5A70, (int)this);
    }
    return this;
}

}

// [TODO] 0x006DE6C0 sub_006DE6C0 (140 B)
// [TODO] 0x006DE7A0 sub_006DE7A0 (123 B)
// [TODO] 0x006DE900 sub_006DE900 (43 B)
// [TODO] 0x006DE930 sub_006DE930 (43 B)
// [TODO] 0x006DEBB0 sub_006DEBB0 (35 B)
// [TODO] 0x006DEBE0 sub_006DEBE0 (20 B)
// ============================================================================
// [VERIFIED] sub_006DEC00 (0x006DEC00, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006DEC00 (0x006DEC00, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0041135C(void);

class Class_006DEC00
{
public:
    void sub_006DEC00();
};

void Class_006DEC00::sub_006DEC00()
{
    sub_0041135C();
}

// [TODO] 0x006DEC30 sub_006DEC30 (84 B)
// [TODO] 0x006DEC90 sub_006DEC90 (24 B)
// [TODO] 0x006DECB0 sub_006DECB0 (118 B)
// ============================================================================
// [VERIFIED] sub_006DED30 (0x006DED30, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006DED30 (0x006DED30, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00FB0BD8;

class Class_006DED30
{
public:
    void sub_006DED30();
};

void Class_006DED30::sub_006DED30()
{
    ((void (__cdecl*)(void))DAT_00FB0BD8)();
}

// ============================================================================
// [VERIFIED] sub_006DEDF0 (0x006DEDF0, 1 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// sub_006DEDF0 (PC 0x006DEDF0, 1 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

void __cdecl sub_006DEDF0(void)
{
}

// [TODO] 0x006DEF50 sub_006DEF50 (74 B)
// ============================================================================
// [VERIFIED] sub_006DEFA0 (0x006DEFA0, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00283B60 (0x00283B60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006DEFA0 (0x006DEFA0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F0D8;

void __cdecl sub_006DEFA0(int a1)
{
    ((void (__stdcall*)(int))DAT_0072F0D8)(a1);
}

// [TODO] 0x006DEFE0 sub_006DEFE0 (34 B)
// [TODO] 0x006DF010 sub_006DF010 (59 B)
// ============================================================================
// [VERIFIED] sub_006DF050 (0x006DF050, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00283B60 (0x00283B60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006DF050 (0x006DF050, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F0A0;

void __cdecl sub_006DF050(int a1)
{
    ((void (__stdcall*)(int))DAT_0072F0A0)(a1);
}

// ============================================================================
// [VERIFIED] sub_006DF060 (0x006DF060, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00283B60 (0x00283B60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006DF060 (0x006DF060, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F09C;

void __cdecl sub_006DF060(int a1)
{
    ((void (__stdcall*)(int))DAT_0072F09C)(a1);
}

// ============================================================================
// [VERIFIED] sub_006DF070 (0x006DF070, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00283B60 (0x00283B60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006DF070 (0x006DF070, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F098;

void __cdecl sub_006DF070(int a1)
{
    ((void (__stdcall*)(int))DAT_0072F098)(a1);
}

// ============================================================================
// [VERIFIED] sub_006DF080 (0x006DF080, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00283B60 (0x00283B60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006DF080 (0x006DF080, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F094;

void __cdecl sub_006DF080(int a1)
{
    ((void (__stdcall*)(int))DAT_0072F094)(a1);
}

// [TODO] 0x006DF090 sub_006DF090 (11 B)
// [TODO] 0x006DF0B0 sub_006DF0B0 (14 B)
// [TODO] 0x006DF0C0 sub_006DF0C0 (16 B)
// [TODO] 0x006DF0D0 sub_006DF0D0 (18 B)
// [TODO] 0x006DF0F0 sub_006DF0F0 (78 B)
// [TODO] 0x006DF140 sub_006DF140 (80 B)
// [TODO] 0x006DF220 sub_006DF220 (129 B)
// [TODO] 0x006DF2B0 sub_006DF2B0 (34 B)
// [TODO] 0x006DF310 sub_006DF310 (141 B)
// [TODO] 0x006DF3A0 sub_006DF3A0 (7 B)
// [TODO] 0x006DF3E0 sub_006DF3E0 (14 B)
// [TODO] 0x006DF3F0 sub_006DF3F0 (23 B)
// [TODO] 0x006DF430 sub_006DF430 (81 B)
// ============================================================================
// [VERIFIED] sub_006DF490 (0x006DF490, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006DF490 (0x006DF490, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085AEF4;

int __cdecl sub_006DF490(void)
{
    return DAT_0085AEF4;
}

// [TODO] 0x006DF4A0 LoadSet::vfunc_00 (5 B)
// [TODO] 0x006DF4B0 core::Platform::vfunc_01 (5 B)
// [TODO] 0x006DF4C0 core::Platform::vfunc_04 (24 B)
// [TODO] 0x006DF4E0 core::Platform::vfunc_07 (68 B)
// [TODO] 0x006DF590 core::Platform::vfunc_06 (50 B)
// [TODO] 0x006DF650 sub_006DF650 (16008 B)
// [TODO] 0x006DF6B0 sub_006DF6B0 (33 B)
// [TODO] 0x006DF6E0 sub_006DF6E0 (34 B)
// [TODO] 0x006DF710 core::MemorySpaceAsyncRequest_Copy::vfunc_01 (5 B)
// [TODO] 0x006DF720 UpperBodyAnimStateCondition::vfunc_13 (5 B)
// [TODO] 0x006DF730 core::MemoryAllocatorMalloc::vfunc_04 (26 B)
// [TODO] 0x006DF750 core::MemoryAllocatorMalloc::vfunc_05 (15 B)
// [TODO] 0x006DF760 core::MemoryAllocatorMalloc::vfunc_07 (21 B)
// [TODO] 0x006DF780 sub_006DF780 (55 B)
// [TODO] 0x006DF7C0 core::MemoryAllocatorMalloc::vfunc_08 (22 B)
// [TODO] 0x006DF7E0 pure3d::pddiDisplay::vfunc_09 (5 B)
// ============================================================================
// [VERIFIED] core::MemoryAllocatorMalloc::vfunc_12 (0x006DF7F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::MemoryAllocatorMalloc::vfunc_12 (0x0028D100), which was matched first;
// its addresses and names were swapped for this function's.
// core::MemoryAllocatorMalloc::vfunc_12 (0x006DF7F0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085AF08;

namespace core {

class MemoryAllocatorMalloc
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual int vfunc_12();
};

int MemoryAllocatorMalloc::vfunc_12()
{
    return DAT_0085AF08;
}

}

// ============================================================================
// [VERIFIED] sub_006DF960 (0x006DF960, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006DF960 (0x006DF960, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085CD34;

int __cdecl sub_006DF960(void)
{
    return DAT_0085CD34;
}

// ============================================================================
// [VERIFIED] sub_006DF970 (0x006DF970, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006DF970 (0x006DF970, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0042C0C6(void);

class Class_006DF970
{
public:
    void sub_006DF970();
};

void Class_006DF970::sub_006DF970()
{
    sub_0042C0C6();
}

// [TODO] 0x006DF9E0 sub_006DF9E0 (191 B)
// [TODO] 0x006DFAA0 sub_006DFAA0 (8 B)
// [TODO] 0x006DFB40 sub_006DFB40 (370 B)
// [TODO] 0x006DFD00 sub_006DFD00 (322 B)
// [TODO] 0x006DFFC0 sub_006DFFC0 (74 B)
// [TODO] 0x006E0010 GameMemorySegmentCollection::vfunc_00 (5 B)
// [TODO] 0x006E0020 core::String::vfunc_05 (110 B)
// [TODO] 0x006E0090 core::String::vfunc_04 (36 B)
// [TODO] 0x006E00C0 core::String::vfunc_24 (9 B)
// [TODO] 0x006E00D0 core::String::vfunc_23 (100 B)
// [TODO] 0x006E0140 core::String::vfunc_07 (160 B)
// [TODO] 0x006E01E0 core::String::vfunc_06 (34 B)
// [TODO] 0x006E0210 core::String::vfunc_09 (54 B)
// [TODO] 0x006E0250 core::String::vfunc_08 (17 B)
// [TODO] 0x006E0270 core::String::vfunc_10 (31 B)
// [TODO] 0x006E0290 core::String::vfunc_18 (30 B)
// [TODO] 0x006E02B0 core::String::vfunc_17 (293 B)
// [TODO] 0x006E03E0 core::String::vfunc_16 (5 B)
// [TODO] 0x006E03F0 core::String::vfunc_15 (55 B)
// [TODO] 0x006E0430 core::String::vfunc_14 (26 B)
// [TODO] 0x006E0450 core::String::vfunc_12 (54 B)
// [TODO] 0x006E0490 core::String::vfunc_11 (26 B)
// [TODO] 0x006E04B0 core::String::vfunc_19 (22 B)
// [TODO] 0x006E04D0 core::String::vfunc_20 (22 B)
// [TODO] 0x006E04F0 core::String::vfunc_22 (20 B)
// [TODO] 0x006E0510 core::String::vfunc_21 (36 B)
// ============================================================================
// [VERIFIED] core::String::vfunc_03 (0x006E0540, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::String::vfunc_03 (0x006E0540, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);
extern "C" void __cdecl sub_006E0570(void);

namespace core {

class String
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual String* vfunc_03(int a1);
};

String* String::vfunc_03(int a1)
{
    sub_006E0570();
    if (a1 & 1) {
        sub_006DC430(DAT_007F5A70, (int)this);
    }
    return this;
}

}

// [TODO] 0x006E0570 sub_006E0570 (67 B)
// [TODO] 0x006E05C0 core::String::vfunc_00 (8 B)
// [TODO] 0x006E05D0 sub_006E05D0 (47 B)
// [TODO] 0x006E0680 sub_006E0680 (241 B)
// [TODO] 0x006E0780 sub_006E0780 (60 B)
// [TODO] 0x006E07C0 sub_006E07C0 (19 B)
// [TODO] 0x006E0930 core::MemoryDlAllocator::vfunc_00 (5 B)
// [TODO] 0x006E0940 core::MemoryDlAllocator::vfunc_11 (159 B)
// [TODO] 0x006E09E0 core::MemoryDlAllocator::vfunc_06 (28 B)
// [TODO] 0x006E0A00 core::MemoryDlAllocator::vfunc_10 (86 B)
// ============================================================================
// [VERIFIED] core::MemoryDlAllocator::vfunc_03 (0x006E0A60, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::MemoryDlAllocator::vfunc_03 (0x006E0A60, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);
extern "C" void __cdecl sub_006E0A90(void);

namespace core {

class MemoryDlAllocator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual MemoryDlAllocator* vfunc_03(int a1);
};

MemoryDlAllocator* MemoryDlAllocator::vfunc_03(int a1)
{
    sub_006E0A90();
    if (a1 & 1) {
        sub_006DC430(DAT_007F5A70, (int)this);
    }
    return this;
}

}

// [TODO] 0x006E0A90 sub_006E0A90 (35 B)
// [TODO] 0x006E0AC0 core::MemoryDlAllocator::vfunc_00 (8 B)
// [TODO] 0x006E0AD0 sub_006E0AD0 (215 B)
// [TODO] 0x006E0BB0 core::MemoryDlAllocator::vfunc_05 (200 B)
// [TODO] 0x006E0C80 core::MemoryDlAllocator::vfunc_04 (133 B)
// [TODO] 0x006E0D10 sub_006E0D10 (42 B)
// [TODO] 0x006E0D40 sub_006E0D40 (9 B)
// [TODO] 0x006E11C0 sub_006E11C0 (493 B)
// [TODO] 0x006E13B0 core::MemoryDlAllocator::vfunc_07 (117 B)
// [TODO] 0x006E1430 sub_006E1430 (331 B)
// [TODO] 0x006E1580 sub_006E1580 (244 B)
// [TODO] 0x006E1680 sub_006E1680 (36 B)
// [TODO] 0x006E16B0 sub_006E16B0 (31 B)
// [TODO] 0x006E16D0 sub_006E16D0 (42 B)
// [TODO] 0x006E1700 sub_006E1700 (35 B)
// [TODO] 0x006E1730 sub_006E1730 (27 B)
// [TODO] 0x006E1750 sub_006E1750 (36 B)
// [TODO] 0x006E1780 sub_006E1780 (25 B)
// [TODO] 0x006E1820 sub_006E1820 (802 B)
// [TODO] 0x006E1B50 sub_006E1B50 (60 B)
// [TODO] 0x006E1B90 sub_006E1B90 (19 B)
// [TODO] 0x006E1CF0 core::MemoryDlAllocator::vfunc_02 (4 B)
// [TODO] 0x006E1D00 core::MemorySmallDlAllocator::vfunc_10 (61 B)
// ============================================================================
// [VERIFIED] core::MemorySmallDlAllocator::vfunc_03 (0x006E1D40, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::MemorySmallDlAllocator::vfunc_03 (0x006E1D40, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);
extern "C" void __cdecl sub_006E1D70(void);

namespace core {

class MemorySmallDlAllocator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual MemorySmallDlAllocator* vfunc_03(int a1);
};

MemorySmallDlAllocator* MemorySmallDlAllocator::vfunc_03(int a1)
{
    sub_006E1D70();
    if (a1 & 1) {
        sub_006DC430(DAT_007F5A70, (int)this);
    }
    return this;
}

}

// [TODO] 0x006E1D70 sub_006E1D70 (35 B)
// [TODO] 0x006E1DA0 core::MemorySmallDlAllocator::vfunc_00 (8 B)
// [TODO] 0x006E1DB0 core::MemoryDlAllocator::vfunc_01 (79 B)
// [TODO] 0x006E1E00 core::MemorySmallDlAllocator::vfunc_05 (229 B)
// [TODO] 0x006E1EF0 sub_006E1EF0 (724 B)
// [TODO] 0x006E21D0 core::MemorySmallDlAllocator::vfunc_04 (167 B)
// [TODO] 0x006E2280 sub_006E2280 (232 B)
// [TODO] 0x006E2370 sub_006E2370 (2613 B)
// [TODO] 0x006E2D92 sub_006E2D92 (3 B)
// [TODO] 0x006E2DB0 sub_006E2DB0 (673 B)
// [TODO] 0x006E3060 core::MemorySmallDlAllocator::vfunc_07 (151 B)
// [TODO] 0x006E3100 sub_006E3100 (482 B)
// [TODO] 0x006E32F0 sub_006E32F0 (244 B)
// [TODO] 0x006E3630 sub_006E3630 (50 B)
// [TODO] 0x006E3670 sub_006E3670 (6 B)
// [TODO] 0x006E36A0 core::CompletionEventRequest::vfunc_01 (18 B)
// ============================================================================
// [VERIFIED] core::CompletionEventRequest::vfunc_06 (0x006E36C0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CompletionEventRequest::vfunc_06 (0x002A98D0), which was matched first;
// its addresses and names were swapped for this function's.
// core::CompletionEventRequest::vfunc_06 (0x006E36C0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class CompletionEventRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06();
};

int CompletionEventRequest::vfunc_06()
{
    return 23;
}

}

// [TODO] 0x006E36D0 core::FileCompletionRequest::vfunc_07 (46 B)
// [TODO] 0x006E3700 core::FileCompletionRequest::vfunc_01 (18 B)
// [TODO] 0x006E3720 core::DriveCompletionRequest::vfunc_07 (46 B)
// [TODO] 0x006E3750 core::FileCompletionRequest::vfunc_03 (7 B)
// [TODO] 0x006E3760 core::DriveCompletionRequest::vfunc_06 (6 B)
// [TODO] 0x006E3770 core::FileRequest::vfunc_02 (15 B)
// [TODO] 0x006E3780 core::FileRequest::vfunc_04 (63 B)
// [TODO] 0x006E37C0 core::FileRequest::vfunc_05 (8 B)
// [TODO] 0x006E37D0 core::FileOpenRequest::vfunc_01 (561 B)
// [TODO] 0x006E3A10 core::FileOpenByKeyRequest::vfunc_01 (195 B)
// [TODO] 0x006E3AE0 core::SaveGameOpenRequest::vfunc_01 (127 B)
// [TODO] 0x006E3B60 core::FileCloseRequest::vfunc_01 (110 B)
// [TODO] 0x006E3BD0 core::FileCommitRequest::vfunc_01 (75 B)
// ============================================================================
// [VERIFIED] fight::ParamString<UpperBodyAnimStateCondition>::vfunc_01 (0x006E3C20, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as fight::ParamString<TimedCharacterFightTrack>::vfunc_01 (0x00022A00), which was matched first;
// its addresses and names were swapped for this function's.
// fight::ParamString<UpperBodyAnimStateCondition>::vfunc_01 (0x006E3C20, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class UpperBodyAnimStateCondition;

namespace fight { 
template <class T0> class ParamString
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int fight::ParamString<UpperBodyAnimStateCondition>::vfunc_01()
{
    return 3;
}

// [TODO] 0x006E3C30 core::FileReadRequest::vfunc_01 (266 B)
// [TODO] 0x006E3D40 core::FileWriteRequest::vfunc_01 (144 B)
// [TODO] 0x006E3DD0 fight::ParamEnumConstList<DirectionalGetHitCondition>::vfunc_01 (6 B)
// [TODO] 0x006E3DE0 core::FileSetPositionRequest::vfunc_01 (55 B)
// [TODO] 0x006E3E20 core::FileGetPositionRequest::vfunc_01 (56 B)
// [TODO] 0x006E3E60 core::FileGetPositionRequest::vfunc_06 (6 B)
// [TODO] 0x006E3E70 core::FileGetSizeRequest::vfunc_01 (56 B)
// [TODO] 0x006E3EB0 DealerSpawnObject::vfunc_45 (6 B)
// [TODO] 0x006E3EC0 core::FileCancelRequest::vfunc_01 (59 B)
// [TODO] 0x006E3F00 fight::ParamBranch<ExitConditionTrack>::vfunc_01 (6 B)
// [TODO] 0x006E3F10 core::FileRequest::vfunc_03 (7 B)
// [TODO] 0x006E3F20 core::DriveRequest::vfunc_04 (63 B)
// [TODO] 0x006E3F60 core::DriveOpenRequest::vfunc_06 (6 B)
// [TODO] 0x006E3F70 core::DriveMediaRequest::vfunc_01 (78 B)
// [TODO] 0x006E3FC0 core::DriveMediaRequest::vfunc_06 (6 B)
// [TODO] 0x006E3FD0 core::DriveFormatRequest::vfunc_01 (63 B)
// [TODO] 0x006E4010 GlanceAtOvertakingPed::vfunc_10 (6 B)
// [TODO] 0x006E4020 core::DriveCreateDirectoryRequest::vfunc_01 (68 B)
// [TODO] 0x006E4070 core::DriveCreateDirectoryRequest::vfunc_06 (6 B)
// [TODO] 0x006E4080 core::DriveDestroyDirectoryRequest::vfunc_01 (68 B)
// [TODO] 0x006E40D0 core::DriveDestroyDirectoryRequest::vfunc_06 (6 B)
// [TODO] 0x006E40E0 core::DriveFindFirstRequest::vfunc_01 (110 B)
// [TODO] 0x006E4150 GangSpawnObject::vfunc_45 (6 B)
// [TODO] 0x006E4160 core::DriveFindNextRequest::vfunc_01 (72 B)
// ============================================================================
// [VERIFIED] core::DriveFindNextRequest::vfunc_06 (0x006E41B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::DriveFindNextRequest::vfunc_06 (0x0006F9A0), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveFindNextRequest::vfunc_06 (0x006E41B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class DriveFindNextRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06();
};

int DriveFindNextRequest::vfunc_06()
{
    return 17;
}

}

// [TODO] 0x006E41C0 core::DriveFindCloseRequest::vfunc_01 (64 B)
// [TODO] 0x006E4200 core::DriveFindCloseRequest::vfunc_06 (6 B)
// [TODO] 0x006E4210 core::DriveFileDestroyRequest::vfunc_01 (68 B)
// [TODO] 0x006E4260 pure3d::d3dContext::vfunc_22 (4 B)
// [TODO] 0x006E4270 core::DriveFileDestroyRequest::vfunc_06 (6 B)
// [TODO] 0x006E4280 core::DriveCancelRequest::vfunc_01 (59 B)
// [TODO] 0x006E42C0 core::DriveCancelRequest::vfunc_06 (6 B)
// [TODO] 0x006E42D0 core::DriveLockRequest::vfunc_06 (6 B)
// [TODO] 0x006E42E0 core::DriveLockRequest::vfunc_01 (73 B)
// [TODO] 0x006E4330 sub_006E4330 (77 B)
// [TODO] 0x006E4380 core::Request::vfunc_00 (60 B)
// [TODO] 0x006E43C0 sub_006E43C0 (59 B)
// [TODO] 0x006E4400 core::CompletionEventRequest::vfunc_00 (74 B)
// [TODO] 0x006E4450 sub_006E4450 (120 B)
// ============================================================================
// [VERIFIED] core::FileCompletionRequest::vfunc_00 (0x006E44D0, 82 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::FileCompletionRequest::vfunc_00 (0x002AA6D0), which was matched first;
// its addresses and names were swapped for this function's.
// core::FileCompletionRequest::vfunc_00 (0x006E44D0, 82 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
};

extern "C" char DAT_00771C98[];
extern "C" char DAT_00771CD8[];
extern "C" char DAT_0085CDDC[];
extern "C" int DAT_0085CDF4;
extern "C" void __cdecl sub_006DF070(int);
extern "C" void __cdecl sub_006DF080(int);

namespace core {

class FileCompletionRequest
{
public:
    virtual FileCompletionRequest* vfunc_00(int a1);
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

FileCompletionRequest* FileCompletionRequest::vfunc_00(int a1)
{
    int t1;

    t1 = m_Field10;
    *(int*)this = (int)DAT_00771CD8;
    ((Object*)t1)->vfunc_01();
    m_Field0C->vfunc_01();
    *(int*)this = (int)DAT_00771C98;
    if (a1 & 1) {
        sub_006DF080((int)DAT_0085CDDC);
        ((Object*)DAT_0085CDF4)->vfunc_05((int)this);
        sub_006DF070((int)DAT_0085CDDC);
    }
    return this;
}

}

// [TODO] 0x006E4530 sub_006E4530 (120 B)
// ============================================================================
// [VERIFIED] core::DriveCompletionRequest::vfunc_00 (0x006E45B0, 82 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::FileCompletionRequest::vfunc_00 (0x002AA6D0), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveCompletionRequest::vfunc_00 (0x006E45B0, 82 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
};

extern "C" char DAT_00771C98[];
extern "C" char DAT_00771CFC[];
extern "C" char DAT_0085CDDC[];
extern "C" int DAT_0085CDF4;
extern "C" void __cdecl sub_006DF070(int);
extern "C" void __cdecl sub_006DF080(int);

namespace core {

class DriveCompletionRequest
{
public:
    virtual DriveCompletionRequest* vfunc_00(int a1);
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

DriveCompletionRequest* DriveCompletionRequest::vfunc_00(int a1)
{
    int t1;

    t1 = m_Field10;
    *(int*)this = (int)DAT_00771CFC;
    ((Object*)t1)->vfunc_01();
    m_Field0C->vfunc_01();
    *(int*)this = (int)DAT_00771C98;
    if (a1 & 1) {
        sub_006DF080((int)DAT_0085CDDC);
        ((Object*)DAT_0085CDF4)->vfunc_05((int)this);
        sub_006DF070((int)DAT_0085CDDC);
    }
    return this;
}

}

// [TODO] 0x006E4610 sub_006E4610 (9 B)
// [TODO] 0x006E4670 sub_006E4670 (44 B)
// ============================================================================
// [VERIFIED] sub_006E46A0 (0x006E46A0, 51 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA890 (0x002AA890), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E46A0 (0x006E46A0, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    virtual void vfunc_00();
};

struct Object
{
    void sub_006DEC00();
};

extern "C" char DAT_00771D40[];
extern "C" void __stdcall sub_006E4610(int);

class Class_006E46A0
{
public:
    Class_006E46A0* sub_006E46A0(int a1, int a2, int a3);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    Field10* m_Field10; // +0x10
};

Class_006E46A0* Class_006E46A0::sub_006E46A0(int a1, int a2, int a3)
{
    sub_006E4610(a1);
    m_Field00 = (int)DAT_00771D40;
    m_Field0C = a2;
    m_Field10 = (Field10*)a3;
    ((Object*)a2)->sub_006DEC00();
    m_Field10->vfunc_00();
    return this;
}

// [TODO] 0x006E46E0 core::FileOpenByKeyRequest::vfunc_00 (116 B)
// [TODO] 0x006E4760 sub_006E4760 (58 B)
// ============================================================================
// [VERIFIED] sub_006E47A0 (0x006E47A0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA990 (0x002AA990), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E47A0 (0x006E47A0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00771DE4[];
extern "C" void __cdecl sub_006DEC00(void);
extern "C" void __stdcall sub_006E4610(int);

class Class_006E47A0
{
public:
    Class_006E47A0* sub_006E47A0(int a1);
    int m_Field00; // +0x00
};

Class_006E47A0* Class_006E47A0::sub_006E47A0(int a1)
{
    sub_006E4610(a1);
    m_Field00 = (int)DAT_00771DE4;
    sub_006DEC00();
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E47C0 (0x006E47C0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA990 (0x002AA990), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E47C0 (0x006E47C0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00771E04[];
extern "C" void __cdecl sub_006DEC00(void);
extern "C" void __stdcall sub_006E4610(int);

class Class_006E47C0
{
public:
    Class_006E47C0* sub_006E47C0(int a1);
    int m_Field00; // +0x00
};

Class_006E47C0* Class_006E47C0::sub_006E47C0(int a1)
{
    sub_006E4610(a1);
    m_Field00 = (int)DAT_00771E04;
    sub_006DEC00();
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E47E0 (0x006E47E0, 51 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA9D0 (0x002AA9D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E47E0 (0x006E47E0, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006DEC00();
};

extern "C" char DAT_00771E24[];
extern "C" void __stdcall sub_006E4610(int);

class Class_006E47E0
{
public:
    Class_006E47E0* sub_006E47E0(int a1, int a2, int a3, int a4);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

Class_006E47E0* Class_006E47E0::sub_006E47E0(int a1, int a2, int a3, int a4)
{
    sub_006E4610(a1);
    m_Field00 = (int)DAT_00771E24;
    m_Field0C = a2;
    m_Field10 = a3;
    m_Field14 = a4;
    ((Object*)a2)->sub_006DEC00();
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E4820 (0x006E4820, 51 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA9D0 (0x002AA9D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E4820 (0x006E4820, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006DEC00();
};

extern "C" char DAT_00771E44[];
extern "C" void __stdcall sub_006E4610(int);

class Class_006E4820
{
public:
    Class_006E4820* sub_006E4820(int a1, int a2, int a3, int a4);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

Class_006E4820* Class_006E4820::sub_006E4820(int a1, int a2, int a3, int a4)
{
    sub_006E4610(a1);
    m_Field00 = (int)DAT_00771E44;
    m_Field0C = a2;
    m_Field10 = a3;
    m_Field14 = a4;
    ((Object*)a2)->sub_006DEC00();
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E4860 (0x006E4860, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AAA50 (0x002AAA50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E4860 (0x006E4860, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006DEC00();
};

extern "C" char DAT_00771E64[];
extern "C" void __stdcall sub_006E4610(int);

class Class_006E4860
{
public:
    Class_006E4860* sub_006E4860(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

Class_006E4860* Class_006E4860::sub_006E4860(int a1, int a2)
{
    sub_006E4610(a1);
    m_Field00 = (int)DAT_00771E64;
    m_Field0C = a2;
    ((Object*)a2)->sub_006DEC00();
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E4890 (0x006E4890, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AAA50 (0x002AAA50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E4890 (0x006E4890, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006DEC00();
};

extern "C" char DAT_00771E84[];
extern "C" void __stdcall sub_006E4610(int);

class Class_006E4890
{
public:
    Class_006E4890* sub_006E4890(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

Class_006E4890* Class_006E4890::sub_006E4890(int a1, int a2)
{
    sub_006E4610(a1);
    m_Field00 = (int)DAT_00771E84;
    m_Field0C = a2;
    ((Object*)a2)->sub_006DEC00();
    return this;
}

// [TODO] 0x006E48C0 core::FileRequest::vfunc_00 (103 B)
// ============================================================================
// [VERIFIED] sub_006E4930 (0x006E4930, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AAA50 (0x002AAA50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E4930 (0x006E4930, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006DEC00();
};

extern "C" char DAT_00771EA4[];
extern "C" void __stdcall sub_006E4610(int);

class Class_006E4930
{
public:
    Class_006E4930* sub_006E4930(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

Class_006E4930* Class_006E4930::sub_006E4930(int a1, int a2)
{
    sub_006E4610(a1);
    m_Field00 = (int)DAT_00771EA4;
    m_Field0C = a2;
    ((Object*)a2)->sub_006DEC00();
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E4960 (0x006E4960, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA990 (0x002AA990), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E4960 (0x006E4960, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00771EC4[];
extern "C" void __cdecl sub_006DEC00(void);
extern "C" void __stdcall sub_006E4610(int);

class Class_006E4960
{
public:
    Class_006E4960* sub_006E4960(int a1);
    int m_Field00; // +0x00
};

Class_006E4960* Class_006E4960::sub_006E4960(int a1)
{
    sub_006E4610(a1);
    m_Field00 = (int)DAT_00771EC4;
    sub_006DEC00();
    return this;
}

// [TODO] 0x006E4980 sub_006E4980 (9 B)
// ============================================================================
// [VERIFIED] sub_006E49E0 (0x006E49E0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA990 (0x002AA990), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E49E0 (0x006E49E0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00771EE4[];
extern "C" void __cdecl sub_006DEC00(void);
extern "C" void __stdcall sub_006E4980(int);

class Class_006E49E0
{
public:
    Class_006E49E0* sub_006E49E0(int a1);
    int m_Field00; // +0x00
};

Class_006E49E0* Class_006E49E0::sub_006E49E0(int a1)
{
    sub_006E4980(a1);
    m_Field00 = (int)DAT_00771EE4;
    sub_006DEC00();
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E4A00 (0x006E4A00, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AAA50 (0x002AAA50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E4A00 (0x006E4A00, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006DEC00();
};

extern "C" char DAT_00771F04[];
extern "C" void __stdcall sub_006E4980(int);

class Class_006E4A00
{
public:
    Class_006E4A00* sub_006E4A00(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

Class_006E4A00* Class_006E4A00::sub_006E4A00(int a1, int a2)
{
    sub_006E4980(a1);
    m_Field00 = (int)DAT_00771F04;
    m_Field0C = a2;
    ((Object*)a2)->sub_006DEC00();
    return this;
}

// [TODO] 0x006E4A30 core::DriveRequest::vfunc_00 (103 B)
// ============================================================================
// [VERIFIED] sub_006E4AA0 (0x006E4AA0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA990 (0x002AA990), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E4AA0 (0x006E4AA0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00771F24[];
extern "C" void __cdecl sub_006DEC00(void);
extern "C" void __stdcall sub_006E4980(int);

class Class_006E4AA0
{
public:
    Class_006E4AA0* sub_006E4AA0(int a1);
    int m_Field00; // +0x00
};

Class_006E4AA0* Class_006E4AA0::sub_006E4AA0(int a1)
{
    sub_006E4980(a1);
    m_Field00 = (int)DAT_00771F24;
    sub_006DEC00();
    return this;
}

// [TODO] 0x006E4AC0 sub_006E4AC0 (54 B)
// [TODO] 0x006E4B00 sub_006E4B00 (54 B)
// [TODO] 0x006E4B40 sub_006E4B40 (70 B)
// ============================================================================
// [VERIFIED] sub_006E4B90 (0x006E4B90, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AAA50 (0x002AAA50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E4B90 (0x006E4B90, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006DEC00();
};

extern "C" char DAT_00771FA4[];
extern "C" void __stdcall sub_006E4980(int);

class Class_006E4B90
{
public:
    Class_006E4B90* sub_006E4B90(int a1, int a2);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

Class_006E4B90* Class_006E4B90::sub_006E4B90(int a1, int a2)
{
    sub_006E4980(a1);
    m_Field00 = (int)DAT_00771FA4;
    m_Field0C = a2;
    ((Object*)a2)->sub_006DEC00();
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E4BC0 (0x006E4BC0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA990 (0x002AA990), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E4BC0 (0x006E4BC0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00771FC4[];
extern "C" void __cdecl sub_006DEC00(void);
extern "C" void __stdcall sub_006E4980(int);

class Class_006E4BC0
{
public:
    Class_006E4BC0* sub_006E4BC0(int a1);
    int m_Field00; // +0x00
};

Class_006E4BC0* Class_006E4BC0::sub_006E4BC0(int a1)
{
    sub_006E4980(a1);
    m_Field00 = (int)DAT_00771FC4;
    sub_006DEC00();
    return this;
}

// [TODO] 0x006E4BE0 sub_006E4BE0 (60 B)
// ============================================================================
// [VERIFIED] sub_006E4C20 (0x006E4C20, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AA990 (0x002AA990), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E4C20 (0x006E4C20, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772004[];
extern "C" void __cdecl sub_006DEC00(void);
extern "C" void __stdcall sub_006E4980(int);

class Class_006E4C20
{
public:
    Class_006E4C20* sub_006E4C20(int a1);
    int m_Field00; // +0x00
};

Class_006E4C20* Class_006E4C20::sub_006E4C20(int a1)
{
    sub_006E4980(a1);
    m_Field00 = (int)DAT_00772004;
    sub_006DEC00();
    return this;
}

// ============================================================================
// [VERIFIED] sub_006E4C40 (0x006E4C40, 51 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002AAE20 (0x002AAE20), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E4C40 (0x006E4C40, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006DEC00();
};

extern "C" char DAT_00772024[];
extern "C" void __stdcall sub_006E4980(int);

class Class_006E4C40
{
public:
    Class_006E4C40* sub_006E4C40(int a1, int a2, int a3);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    char m_pad14[0x4];
    int m_Field18; // +0x18
};

Class_006E4C40* Class_006E4C40::sub_006E4C40(int a1, int a2, int a3)
{
    sub_006E4980(a1);
    m_Field00 = (int)DAT_00772024;
    m_Field0C = a2;
    m_Field10 = a3;
    m_Field18 = 0;
    ((Object*)a2)->sub_006DEC00();
    return this;
}

// [TODO] 0x006E4C80 sub_006E4C80 (50 B)
// [TODO] 0x006E4CC0 sub_006E4CC0 (6 B)
// [TODO] 0x006E4CF0 core::File::vfunc_01 (119 B)
// ============================================================================
// [VERIFIED] core::File::vfunc_00 (0x006E4D70, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_00 (0x002AAF50), which was matched first;
// its addresses and names were swapped for this function's.
// core::File::vfunc_00 (0x006E4D70, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0085CDF8[];
extern "C" void __cdecl sub_006DF080(int);

namespace core {

class File
{
public:
    virtual void vfunc_00();
};

void File::vfunc_00()
{
    sub_006DF080((int)DAT_0085CDF8);
}

}

// ============================================================================
// [VERIFIED] core::File::vfunc_01 (0x006E4D80, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_00 (0x002AAF50), which was matched first;
// its addresses and names were swapped for this function's.
// core::File::vfunc_01 (0x006E4D80, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0085CDF8[];
extern "C" void __cdecl sub_006DF070(int);

namespace core {

class File
{
public:
    virtual void vfunc_01();
};

void File::vfunc_01()
{
    sub_006DF070((int)DAT_0085CDF8);
}

}

// [TODO] 0x006E4D90 core::File::vfunc_09 (60 B)
// [TODO] 0x006E4DD0 core::File::vfunc_04 (79 B)
// [TODO] 0x006E4E20 core::File::vfunc_05 (79 B)
// [TODO] 0x006E4E70 core::File::vfunc_06 (69 B)
// [TODO] 0x006E4EC0 core::File::vfunc_07 (69 B)
// [TODO] 0x006E4F10 core::File::vfunc_08 (69 B)
// [TODO] 0x006E4F60 core::File::vfunc_10 (36 B)
// [TODO] 0x006E4F90 core::File::vfunc_11 (36 B)
// [TODO] 0x006E4FC0 core::File::vfunc_12 (26 B)
// [TODO] 0x006E4FE0 core::File::vfunc_13 (26 B)
// [TODO] 0x006E5000 core::File::vfunc_14 (26 B)
// [TODO] 0x006E5020 core::File::vfunc_15 (16 B)
// [TODO] 0x006E5030 core::File::vfunc_16 (7 B)
// [TODO] 0x006E5040 core::File::vfunc_18 (61 B)
// [TODO] 0x006E5080 core::File::vfunc_19 (85 B)
// [TODO] 0x006E50E0 core::File::vfunc_21 (35 B)
// [TODO] 0x006E5110 core::File::vfunc_22 (47 B)
// [TODO] 0x006E5140 core::File::vfunc_23 (29 B)
// [TODO] 0x006E5160 core::File::vfunc_25 (24 B)
// [TODO] 0x006E5180 core::File::vfunc_26 (4 B)
// [TODO] 0x006E5190 core::File::vfunc_27 (8 B)
// [TODO] 0x006E51A0 core::File::vfunc_30 (7 B)
// [TODO] 0x006E51B0 core::File::vfunc_17 (6 B)
// [TODO] 0x006E51C0 core::File::vfunc_31 (13 B)
// [TODO] 0x006E51D0 core::File::vfunc_32 (7 B)
// [TODO] 0x006E51E0 core::File::vfunc_33 (7 B)
// [TODO] 0x006E51F0 core::File::vfunc_03 (92 B)
// [TODO] 0x006E5250 sub_006E5250 (248 B)
// [TODO] 0x006E5350 sub_006E5350 (23 B)
// [TODO] 0x006E5450 sub_006E5450 (47 B)
// ============================================================================
// [VERIFIED] sub_006E5480 (0x006E5480, 44 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002A9880 (0x002A9880), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E5480 (0x006E5480, 44 bytes)
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
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual int vfunc_16();
};

extern "C" char DAT_0085CE14[];
extern "C" int DAT_0085CE2C;
extern "C" void __cdecl sub_006DF070(int);
extern "C" void __cdecl sub_006DF080(int);

int __cdecl sub_006E5480(void)
{
    int t3;

    sub_006DF080((int)DAT_0085CE14);
    t3 = ((Object*)DAT_0085CE2C)->vfunc_16();
    sub_006DF070((int)DAT_0085CE14);
    return t3;
}

// [TODO] 0x006E54B0 core::File::vfunc_00 (27 B)
// [TODO] 0x006E54D0 core::InstanceDrive::vfunc_01 (123 B)
// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_00 (0x006E5550, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_00 (0x002AAF50), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_00 (0x006E5550, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0085CE14[];
extern "C" void __cdecl sub_006DF080(int);

namespace core {

class InstanceDrive
{
public:
    virtual void vfunc_00();
};

void InstanceDrive::vfunc_00()
{
    sub_006DF080((int)DAT_0085CE14);
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_01 (0x006E5560, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::File::vfunc_00 (0x002AAF50), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_01 (0x006E5560, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0085CE14[];
extern "C" void __cdecl sub_006DF070(int);

namespace core {

class InstanceDrive
{
public:
    virtual void vfunc_01();
};

void InstanceDrive::vfunc_01()
{
    sub_006DF070((int)DAT_0085CE14);
}

}

// [TODO] 0x006E5570 core::InstanceDrive::vfunc_04 (8 B)
// [TODO] 0x006E5580 core::InstanceDrive::vfunc_05 (69 B)
// [TODO] 0x006E55D0 core::InstanceDrive::vfunc_06 (60 B)
// [TODO] 0x006E5610 core::InstanceDrive::vfunc_07 (135 B)
// [TODO] 0x006E56A0 core::InstanceDrive::vfunc_08 (135 B)
// [TODO] 0x006E5730 core::InstanceDrive::vfunc_09 (146 B)
// [TODO] 0x006E57D0 core::InstanceDrive::vfunc_10 (69 B)
// [TODO] 0x006E5820 core::InstanceDrive::vfunc_11 (138 B)
// [TODO] 0x006E58B0 core::InstanceDrive::vfunc_12 (26 B)
// [TODO] 0x006E58D0 core::InstanceDrive::vfunc_13 (16 B)
// [TODO] 0x006E58E0 core::InstanceDrive::vfunc_14 (26 B)
// [TODO] 0x006E5900 core::InstanceDrive::vfunc_15 (26 B)
// [TODO] 0x006E5920 core::InstanceDrive::vfunc_16 (31 B)
// [TODO] 0x006E5940 core::InstanceDrive::vfunc_17 (26 B)
// [TODO] 0x006E5960 core::InstanceDrive::vfunc_18 (26 B)
// [TODO] 0x006E5980 core::InstanceDrive::vfunc_19 (61 B)
// [TODO] 0x006E59C0 core::InstanceDrive::vfunc_20 (85 B)
// [TODO] 0x006E5A20 core::File::vfunc_20 (72 B)
// [TODO] 0x006E5A70 core::InstanceDrive::vfunc_22 (35 B)
// [TODO] 0x006E5AA0 core::InstanceDrive::vfunc_23 (47 B)
// [TODO] 0x006E5AD0 core::InstanceDrive::vfunc_24 (63 B)
// [TODO] 0x006E5B10 core::InstanceDrive::vfunc_25 (1671 B)
// [TODO] 0x006E5B20 core::InstanceDrive::vfunc_26 (1701 B)
// [TODO] 0x006E5B30 core::InstanceDrive::vfunc_27 (1736 B)
// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_29 (0x006E5B40, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_29 (0x006E5B40, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E6290();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_29()
{
    m_Field0C->sub_006E6290();
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_30 (0x006E5B50, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_30 (0x006E5B50, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E6250();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_30();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_30()
{
    m_Field0C->sub_006E6250();
}

}

// [TODO] 0x006E5B60 core::InstanceDrive::vfunc_31 (1729 B)
// [TODO] 0x006E5B70 core::InstanceDrive::vfunc_32 (2026 B)
// [TODO] 0x006E5B80 core::InstanceDrive::vfunc_33 (1987 B)
// [TODO] 0x006E5B90 core::InstanceDrive::vfunc_34 (203 B)
// [TODO] 0x006E5C60 core::InstanceDrive::vfunc_35 (64 B)
// [TODO] 0x006E5CA0 core::InstanceDrive::vfunc_36 (193 B)
// [TODO] 0x006E5D70 core::InstanceDrive::vfunc_37 (59 B)
// [TODO] 0x006E5DB0 core::InstanceDrive::vfunc_41 (1525 B)
// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_40 (0x006E5DC0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_40 (0x006E5DC0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E63B0();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_40();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_40()
{
    m_Field0C->sub_006E63B0();
}

}

// [TODO] 0x006E5DD0 core::InstanceDrive::vfunc_43 (1541 B)
// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_42 (0x006E5DE0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_29 (0x002ABD60), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_42 (0x006E5DE0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E63E0();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_42();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void InstanceDrive::vfunc_42()
{
    m_Field0C->sub_006E63E0();
}

}

// [TODO] 0x006E5DF0 core::InstanceDrive::vfunc_44 (9105 B)
// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_45 (0x006E5E00, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_45 (0x002AC020), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_45 (0x006E5E00, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_006E6370(int, int, int);
};

struct Object
{
    int sub_006E4C40(int, int, int);
};

extern "C" int __cdecl sub_006E3670(int);

namespace core {

class InstanceDrive
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual int vfunc_45(int a1, int a2, int a3);
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

int InstanceDrive::vfunc_45(int a1, int a2, int a3)
{
    int r_esi, t1;

    t1 = sub_006E3670(28);
    if (t1) {
        r_esi = ((Object*)t1)->sub_006E4C40((int)this, a1, a2);
    } else {
        r_esi = 0;
    }
    m_Field0C->sub_006E6370(r_esi, a3, 0);
    return r_esi;
}

}

// ============================================================================
// [VERIFIED] core::InstanceDrive::vfunc_46 (0x006E5E50, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::InstanceDrive::vfunc_46 (0x002AC070), which was matched first;
// its addresses and names were swapped for this function's.
// core::InstanceDrive::vfunc_46 (0x006E5E50, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006E4330();
};

namespace core {

class InstanceDrive
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46(int a1);
};

void InstanceDrive::vfunc_46(int a1)
{
    ((Object*)a1)->sub_006E4330();
}

}

// [TODO] 0x006E5E60 core::InstanceDrive::vfunc_48 (8 B)
// [TODO] 0x006E5E70 fight::SequenceAction::vfunc_04 (8 B)
// [TODO] 0x006E5E80 core::InstanceDrive::vfunc_03 (81 B)
// [TODO] 0x006E5EE0 sub_006E5EE0 (114 B)
// [TODO] 0x006E5F60 sub_006E5F60 (66 B)
// [TODO] 0x006E5FB0 sub_006E5FB0 (67 B)
// [TODO] 0x006E6000 sub_006E6000 (38 B)
// [TODO] 0x006E6070 core::Drive::vfunc_00 (23 B)
// [TODO] 0x006E60C0 sub_006E60C0 (22 B)
// [TODO] 0x006E60E0 sub_006E60E0 (36 B)
// [TODO] 0x006E6110 sub_006E6110 (4 B)
// [TODO] 0x006E6120 sub_006E6120 (57 B)
// [TODO] 0x006E6230 sub_006E6230 (29 B)
// [TODO] 0x006E6250 sub_006E6250 (50 B)
// [TODO] 0x006E6290 sub_006E6290 (31 B)
// [TODO] 0x006E62B0 sub_006E62B0 (63 B)
// [TODO] 0x006E6360 sub_006E6360 (4 B)
// ============================================================================
// [VERIFIED] sub_006E6370 (0x006E6370, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E6370 (0x006E6370, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00FB0E38;

class Class_006E6370
{
public:
    void sub_006E6370();
};

void Class_006E6370::sub_006E6370()
{
    ((void (__cdecl*)(void))DAT_00FB0E38)();
}

// [TODO] 0x006E6380 sub_006E6380 (7330 B)
// [TODO] 0x006E63B0 sub_006E63B0 (11 B)
// [TODO] 0x006E63E0 sub_006E63E0 (11 B)
// [TODO] 0x006E6400 sub_006E6400 (1394 B)
// [TODO] 0x006E6410 sub_006E6410 (1490 B)
// [TODO] 0x006E6420 sub_006E6420 (4 B)
// [TODO] 0x006E6430 core::Drive::vfunc_06 (7 B)
// [TODO] 0x006E6440 core::Drive::vfunc_11 (5 B)
// [TODO] 0x006E6450 core::Drive::vfunc_15 (5 B)
// [TODO] 0x006E6460 core::Drive::vfunc_22 (8 B)
// [TODO] 0x006E6470 core::Drive::vfunc_00 (8 B)
// [TODO] 0x006E6480 core::Drive::vfunc_02 (8 B)
// ============================================================================
// [VERIFIED] core::SafeRefCount::vfunc_02 (0x006E6490, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::BaseObject::vfunc_00 (0x00026BB0), which was matched first;
// its addresses and names were swapped for this function's.
// core::SafeRefCount::vfunc_02 (0x006E6490, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007721D8[];
extern "C" void __cdecl sub_0043CE70(int);

namespace core {

class SafeRefCount
{
public:
    virtual SafeRefCount* vfunc_02(int a1);
};

SafeRefCount* SafeRefCount::vfunc_02(int a1)
{
    *(int*)this = (int)DAT_007721D8;
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x006E64B0 sub_006E64B0 (127 B)
// [TODO] 0x006E6530 core::Drive::vfunc_03 (88 B)
// [TODO] 0x006E6590 core::Drive::vfunc_04 (257 B)
// [TODO] 0x006E66A0 sub_006E66A0 (103 B)
// [TODO] 0x006E6710 core::CementLibrary::vfunc_00 (11 B)
// [TODO] 0x006E6720 core::CementLibrary::vfunc_01 (12 B)
// [TODO] 0x006E6730 core::CementLibrary::vfunc_05 (39 B)
// [TODO] 0x006E6760 core::CementLibrary::vfunc_07 (10 B)
// [TODO] 0x006E6770 core::CementLibrary::vfunc_06 (23 B)
// [TODO] 0x006E6790 sub_006E6790 (62 B)
// [TODO] 0x006E67D0 sub_006E67D0 (52 B)
// [TODO] 0x006E6810 core::CementLibrary::vfunc_08 (151 B)
// [TODO] 0x006E68B0 core::CementLibrary::vfunc_09 (51 B)
// [TODO] 0x006E68C9 sub_006E68C9 (26 B)
// [TODO] 0x006E68F0 sub_006E68F0 (54 B)
// ============================================================================
// [VERIFIED] sub_006E69F0 (0x006E69F0, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002ACD30 (0x002ACD30), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E69F0 (0x006E69F0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006DF080(int);

class Class_006E69F0
{
public:
    void sub_006E69F0(int a1);
    char m_pad00[0x10];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

void Class_006E69F0::sub_006E69F0(int a1)
{
    sub_006DF080((int)(&m_Field14));
    m_Field10 = *(int*)((int)this + (a1 * 4));
}

// ============================================================================
// [VERIFIED] sub_006E6A10 (0x006E6A10, 14 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002ACD50 (0x002ACD50), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E6A10 (0x006E6A10, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006E6A10
{
public:
    int sub_006E6A10();
    char m_pad00[0x10];
    int m_Field10; // +0x10
};

int Class_006E6A10::sub_006E6A10()
{
    int r_eax;

    r_eax = m_Field10;
    if (r_eax) {
        m_Field10 = *(int*)(r_eax + 100);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_006E6A20 (0x006E6A20, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E6A20 (0x006E6A20, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00FB09A0;

class Class_006E6A20
{
public:
    void sub_006E6A20();
};

void Class_006E6A20::sub_006E6A20()
{
    ((void (__cdecl*)(void))DAT_00FB09A0)();
}

// [TODO] 0x006E6A40 sub_006E6A40 (64 B)
// [TODO] 0x006E6A80 sub_006E6A80 (194 B)
// [TODO] 0x006E6B50 core::CementLibrary::vfunc_00 (23 B)
// ============================================================================
// [VERIFIED] core::CementLibrary::vfunc_01 (0x006E6B70, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CementLibrary::vfunc_01 (0x002ACEB0), which was matched first;
// its addresses and names were swapped for this function's.
// core::CementLibrary::vfunc_01 (0x006E6B70, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006E6090();
};

namespace core {

class CementLibrary
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void CementLibrary::vfunc_01()
{
    ((Object*)(int)this + 16)->sub_006E6090();
}

}

// [TODO] 0x006E6B80 core::CementLibrary::vfunc_00 (8 B)
// [TODO] 0x006E6B90 core::CementLibrary::vfunc_01 (8 B)
// [TODO] 0x006E6BA0 core::CementLibrary::vfunc_02 (8 B)
// [TODO] 0x006E6BB0 core::CementLibrary::vfunc_03 (8 B)
// [TODO] 0x006E6BC0 core::CementLibrary::vfunc_00 (8 B)
// [TODO] 0x006E6BD0 core::CementLibrary::vfunc_02 (8 B)
// [TODO] 0x006E6BE0 core::CementLibrary::vfunc_04 (419 B)
// [TODO] 0x006E6C82 sub_006E6C82 (257 B)
// [TODO] 0x006E6D90 sub_006E6D90 (137 B)
// [TODO] 0x006E6E20 sub_006E6E20 (54 B)
// [TODO] 0x006E6E60 sub_006E6E60 (227 B)
// [TODO] 0x006E6F50 core::CementLibrary::vfunc_03 (13 B)
// [TODO] 0x006E6F80 sub_006E6F80 (41 B)
// [TODO] 0x006E6FB0 sub_006E6FB0 (135 B)
// [TODO] 0x006E7040 sub_006E7040 (37 B)
// [TODO] 0x006E7070 sub_006E7070 (18 B)
// [TODO] 0x006E7390 sub_006E7390 (124 B)
// [TODO] 0x006E7410 sub_006E7410 (28 B)
// [TODO] 0x006E7430 sub_006E7430 (80 B)
// [TODO] 0x006E7480 core::Win32Drive::vfunc_00 (14 B)
// [TODO] 0x006E7490 core::Win32Drive::vfunc_01 (14 B)
// [TODO] 0x006E74A0 core::Win32Drive::vfunc_05 (7 B)
// [TODO] 0x006E74B0 core::Win32Drive::vfunc_12 (30 B)
// [TODO] 0x006E74D0 core::Win32Drive::vfunc_22 (29 B)
// [TODO] 0x006E74F0 sub_006E74F0 (13 B)
// [TODO] 0x006E75D0 sub_006E75D0 (150 B)
// [TODO] 0x006E7670 sub_006E7670 (138 B)
// [TODO] 0x006E7730 sub_006E7730 (116 B)
// [TODO] 0x006E77B0 core::Win32Drive::vfunc_00 (8 B)
// [TODO] 0x006E77C0 core::Win32Drive::vfunc_02 (8 B)
// [TODO] 0x006E77D0 sub_006E77D0 (220 B)
// ============================================================================
// [VERIFIED] core::Win32Drive::vfunc_03 (0x006E78B0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::Win32Drive::vfunc_03 (0x006E78B0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);
extern "C" void __cdecl sub_006E7430(void);

namespace core {

class Win32Drive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Win32Drive* vfunc_03(int a1);
};

Win32Drive* Win32Drive::vfunc_03(int a1)
{
    sub_006E7430();
    if (a1 & 1) {
        sub_006DC430(DAT_007F5A70, (int)this);
    }
    return this;
}

}

// [TODO] 0x006E78E0 core::Win32Drive::vfunc_09 (80 B)
// [TODO] 0x006E7930 core::Win32Drive::vfunc_10 (265 B)
// [TODO] 0x006E7938 sub_006E7938 (257 B)
// [TODO] 0x006E7A40 core::Win32Drive::vfunc_14 (111 B)
// [TODO] 0x006E7AB0 core::Win32Drive::vfunc_15 (178 B)
// [TODO] 0x006E7B70 core::Win32Drive::vfunc_20 (137 B)
// [TODO] 0x006E7C00 core::Win32Drive::vfunc_21 (140 B)
// [TODO] 0x006E7C90 core::Win32Drive::vfunc_17 (108 B)
// [TODO] 0x006E7D00 core::Win32Drive::vfunc_18 (106 B)
// [TODO] 0x006E7D70 core::Win32Drive::vfunc_19 (106 B)
// [TODO] 0x006E7DE0 sub_006E7DE0 (60 B)
// [TODO] 0x006E7E20 sub_006E7E20 (107 B)
// ============================================================================
// [VERIFIED] core::Drive::vfunc_01 (0x006E7E90, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::Drive::vfunc_01 (0x002C1450), which was matched first;
// its addresses and names were swapped for this function's.
// core::Drive::vfunc_01 (0x006E7E90, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006E6090();
};

namespace core {

class Drive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void Drive::vfunc_01()
{
    ((Object*)(int)this + 12)->sub_006E6090();
}

}

// [TODO] 0x006E7EA0 AnimationRetargetingAction::vfunc_14 (4 B)
// ============================================================================
// [VERIFIED] core::DriveThread::vfunc_00 (0x006E7EB0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::DriveThread::vfunc_00 (0x002C1460), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveThread::vfunc_00 (0x006E7EB0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006DF080(int);

namespace core {

class DriveThread
{
public:
    virtual void vfunc_00();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

void DriveThread::vfunc_00()
{
    sub_006DF080(m_Field08);
}

}

// ============================================================================
// [VERIFIED] core::DriveThread::vfunc_01 (0x006E7EC0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::DriveThread::vfunc_00 (0x002C1460), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveThread::vfunc_01 (0x006E7EC0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006DF070(int);

namespace core {

class DriveThread
{
public:
    virtual void vfunc_01();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

void DriveThread::vfunc_01()
{
    sub_006DF070(m_Field08);
}

}

// [TODO] 0x006E7ED0 sub_006E7ED0 (19 B)
// [TODO] 0x006E8030 sub_006E8030 (123 B)
// [TODO] 0x006E80B0 sub_006E80B0 (103 B)
// [TODO] 0x006E8120 sub_006E8120 (43 B)
// [TODO] 0x006E8190 sub_006E8190 (36 B)
// [TODO] 0x006E81C0 sub_006E81C0 (26 B)
// [TODO] 0x006E81E0 sub_006E81E0 (154 B)
// [TODO] 0x006E8280 sub_006E8280 (21 B)
// [TODO] 0x006E82C0 core::DriveThread::vfunc_00 (8 B)
// [TODO] 0x006E82D0 core::DriveThread::vfunc_02 (8 B)
// [TODO] 0x006E8530 sub_006E8530 (209 B)
// ============================================================================
// [VERIFIED] core::DriveThread::vfunc_03 (0x006E8610, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// core::DriveThread::vfunc_03 (0x006E8610, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);
extern "C" void __cdecl sub_006E7E20(void);

namespace core {

class DriveThread
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual DriveThread* vfunc_03(int a1);
};

DriveThread* DriveThread::vfunc_03(int a1)
{
    sub_006E7E20();
    if (a1 & 1) {
        sub_006DC430(DAT_007F5A70, (int)this);
    }
    return this;
}

}

// [TODO] 0x006E8640 sub_006E8640 (692 B)
// [TODO] 0x006E8B20 sub_006E8B20 (83 B)
// [TODO] 0x006E8B80 sub_006E8B80 (599 B)
// [TODO] 0x006E9160 sub_006E9160 (25 B)
// [TODO] 0x006E9180 sub_006E9180 (42 B)
// [TODO] 0x006E91B0 sub_006E91B0 (194 B)
// [TODO] 0x006E9280 sub_006E9280 (22 B)
// [TODO] 0x006E92A0 sub_006E92A0 (31 B)
// [TODO] 0x006E9340 sub_006E9340 (96 B)
// [TODO] 0x006E93A0 sub_006E93A0 (162 B)
// [TODO] 0x006E9450 sub_006E9450 (121 B)
// [TODO] 0x006E94D0 sub_006E94D0 (14 B)
// [TODO] 0x006E94F0 sub_006E94F0 (54 B)
// [TODO] 0x006E9530 sub_006E9530 (27 B)
// [TODO] 0x006E9550 sub_006E9550 (68 B)
// [TODO] 0x006E95A0 sub_006E95A0 (167 B)
// ============================================================================
// [VERIFIED] sub_006E9650 (0x006E9650, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E9650 (0x006E9650, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00FB066C;

class Class_006E9650
{
public:
    void sub_006E9650();
};

void Class_006E9650::sub_006E9650()
{
    ((void (__cdecl*)(void))DAT_00FB066C)();
}

// [TODO] 0x006E9660 sub_006E9660 (234 B)
// [TODO] 0x006E9750 sub_006E9750 (98 B)
// ============================================================================
// [VERIFIED] sub_006E97D0 (0x006E97D0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E97D0 (0x006E97D0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0043CE00(void);

class Class_006E97D0
{
public:
    void sub_006E97D0();
};

void Class_006E97D0::sub_006E97D0()
{
    sub_0043CE00();
}

// [TODO] 0x006E97E0 sub_006E97E0 (40 B)
// ============================================================================
// [VERIFIED] sub_006E9810 (0x006E9810, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006E9810 (0x006E9810, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0043CE70(void);

class Class_006E9810
{
public:
    void sub_006E9810();
};

void Class_006E9810::sub_006E9810()
{
    sub_0043CE70();
}

// [TODO] 0x006E9820 GameMemorySegmentCollection::vfunc_02 (4 B)
// [TODO] 0x006E9830 sub_006E9830 (17 B)
// [TODO] 0x006E9850 content::LoadInventory::vfunc_04 (126 B)
// [TODO] 0x006E9970 sub_006E9970 (16 B)
// [TODO] 0x006E9A10 sub_006E9A10 (33 B)
// [TODO] 0x006E9AE0 content::LoadInventory::vfunc_03 (81 B)
// [TODO] 0x006E9B40 content::P3DFileHandler::vfunc_04 (809 B)
// [TODO] 0x006E9E70 NISStreamDataLoader::vfunc_04 (27 B)
// ============================================================================
// [VERIFIED] content::Stats::vfunc_00 (0x006E9E90, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::BaseObject::vfunc_00 (0x00026BB0), which was matched first;
// its addresses and names were swapped for this function's.
// content::Stats::vfunc_00 (0x006E9E90, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772404[];
extern "C" void __cdecl sub_0043CE70(int);

namespace content {

class Stats
{
public:
    virtual Stats* vfunc_00(int a1);
};

Stats* Stats::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772404;
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x006E9EC0 sub_006E9EC0 (86 B)
// [TODO] 0x006E9F50 sub_006E9F50 (6 B)
// [TODO] 0x006E9F60 sub_006E9F60 (21 B)
// [TODO] 0x006EA020 sub_006EA020 (64 B)
// ============================================================================
// [VERIFIED] sub_006EA060 (0x006EA060, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00240E00 (0x00240E00), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EA060 (0x006EA060, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    void sub_006E95A0(int, int);
};

class Class_006EA060
{
public:
    void sub_006EA060(int a1, int a2);
    char m_pad00[0x20];
    int m_Field20; // +0x20
};

void Class_006EA060::sub_006EA060(int a1, int a2)
{
    int t1;

    t1 = m_Field20;
    ((Object*)a1)->vfunc_00();
    ((Object*)t1)->sub_006E95A0(a2, a1);
}

// [TODO] 0x006EA150 sub_006EA150 (36 B)
// ============================================================================
// [VERIFIED] sub_006EA1C0 (0x006EA1C0, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000D3C80 (0x000D3C80), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EA1C0 (0x006EA1C0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_006E9F60(int, int);

void __stdcall sub_006EA1C0(int a1)
{
    sub_006E9F60(a1, 1);
}

// [TODO] 0x006EA1D0 sub_006EA1D0 (39 B)
// [TODO] 0x006EA4B0 sub_006EA4B0 (162 B)
// [TODO] 0x006EA570 sub_006EA570 (268 B)
// [TODO] 0x006EA790 sub_006EA790 (137 B)
// [TODO] 0x006EA8F0 sub_006EA8F0 (118 B)
// [TODO] 0x006EA970 sub_006EA970 (100 B)
// [TODO] 0x006EA9E0 sub_006EA9E0 (60 B)
// [TODO] 0x006EAA20 sub_006EAA20 (80 B)
// [TODO] 0x006EAA70 sub_006EAA70 (108 B)
// [TODO] 0x006EAAE0 sub_006EAAE0 (43 B)
// [TODO] 0x006EAB10 sub_006EAB10 (71 B)
// [TODO] 0x006EAB60 sub_006EAB60 (60 B)
// [TODO] 0x006EABA0 sub_006EABA0 (109 B)
// [TODO] 0x006EAC60 content::LoadStream::vfunc_03 (70 B)
// [TODO] 0x006EACB0 sub_006EACB0 (312 B)
// [TODO] 0x006EADF0 sub_006EADF0 (116 B)
// [TODO] 0x006EAEE0 sub_006EAEE0 (103 B)
// [TODO] 0x006EAF50 sub_006EAF50 (69 B)
// [TODO] 0x006EAFA0 sub_006EAFA0 (168 B)
// [TODO] 0x006EB050 sub_006EB050 (141 B)
// [TODO] 0x006EB0E0 sub_006EB0E0 (11 B)
// [TODO] 0x006EB0F0 sub_006EB0F0 (20 B)
// [TODO] 0x006EB110 sub_006EB110 (7 B)
// [TODO] 0x006EB150 sub_006EB150 (242 B)
// [TODO] 0x006EB250 sub_006EB250 (162 B)
// [TODO] 0x006EB300 sub_006EB300 (10 B)
// [TODO] 0x006EB350 sub_006EB350 (16 B)
// [TODO] 0x006EB370 sub_006EB370 (102 B)
// [TODO] 0x006EB490 sub_006EB490 (28 B)
// [TODO] 0x006EB4B0 sub_006EB4B0 (38 B)
// [TODO] 0x006EB4E0 sub_006EB4E0 (38 B)
// [TODO] 0x006EB510 sub_006EB510 (110 B)
// [TODO] 0x006EB580 content::LoadRequest::vfunc_03 (76 B)
// [TODO] 0x006EB5D0 sub_006EB5D0 (71 B)
// [TODO] 0x006EB620 sub_006EB620 (5 B)
// [TODO] 0x006EB630 sub_006EB630 (98 B)
// [TODO] 0x006EB6A0 sub_006EB6A0 (34 B)
// [TODO] 0x006EB6D0 sub_006EB6D0 (16 B)
// [TODO] 0x006EB6E0 sub_006EB6E0 (12 B)
// [TODO] 0x006EB6F0 sub_006EB6F0 (82 B)
// [TODO] 0x006EB750 sub_006EB750 (8 B)
// [TODO] 0x006EB7A0 sub_006EB7A0 (83 B)
// [TODO] 0x006EB800 sub_006EB800 (69 B)
// [TODO] 0x006EB850 sub_006EB850 (103 B)
// [TODO] 0x006EB8C0 sub_006EB8C0 (127 B)
// [TODO] 0x006EB940 sub_006EB940 (104 B)
// ============================================================================
// [VERIFIED] sub_006EB9B0 (0x006EB9B0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000E42D0 (0x000E42D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EB9B0 (0x006EB9B0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_006EB8C0(int);

class Class_006EB9B0
{
public:
    Class_006EB9B0* sub_006EB9B0(int a1);
};

Class_006EB9B0* Class_006EB9B0::sub_006EB9B0(int a1)
{
    sub_006EB8C0(a1);
    return this;
}

// [TODO] 0x006EB9D0 sub_006EB9D0 (41 B)
// [TODO] 0x006EBA00 sub_006EBA00 (94 B)
// [TODO] 0x006EBA60 sub_006EBA60 (94 B)
// [TODO] 0x006EBAE0 sub_006EBAE0 (24 B)
// [TODO] 0x006EBBD0 sub_006EBBD0 (15 B)
// [TODO] 0x006EBBE0 sub_006EBBE0 (69 B)
// [TODO] 0x006EBCA0 sub_006EBCA0 (70 B)
// ============================================================================
// [VERIFIED] sub_006EBD00 (0x006EBD00, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E670 (0x0001E670), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EBD00 (0x006EBD00, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0085CE68;

bool __cdecl sub_006EBD00(void)
{
    return DAT_0085CE68;
}

// [TODO] 0x006EBD20 sub_006EBD20 (51 B)
// [TODO] 0x006EBD60 sub_006EBD60 (51 B)
// [TODO] 0x006EBDA0 sub_006EBDA0 (62 B)
// ============================================================================
// [VERIFIED] sub_006EBDE0 (0x006EBDE0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EBDE0 (0x006EBDE0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F646C[];
extern "C" void __stdcall sub_006EE870(int);

class Class_006EBDE0
{
public:
    void sub_006EBDE0(int a1);
};

void Class_006EBDE0::sub_006EBDE0(int a1)
{
    a1 = (int)DAT_007F646C;
    sub_006EE870(a1);
}

// ============================================================================
// [VERIFIED] audio::OmHalStream::vfunc_10 (0x006EBDF0, 11 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::OmHalStream::vfunc_10 (0x002D5910), which was matched first;
// its addresses and names were swapped for this function's.
// audio::OmHalStream::vfunc_10 (0x006EBDF0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006EB6D0();
};

namespace audio {

class OmHalStream
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
    virtual void vfunc_10();
};

void OmHalStream::vfunc_10()
{
    ((Object*)(int)this + 448)->sub_006EB6D0();
}

}

// [TODO] 0x006EBE00 audio::OmHalStream::vfunc_07 (177 B)
// [TODO] 0x006EBEC0 audio::OmHalStream::vfunc_06 (219 B)
// ============================================================================
// [VERIFIED] audio::OmHalStream::vfunc_08 (0x006EBFA0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::OmHalStream::vfunc_08 (0x002D5B00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::OmHalStream::vfunc_08 (0x006EBFA0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class OmHalStream
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
    virtual bool vfunc_08(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    char m_pad0C[0x1AC];
    int m_Field1B8; // +0x1B8
};

bool OmHalStream::vfunc_08(int a1)
{
    *(int*)a1 = m_Field1B8;
    m_Field08 -= m_Field1B8;
    m_Field1B8 = 0;
    return true;
}

}

// ============================================================================
// [VERIFIED] audio::OmHalStream::vfunc_09 (0x006EBFD0, 17 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::OmHalStream::vfunc_09 (0x002D5B30), which was matched first;
// its addresses and names were swapped for this function's.
// audio::OmHalStream::vfunc_09 (0x006EBFD0, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class OmHalStream
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
    virtual int vfunc_09(int a1);
};

int OmHalStream::vfunc_09(int a1)
{
    return (a1 << 4) + (int)this + 184;
}

}

// [TODO] 0x006EBFF0 audio::OmHalStream::vfunc_05 (46 B)
// [TODO] 0x006EC020 audio::OmHalStream::vfunc_03 (13 B)
// [TODO] 0x006EC030 sub_006EC030 (227 B)
// [TODO] 0x006EC120 sub_006EC120 (185 B)
// [TODO] 0x006EC1E0 sub_006EC1E0 (78 B)
// [TODO] 0x006EC230 sub_006EC230 (76 B)
// [TODO] 0x006EC280 sub_006EC280 (85 B)
// [TODO] 0x006EC2E0 sub_006EC2E0 (361 B)
// ============================================================================
// [VERIFIED] sub_006EC450 (0x006EC450, 24 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D5FC0 (0x002D5FC0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EC450 (0x006EC450, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006EE9B0(void);

int __cdecl sub_006EC450(int a1, int a2)
{
    sub_006EE9B0();
    *(int*)a1 = *(int*)a2;
    *(int*)(a1 + 4) = *(int*)(a2 + 4);
    return a1;
}

// [TODO] 0x006EC470 sub_006EC470 (122 B)
// ============================================================================
// [VERIFIED] sub_006EC4F0 (0x006EC4F0, 70 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D6060 (0x002D6060), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EC4F0 (0x006EC4F0, 70 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006EC120(int, int);
extern "C" bool __cdecl sub_006EC280(int, int);
extern "C" bool __cdecl sub_006F33D0(int, int);

class Class_006EC4F0
{
public:
    bool sub_006EC4F0(int a1);
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
};

bool Class_006EC4F0::sub_006EC4F0(int a1)
{
    if (sub_006EC280(a1, (int)this)) {
        if (!sub_006F33D0(a1, (int)(&m_Field0C))) goto L_3F;
        if (!sub_006EC120(a1, (int)this + 8)) goto L_3F;
        return true;
    }
L_3F:
    return false;
}

// [TODO] 0x006EC540 sub_006EC540 (175 B)
// ============================================================================
// [VERIFIED] audio::OmHalStream::vfunc_12 (0x006EC5F0, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::OmHalStream::vfunc_12 (0x002D6170), which was matched first;
// its addresses and names were swapped for this function's.
// audio::OmHalStream::vfunc_12 (0x006EC5F0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field1C0
{
    void sub_006EBBD0();
};

extern "C" char DAT_007724CC[];
extern "C" char DAT_007F646C[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class OmHalStream
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    char m_pad04[0x1BC];
    Field1C0 m_Field1C0; // +0x1C0
};

void OmHalStream::vfunc_12()
{
    if (this) {
        *(int*)this = (int)DAT_007724CC;
        m_Field1C0.sub_006EBBD0();
        sub_006EE890((int)DAT_007F646C, (int)this);
    }
}

}

// ============================================================================
// [VERIFIED] sub_006EC620 (0x006EC620, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EC620 (0x006EC620, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00FB0390;

class Class_006EC620
{
public:
    void sub_006EC620();
};

void Class_006EC620::sub_006EC620()
{
    ((void (__cdecl*)(void))DAT_00FB0390)();
}

// ============================================================================
// [VERIFIED] sub_006EC630 (0x006EC630, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EC630 (0x006EC630, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F6474[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006EC630(int a1)
{
    sub_006EE890((int)DAT_007F6474, a1);
}

// [TODO] 0x006EC650 sub_006EC650 (25 B)
// ============================================================================
// [VERIFIED] om::EntityLoader::vfunc_03 (0x006EC670, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityLoader::vfunc_03 (0x006EC670, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0073523C[];
extern "C" char DAT_007F6474[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace om {

class EntityLoader
{
public:
    virtual EntityLoader* vfunc_03(int a1);
};

EntityLoader* EntityLoader::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_0073523C;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F6474, (int)this);
    }
    return this;
}

}

// [TODO] 0x006EC6A0 om::EntityLoader::vfunc_04 (245 B)
// ============================================================================
// [VERIFIED] sub_006EC7A0 (0x006EC7A0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EC7A0 (0x006EC7A0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00FB4BA0;

class Class_006EC7A0
{
public:
    void sub_006EC7A0();
};

void Class_006EC7A0::sub_006EC7A0()
{
    ((void (__cdecl*)(void))DAT_00FB4BA0)();
}

// ============================================================================
// [VERIFIED] sub_006EC7B0 (0x006EC7B0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EC7B0 (0x006EC7B0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F64D8[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006EC7B0(int a1)
{
    sub_006EE890((int)DAT_007F64D8, a1);
}

// [TODO] 0x006EC7D0 sub_006EC7D0 (137 B)
// [TODO] 0x006EC860 om::TRbTree<om::MetaTypeBase, 4>::Comp<om::MetaTypeBase, 4, om::String>::vfunc_00 (45 B)
// [TODO] 0x006EC890 om::MetaType<GlobalVehicleSound>::vfunc_01 (199 B)
// [TODO] 0x006EC960 om::MetaType<GlobalVehicleSound>::vfunc_02 (199 B)
// [TODO] 0x006ECA30 sub_006ECA30 (88 B)
// [TODO] 0x006ECA90 sub_006ECA90 (46 B)
// [TODO] 0x006ECAC0 sub_006ECAC0 (15 B)
// ============================================================================
// [VERIFIED] sub_006ECB50 (0x006ECB50, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002CEF70 (0x002CEF70), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006ECB50 (0x006ECB50, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_006ECA90();
};

struct Object
{
    void sub_006F2A40(int);
};

extern "C" char DAT_00772564[];
extern "C" Object DAT_0085CE74;

class Class_006ECB50
{
public:
    void sub_006ECB50();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    char m_pad08[0xC];
    Field14 m_Field14; // +0x14
    char m_pad15[0x13];
    Field14 m_Field28; // +0x28
    char m_pad29[0x13];
    Field14 m_Field3C; // +0x3C
};

void Class_006ECB50::sub_006ECB50()
{
    m_Field00 = (int)DAT_00772564;
    DAT_0085CE74.sub_006F2A40((int)(&m_Field04));
    m_Field14.sub_006ECA90();
    m_Field3C.sub_006ECA90();
    m_Field28.sub_006ECA90();
}

// ============================================================================
// [VERIFIED] om::MetaTypeBase::vfunc_00 (0x006ECB80, 74 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::MetaTypeBase::vfunc_00 (0x002CEFA0), which was matched first;
// its addresses and names were swapped for this function's.
// om::MetaTypeBase::vfunc_00 (0x006ECB80, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_006ECA90();
};

struct Object
{
    void sub_006F2A40(int);
};

extern "C" char DAT_00772564[];
extern "C" char DAT_007F64D8[];
extern "C" Object DAT_0085CE74;
extern "C" void __cdecl sub_006EE890(int, int);

namespace om {

class MetaTypeBase
{
public:
    virtual MetaTypeBase* vfunc_00(int a1);
    int m_Field04; // +0x04
    char m_pad08[0xC];
    Field14 m_Field14; // +0x14
    char m_pad15[0x13];
    Field14 m_Field28; // +0x28
    char m_pad29[0x13];
    Field14 m_Field3C; // +0x3C
};

MetaTypeBase* MetaTypeBase::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772564;
    DAT_0085CE74.sub_006F2A40((int)(&m_Field04));
    m_Field14.sub_006ECA90();
    m_Field3C.sub_006ECA90();
    m_Field28.sub_006ECA90();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F64D8, (int)this);
    }
    return this;
}

}

// [TODO] 0x006ECBD0 sub_006ECBD0 (76 B)
// [TODO] 0x006ECC20 sub_006ECC20 (133 B)
// [TODO] 0x006ECCB0 GlobalVehicleSound::vfunc_00 (6 B)
// [TODO] 0x006ECCC0 GlobalVehicleSound::vfunc_01 (26 B)
// ============================================================================
// [VERIFIED] GlobalVehicleSound::vfunc_02 (0x006ECCE0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GlobalVehicleSound::vfunc_02 (0x002CF100), which was matched first;
// its addresses and names were swapped for this function's.
// GlobalVehicleSound::vfunc_02 (0x006ECCE0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class GlobalVehicleSound
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    char m_pad04[0x1C];
    short m_Field20; // +0x20
};

int GlobalVehicleSound::vfunc_02()
{
    return m_Field20;
}

// ============================================================================
// [VERIFIED] GlobalVehicleSound::vfunc_05 (0x006ECCF0, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GlobalVehicleSound::vfunc_05 (0x002CF110), which was matched first;
// its addresses and names were swapped for this function's.
// GlobalVehicleSound::vfunc_05 (0x006ECCF0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01(int, int);
    virtual int vfunc_02();
};

class GlobalVehicleSound
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual int vfunc_12();
};

void GlobalVehicleSound::vfunc_05(int a1)
{
    ((Object*)((Object*)vfunc_12())->vfunc_02())->vfunc_01(a1, (int)this);
}

// ============================================================================
// [VERIFIED] GlobalVehicleSound::vfunc_07 (0x006ECD10, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GlobalVehicleSound::vfunc_07 (0x002CF130), which was matched first;
// its addresses and names were swapped for this function's.
// GlobalVehicleSound::vfunc_07 (0x006ECD10, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
};

struct Object2
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int, int);
};

class GlobalVehicleSound
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int a1);
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual int vfunc_12();
};

void GlobalVehicleSound::vfunc_07(int a1)
{
    ((Object2*)((Object*)vfunc_12())->vfunc_02())->vfunc_02(a1, (int)this);
}

// [TODO] 0x006ECD30 sub_006ECD30 (71 B)
// [TODO] 0x006ECE00 GlobalVehicleSound::vfunc_08 (488 B)
// [TODO] 0x006ECFF0 sub_006ECFF0 (115 B)
// [TODO] 0x006ED070 om::TRbTree<om::EntityTypeBase, 28>::Comp<om::EntityTypeBase, 28, unsigned int>::vfunc_00 (35 B)
// [TODO] 0x006ED0A0 sub_006ED0A0 (9 B)
// ============================================================================
// [VERIFIED] sub_006ED0C0 (0x006ED0C0, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002CF4E0 (0x002CF4E0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006ED0C0 (0x006ED0C0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F2A40(int);
};

extern "C" char DAT_0073523C[];
extern "C" char DAT_007725C0[];
extern "C" Object DAT_0085CE88;

class Class_006ED0C0
{
public:
    void sub_006ED0C0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

void Class_006ED0C0::sub_006ED0C0()
{
    m_Field00 = (int)DAT_007725C0;
    DAT_0085CE88.sub_006F2A40((int)(&m_Field04));
    m_Field00 = (int)DAT_0073523C;
}

// [TODO] 0x006ED250 sub_006ED250 (175 B)
// [TODO] 0x006ED300 om::TRbTree<om::Entity, 4>::Comp<om::Entity, 4, om::Name<om::CaseSensitive64BitKey>>::vfunc_00 (72 B)
// [TODO] 0x006ED350 sub_006ED350 (48 B)
// ============================================================================
// [VERIFIED] om::EntityTypeBase::vfunc_00 (0x006ED3B0, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityTypeBase::vfunc_00 (0x002CF7D0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityTypeBase::vfunc_00 (0x006ED3B0, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F2A40(int);
};

extern "C" char DAT_007725AC[];
extern "C" Object DAT_0085CE9C;
extern "C" void __cdecl sub_0043CE70(int);

namespace om {

class EntityTypeBase
{
public:
    virtual EntityTypeBase* vfunc_00(int a1);
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

EntityTypeBase* EntityTypeBase::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_007725AC;
    DAT_0085CE9C.sub_006F2A40((int)(&m_Field1C));
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x006ED3E0 sub_006ED3E0 (89 B)
// ============================================================================
// [VERIFIED] om::Entity::vfunc_03 (0x006ED440, 51 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::Entity::vfunc_03 (0x002CF860), which was matched first;
// its addresses and names were swapped for this function's.
// om::Entity::vfunc_03 (0x006ED440, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F2A40(int);
};

extern "C" char DAT_0073523C[];
extern "C" char DAT_007725C0[];
extern "C" Object DAT_0085CE88;
extern "C" void __cdecl sub_0043CE70(int);

namespace om {

class Entity
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Entity* vfunc_03(int a1);
    int m_Field04; // +0x04
};

Entity* Entity::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_007725C0;
    DAT_0085CE88.sub_006F2A40((int)(&m_Field04));
    *(int*)this = (int)DAT_0073523C;
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x006ED490 GlobalVehicleSound::vfunc_04 (109 B)
// [TODO] 0x006ED500 sub_006ED500 (75 B)
// ============================================================================
// [VERIFIED] audio::Sequence::vfunc_12 (0x006ED590, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::MemoryAllocatorMalloc::vfunc_12 (0x0028D100), which was matched first;
// its addresses and names were swapped for this function's.
// audio::Sequence::vfunc_12 (0x006ED590, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00811D78;

namespace audio {

class Sequence
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual int vfunc_12();
};

int Sequence::vfunc_12()
{
    return DAT_00811D78;
}

}

// ============================================================================
// [VERIFIED] sub_006ED5A0 (0x006ED5A0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002CFB40 (0x002CFB40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006ED5A0 (0x006ED5A0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F2450();
};

class Class_006ED5A0
{
public:
    void sub_006ED5A0();
};

void Class_006ED5A0::sub_006ED5A0()
{
    ((Object*)(int)this + 68)->sub_006F2450();
}

// [TODO] 0x006ED5B0 sub_006ED5B0 (16 B)
// [TODO] 0x006ED5C0 sub_006ED5C0 (102 B)
// [TODO] 0x006ED630 sub_006ED630 (44 B)
// [TODO] 0x006ED660 om::TRbTree<audio::SeqTrack, 0>::Comp<audio::SeqTrack, 0, om::Name<om::CaseSensitive32BitKey>>::vfunc_00 (29 B)
// [TODO] 0x006ED680 om::TRbTree<audio::SeqBuss, 0>::Comp<audio::SeqBuss, 0, om::Name<om::CaseSensitive32BitKey>>::vfunc_00 (29 B)
// [TODO] 0x006ED6A0 sub_006ED6A0 (62 B)
// ============================================================================
// [VERIFIED] audio::Sequence::vfunc_05 (0x006ED6E0, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::Sequence::vfunc_05 (0x002CFC80), which was matched first;
// its addresses and names were swapped for this function's.
// audio::Sequence::vfunc_05 (0x006ED6E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field44
{
    void sub_006ED630();
};

extern "C" void __cdecl sub_006ED6A0(void);

namespace audio {

class Sequence
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    virtual void vfunc_06(int);
    char m_pad04[0x40];
    Field44 m_Field44; // +0x44
};

void Sequence::vfunc_05(int a1)
{
    sub_006ED6A0();
    m_Field44.sub_006ED630();
    vfunc_06(a1);
}

}

// [TODO] 0x006ED700 sub_006ED700 (273 B)
// [TODO] 0x006ED820 sub_006ED820 (98 B)
// [TODO] 0x006ED890 sub_006ED890 (107 B)
// [TODO] 0x006ED900 audio::Sequence::vfunc_03 (96 B)
// [TODO] 0x006ED960 audio::Sequence::vfunc_07 (64 B)
// [TODO] 0x006ED9A0 sub_006ED9A0 (143 B)
// [TODO] 0x006EDA30 audio::Sequence::vfunc_06 (110 B)
// [TODO] 0x006EDB60 sub_006EDB60 (12 B)
// ============================================================================
// [VERIFIED] sub_006EDCA0 (0x006EDCA0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EDCA0 (0x006EDCA0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_004897A5(void);

class Class_006EDCA0
{
public:
    void sub_006EDCA0();
};

void Class_006EDCA0::sub_006EDCA0()
{
    sub_004897A5();
}

// [TODO] 0x006EDCB0 sub_006EDCB0 (18 B)
// [TODO] 0x006EDCD0 sub_006EDCD0 (36 B)
// [TODO] 0x006EDD00 sub_006EDD00 (64 B)
// [TODO] 0x006EDD40 sub_006EDD40 (133 B)
// [TODO] 0x006EDDD0 sub_006EDDD0 (22 B)
// [TODO] 0x006EDDF0 sub_006EDDF0 (27 B)
// [TODO] 0x006EDE10 sub_006EDE10 (91 B)
// [TODO] 0x006EDE70 om::ContentStream::vfunc_00 (45 B)
// [TODO] 0x006EDEA0 sub_006EDEA0 (13 B)
// [TODO] 0x006EDEF0 sub_006EDEF0 (81 B)
// ============================================================================
// [VERIFIED] sub_006EDF50 (0x006EDF50, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EDF50 (0x006EDF50, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F680C[];
extern "C" void __stdcall sub_006EE870(int);

class Class_006EDF50
{
public:
    void sub_006EDF50(int a1);
};

void Class_006EDF50::sub_006EDF50(int a1)
{
    a1 = (int)DAT_007F680C;
    sub_006EE870(a1);
}

// ============================================================================
// [VERIFIED] sub_006EDF60 (0x006EDF60, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EDF60 (0x006EDF60, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F680C[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006EDF60(int a1)
{
    sub_006EE890((int)DAT_007F680C, a1);
}

// ============================================================================
// [VERIFIED] sub_006EDF80 (0x006EDF80, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EDF80 (0x006EDF80, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F6814[];
extern "C" void __stdcall sub_006EE870(int);

class Class_006EDF80
{
public:
    void sub_006EDF80(int a1);
};

void Class_006EDF80::sub_006EDF80(int a1)
{
    a1 = (int)DAT_007F6814;
    sub_006EE870(a1);
}

// ============================================================================
// [VERIFIED] sub_006EDFA0 (0x006EDFA0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EDFA0 (0x006EDFA0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F681C[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006EDFA0(int a1)
{
    sub_006EE890((int)DAT_007F681C, a1);
}

// ============================================================================
// [VERIFIED] sub_006EDFC0 (0x006EDFC0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EDFC0 (0x006EDFC0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F6824[];
extern "C" void __stdcall sub_006EE870(int);

class Class_006EDFC0
{
public:
    void sub_006EDFC0(int a1);
};

void Class_006EDFC0::sub_006EDFC0(int a1)
{
    a1 = (int)DAT_007F6824;
    sub_006EE870(a1);
}

// ============================================================================
// [VERIFIED] sub_006EDFD0 (0x006EDFD0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EDFD0 (0x006EDFD0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F6824[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006EDFD0(int a1)
{
    sub_006EE890((int)DAT_007F6824, a1);
}

// [TODO] 0x006EDFF0 audio::MixerMix::vfunc_00 (5 B)
// [TODO] 0x006EE000 audio::MixerMix::vfunc_01 (23 B)
// ============================================================================
// [VERIFIED] sub_006EE040 (0x006EE040, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0001E5D0 (0x0001E5D0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EE040 (0x006EE040, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085CEB0;

int __cdecl sub_006EE040(void)
{
    return DAT_0085CEB0;
}

// [TODO] 0x006EE050 sub_006EE050 (5 B)
// [TODO] 0x006EE060 sub_006EE060 (15 B)
// [TODO] 0x006EE070 sub_006EE070 (13 B)
// [TODO] 0x006EE080 sub_006EE080 (5 B)
// [TODO] 0x006EE090 sub_006EE090 (5 B)
// [TODO] 0x006EE0A0 sub_006EE0A0 (115 B)
// [TODO] 0x006EE120 om::TRbTree<audio::MixerMix, 4>::Comp<audio::MixerMix, 4, audio::Mix*>::vfunc_00 (35 B)
// [TODO] 0x006EE150 sub_006EE150 (427 B)
// ============================================================================
// [VERIFIED] sub_006EE310 (0x006EE310, 59 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D0890 (0x002D0890), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EE310 (0x006EE310, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_006F2A20();
};

extern "C" int DAT_0085CEB0;
extern "C" void __cdecl sub_006F2A20(void);

class Class_006EE310
{
public:
    Class_006EE310* sub_006EE310();
    char m_pad00[0x14];
    Field14 m_Field14; // +0x14
    char m_pad15[0x13];
    int m_Field28; // +0x28
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
    int m_Field34; // +0x34
    char m_pad38[0x8];
    int m_Field40; // +0x40
    int m_Field44; // +0x44
    int m_Field48; // +0x48
    int m_Field4C; // +0x4C
    int m_Field50; // +0x50
};

Class_006EE310* Class_006EE310::sub_006EE310()
{
    ::sub_006F2A20();
    m_Field14.sub_006F2A20();
    m_Field28 = 0;
    m_Field2C = 0;
    m_Field30 = 0;
    m_Field34 = 0;
    DAT_0085CEB0 = (int)this;
    m_Field48 = 0;
    m_Field4C = 0;
    m_Field40 = 0;
    m_Field44 = 0;
    m_Field50 = 0x3F800000;
    return this;
}

// [TODO] 0x006EE350 sub_006EE350 (91 B)
// [TODO] 0x006EE3B0 sub_006EE3B0 (97 B)
// [TODO] 0x006EE420 om::TRbTree<audio::MixerBuss, 0>::Comp<audio::MixerBuss, 0, om::Name<om::CaseSensitive32BitKey>>::vfunc_00 (29 B)
// [TODO] 0x006EE440 sub_006EE440 (88 B)
// [TODO] 0x006EE4A0 sub_006EE4A0 (71 B)
// [TODO] 0x006EE4F0 sub_006EE4F0 (60 B)
// [TODO] 0x006EE530 sub_006EE530 (56 B)
// ============================================================================
// [VERIFIED] sub_006EE570 (0x006EE570, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EE570 (0x006EE570, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006EE3B0(void);

class Class_006EE570
{
public:
    void sub_006EE570();
};

void Class_006EE570::sub_006EE570()
{
    sub_006EE3B0();
}

// [TODO] 0x006EE580 sub_006EE580 (118 B)
// [TODO] 0x006EE600 sub_006EE600 (114 B)
// [TODO] 0x006EE680 sub_006EE680 (99 B)
// [TODO] 0x006EE790 sub_006EE790 (99 B)
// ============================================================================
// [VERIFIED] audio::MixerMix::vfunc_03 (0x006EE800, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::MixerMix::vfunc_03 (0x006EE800, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F681C[];
extern "C" void __cdecl sub_006EE790(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class MixerMix
{
public:
    virtual MixerMix* vfunc_03(int a1);
};

MixerMix* MixerMix::vfunc_03(int a1)
{
    sub_006EE790();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F681C, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] sub_006EE870 (0x006EE870, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002CF960 (0x002CF960), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EE870 (0x006EE870, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F6834;

void __cdecl sub_006EE870(int a1)
{
    ((void (__cdecl*)(int, int))*(int*)(DAT_007F6834 + 4))(DAT_007F6834, a1);
}

// [TODO] 0x006EE890 sub_006EE890 (14 B)
// [TODO] 0x006EE8B0 sub_006EE8B0 (67 B)
// ============================================================================
// [VERIFIED] sub_006EE900 (0x006EE900, 25 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_000B7EE0 (0x000B7EE0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EE900 (0x006EE900, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007726E4[];

class Class_006EE900
{
public:
    Class_006EE900* sub_006EE900(int a1, int a2);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};

Class_006EE900* Class_006EE900::sub_006EE900(int a1, int a2)
{
    m_Field00 = (int)DAT_007726E4;
    m_Field04 = a1;
    m_Field08 = a2;
    return this;
}

// [TODO] 0x006EE930 sub_006EE930 (85 B)
// ============================================================================
// [VERIFIED] om::Allocator::vfunc_00 (0x006EE990, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::BaseObject::vfunc_00 (0x00026BB0), which was matched first;
// its addresses and names were swapped for this function's.
// om::Allocator::vfunc_00 (0x006EE990, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007726E4[];
extern "C" void __cdecl sub_0043CE70(int);

namespace om {

class Allocator
{
public:
    virtual Allocator* vfunc_00(int a1);
};

Allocator* Allocator::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_007726E4;
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x006EE9B0 sub_006EE9B0 (6 B)
// ============================================================================
// [VERIFIED] sub_006EE9D0 (0x006EE9D0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EE9D0 (0x006EE9D0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F69A8[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006EE9D0(int a1)
{
    sub_006EE890((int)DAT_007F69A8, a1);
}

// ============================================================================
// [VERIFIED] sub_006EE9F0 (0x006EE9F0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EE9F0 (0x006EE9F0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00424301(void);

class Class_006EE9F0
{
public:
    void sub_006EE9F0();
};

void Class_006EE9F0::sub_006EE9F0()
{
    sub_00424301();
}

// ============================================================================
// [VERIFIED] om::MetaType<audio::SeqEvent>::vfunc_00 (0x006EEAC0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::MetaType<audio::SeqEvent>::vfunc_00 (0x002D0EA0), which was matched first;
// its addresses and names were swapped for this function's.
// om::MetaType<audio::SeqEvent>::vfunc_00 (0x006EEAC0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772708[];
extern "C" void __cdecl sub_006EC7B0(int);
extern "C" void __cdecl sub_006ECB50(void);

namespace audio { class SeqEvent; }

namespace om { 
template <class T0> class MetaType
{
public:
    virtual MetaType<audio::SeqEvent>* vfunc_00(int a1);
};
}

template <> om::MetaType<audio::SeqEvent>* om::MetaType<audio::SeqEvent>::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772708;
    sub_006ECB50();
    if (a1 & 1) {
        sub_006EC7B0((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] om::MetaType<audio::Mix>::vfunc_00 (0x006EEAF0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::MetaType<audio::SeqEvent>::vfunc_00 (0x002D0EA0), which was matched first;
// its addresses and names were swapped for this function's.
// om::MetaType<audio::Mix>::vfunc_00 (0x006EEAF0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772718[];
extern "C" void __cdecl sub_006EC7B0(int);
extern "C" void __cdecl sub_006ECB50(void);

namespace audio { class Mix; }

namespace om { 
template <class T0> class MetaType
{
public:
    virtual MetaType<audio::Mix>* vfunc_00(int a1);
};
}

template <> om::MetaType<audio::Mix>* om::MetaType<audio::Mix>::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772718;
    sub_006ECB50();
    if (a1 & 1) {
        sub_006EC7B0((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] om::MetaType<audio::Clip>::vfunc_00 (0x006EEB20, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::MetaType<audio::SeqEvent>::vfunc_00 (0x002D0EA0), which was matched first;
// its addresses and names were swapped for this function's.
// om::MetaType<audio::Clip>::vfunc_00 (0x006EEB20, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772728[];
extern "C" void __cdecl sub_006EC7B0(int);
extern "C" void __cdecl sub_006ECB50(void);

namespace audio { class Clip; }

namespace om { 
template <class T0> class MetaType
{
public:
    virtual MetaType<audio::Clip>* vfunc_00(int a1);
};
}

template <> om::MetaType<audio::Clip>* om::MetaType<audio::Clip>::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772728;
    sub_006ECB50();
    if (a1 & 1) {
        sub_006EC7B0((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] om::MetaType<audio::Sequence>::vfunc_00 (0x006EEB50, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::MetaType<audio::SeqEvent>::vfunc_00 (0x002D0EA0), which was matched first;
// its addresses and names were swapped for this function's.
// om::MetaType<audio::Sequence>::vfunc_00 (0x006EEB50, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772738[];
extern "C" void __cdecl sub_006EC7B0(int);
extern "C" void __cdecl sub_006ECB50(void);

namespace audio { class Sequence; }

namespace om { 
template <class T0> class MetaType
{
public:
    virtual MetaType<audio::Sequence>* vfunc_00(int a1);
};
}

template <> om::MetaType<audio::Sequence>* om::MetaType<audio::Sequence>::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772738;
    sub_006ECB50();
    if (a1 & 1) {
        sub_006EC7B0((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] sub_006EEB80 (0x006EEB80, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EEB80 (0x006EEB80, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006ECAC0(int, int);
};

extern "C" char DAT_00772718[];
extern "C" char DAT_00772748[];
extern "C" int DAT_0085CEDC;
extern "C" int __cdecl sub_006EC7A0(int);

class Class_006EEB80
{
public:
    Class_006EEB80* sub_006EEB80(int a1, int a2, int a3, int a4);
    void sub_006ED350(int, int, int, int);
    int m_Field00; // +0x00
};

Class_006EEB80* Class_006EEB80::sub_006EEB80(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_006ED350(a1, a2, a3, a4);
    m_Field00 = (int)DAT_00772748;
    t2 = sub_006EC7A0(88);
    if (t2) {
        ((Object*)t2)->sub_006ECAC0(a1, 0);
        *(int*)t2 = (int)DAT_00772718;
        DAT_0085CEDC = t2;
        return this;
    }
    DAT_0085CEDC = 0;
    return this;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Mix>::vfunc_03 (0x006EEBF0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_03 (0x002D0FD0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Mix>::vfunc_03 (0x006EEBF0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007C1624[];

namespace audio { class Mix; }

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

template <> void* om::EntityType<audio::Mix>::vfunc_03()
{
    return DAT_007C1624;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Mix>::vfunc_02 (0x006EEC00, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_02 (0x002D0FE0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Mix>::vfunc_02 (0x006EEC00, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085CEDC;

namespace audio { class Mix; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
};
}

template <> int om::EntityType<audio::Mix>::vfunc_02()
{
    return DAT_0085CEDC;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Mix>::vfunc_01 (0x006EEC10, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_01 (0x002D0FF0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Mix>::vfunc_01 (0x006EEC10, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006F6020(int);
};

extern "C" int DAT_00811DA8;
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class Mix; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
};
}

template <> int om::EntityType<audio::Mix>::vfunc_01(int a1)
{
    int r_eax;

    r_eax = DAT_00811DA8;
    if (r_eax) {
        r_eax += 4;
    } else {
        r_eax = 0;
    }
    r_eax = sub_006EE870(r_eax);
    if (r_eax) {
        return ((Object*)r_eax)->sub_006F6020(a1);
    }
    r_eax = 0;
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_006EEC40 (0x006EEC40, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EEC40 (0x006EEC40, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006ECAC0(int, int);
};

extern "C" char DAT_00772728[];
extern "C" char DAT_0077275C[];
extern "C" int DAT_0085CEE0;
extern "C" int __cdecl sub_006EC7A0(int);

class Class_006EEC40
{
public:
    Class_006EEC40* sub_006EEC40(int a1, int a2, int a3, int a4);
    void sub_006ED350(int, int, int, int);
    int m_Field00; // +0x00
};

Class_006EEC40* Class_006EEC40::sub_006EEC40(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_006ED350(a1, a2, a3, a4);
    m_Field00 = (int)DAT_0077275C;
    t2 = sub_006EC7A0(88);
    if (t2) {
        ((Object*)t2)->sub_006ECAC0(a1, 0);
        *(int*)t2 = (int)DAT_00772728;
        DAT_0085CEE0 = t2;
        return this;
    }
    DAT_0085CEE0 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Clip>::vfunc_03 (0x006EECB0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_03 (0x002D0FD0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Clip>::vfunc_03 (0x006EECB0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007C6038[];

namespace audio { class Clip; }

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

template <> void* om::EntityType<audio::Clip>::vfunc_03()
{
    return DAT_007C6038;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Clip>::vfunc_02 (0x006EECC0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_02 (0x002D0FE0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Clip>::vfunc_02 (0x006EECC0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085CEE0;

namespace audio { class Clip; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
};
}

template <> int om::EntityType<audio::Clip>::vfunc_02()
{
    return DAT_0085CEE0;
}

// [TODO] 0x006EECD0 om::EntityType<audio::Clip>::vfunc_01 (69 B)
// ============================================================================
// [VERIFIED] audio::Clip::vfunc_12 (0x006EED20, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::MemoryAllocatorMalloc::vfunc_12 (0x0028D100), which was matched first;
// its addresses and names were swapped for this function's.
// audio::Clip::vfunc_12 (0x006EED20, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085CED0;

namespace audio {

class Clip
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual int vfunc_12();
};

int Clip::vfunc_12()
{
    return DAT_0085CED0;
}

}

// [TODO] 0x006EED30 audio::Clip::vfunc_03 (61 B)
// ============================================================================
// [VERIFIED] sub_006EED70 (0x006EED70, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EED70 (0x006EED70, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006ECAC0(int, int);
};

extern "C" char DAT_00772738[];
extern "C" char DAT_007727A8[];
extern "C" int DAT_0085CEE4;
extern "C" int __cdecl sub_006EC7A0(int);

class Class_006EED70
{
public:
    Class_006EED70* sub_006EED70(int a1, int a2, int a3, int a4);
    void sub_006ED350(int, int, int, int);
    int m_Field00; // +0x00
};

Class_006EED70* Class_006EED70::sub_006EED70(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_006ED350(a1, a2, a3, a4);
    m_Field00 = (int)DAT_007727A8;
    t2 = sub_006EC7A0(88);
    if (t2) {
        ((Object*)t2)->sub_006ECAC0(a1, 0);
        *(int*)t2 = (int)DAT_00772738;
        DAT_0085CEE4 = t2;
        return this;
    }
    DAT_0085CEE4 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Sequence>::vfunc_03 (0x006EEDE0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_03 (0x002D0FD0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Sequence>::vfunc_03 (0x006EEDE0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007C1604[];

namespace audio { class Sequence; }

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

template <> void* om::EntityType<audio::Sequence>::vfunc_03()
{
    return DAT_007C1604;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Sequence>::vfunc_02 (0x006EEDF0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_02 (0x002D0FE0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Sequence>::vfunc_02 (0x006EEDF0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085CEE4;

namespace audio { class Sequence; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
};
}

template <> int om::EntityType<audio::Sequence>::vfunc_02()
{
    return DAT_0085CEE4;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Sequence>::vfunc_01 (0x006EEE00, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_01 (0x002D0FF0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Sequence>::vfunc_01 (0x006EEE00, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006ED550(int);
};

extern "C" int DAT_00811D78;
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class Sequence; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
};
}

template <> int om::EntityType<audio::Sequence>::vfunc_01(int a1)
{
    int r_eax;

    r_eax = DAT_00811D78;
    if (r_eax) {
        r_eax += 4;
    } else {
        r_eax = 0;
    }
    r_eax = sub_006EE870(r_eax);
    if (r_eax) {
        return ((Object*)r_eax)->sub_006ED550(a1);
    }
    r_eax = 0;
    return r_eax;
}

// ============================================================================
// [VERIFIED] sub_006EF160 (0x006EF160, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EF160 (0x006EF160, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F69B4[];
extern "C" void __stdcall sub_006EE870(int);

class Class_006EF160
{
public:
    void sub_006EF160(int a1);
};

void Class_006EF160::sub_006EF160(int a1)
{
    a1 = (int)DAT_007F69B4;
    sub_006EE870(a1);
}

// ============================================================================
// [VERIFIED] sub_006EF170 (0x006EF170, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EF170 (0x006EF170, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F69B4[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006EF170(int a1)
{
    sub_006EE890((int)DAT_007F69B4, a1);
}

// [TODO] 0x006EF190 sub_006EF190 (222 B)
// [TODO] 0x006EF290 sub_006EF290 (6 B)
// ============================================================================
// [VERIFIED] sub_006EF360 (0x006EF360, 10 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00011710 (0x00011710), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EF360 (0x006EF360, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0085D12C;

bool __cdecl sub_006EF360(bool a1)
{
    DAT_0085D12C = a1;
    return a1;
}

// [TODO] 0x006EF370 sub_006EF370 (83 B)
// [TODO] 0x006EF3D0 sub_006EF3D0 (157 B)
// [TODO] 0x006EF470 sub_006EF470 (208 B)
// [TODO] 0x006EF540 sub_006EF540 (292 B)
// [TODO] 0x006EF670 sub_006EF670 (539 B)
// [TODO] 0x006EF8F0 sub_006EF8F0 (9 B)
// [TODO] 0x006EF900 sub_006EF900 (27 B)
// [TODO] 0x006EF970 sub_006EF970 (8 B)
// ============================================================================
// [VERIFIED] sub_006EF980 (0x006EF980, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002E0C0 (0x0002E0C0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EF980 (0x006EF980, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006EF980(int a1)
{
    return *(int*)(a1 + 16);
}

// [TODO] 0x006EF990 sub_006EF990 (12 B)
// [TODO] 0x006EF9A0 sub_006EF9A0 (34 B)
// [TODO] 0x006EF9E0 sub_006EF9E0 (35 B)
// [TODO] 0x006EFA10 sub_006EFA10 (61 B)
// [TODO] 0x006EFA50 sub_006EFA50 (12 B)
// [TODO] 0x006EFA60 sub_006EFA60 (256 B)
// ============================================================================
// [VERIFIED] sub_006EFB60 (0x006EFB60, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0002E0B0 (0x0002E0B0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006EFB60 (0x006EFB60, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006EFB60(int a1)
{
    return *(int*)(a1 + 8);
}

// [TODO] 0x006EFB70 sub_006EFB70 (12 B)
// [TODO] 0x006EFB80 sub_006EFB80 (12 B)
// [TODO] 0x006EFB90 sub_006EFB90 (94 B)
// [TODO] 0x006EFBF0 sub_006EFBF0 (136 B)
// [TODO] 0x006EFC80 sub_006EFC80 (13 B)
// [TODO] 0x006EFC90 sub_006EFC90 (11 B)
// [TODO] 0x006EFCB0 sub_006EFCB0 (44 B)
// [TODO] 0x006EFCE0 sub_006EFCE0 (8 B)
// [TODO] 0x006EFCF0 sub_006EFCF0 (61 B)
// [TODO] 0x006EFD30 sub_006EFD30 (12 B)
// [TODO] 0x006EFD40 sub_006EFD40 (43 B)
// [TODO] 0x006EFD70 sub_006EFD70 (143 B)
// [TODO] 0x006EFE00 sub_006EFE00 (205 B)
// [TODO] 0x006EFF60 sub_006EFF60 (86 B)
// [TODO] 0x006F0210 sub_006F0210 (445 B)
// ============================================================================
// [VERIFIED] om::MetaType<audio::LayerTemplate>::vfunc_00 (0x006F03D0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::MetaType<audio::SeqEvent>::vfunc_00 (0x002D0EA0), which was matched first;
// its addresses and names were swapped for this function's.
// om::MetaType<audio::LayerTemplate>::vfunc_00 (0x006F03D0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007728D0[];
extern "C" void __cdecl sub_006EC7B0(int);
extern "C" void __cdecl sub_006ECB50(void);

namespace audio { class LayerTemplate; }

namespace om { 
template <class T0> class MetaType
{
public:
    virtual MetaType<audio::LayerTemplate>* vfunc_00(int a1);
};
}

template <> om::MetaType<audio::LayerTemplate>* om::MetaType<audio::LayerTemplate>::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_007728D0;
    sub_006ECB50();
    if (a1 & 1) {
        sub_006EC7B0((int)this);
    }
    return this;
}

// [TODO] 0x006F0400 audio::LayerTemplate::vfunc_06 (45 B)
// ============================================================================
// [VERIFIED] audio::LayerTemplate::vfunc_12 (0x006F04A0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::MemoryAllocatorMalloc::vfunc_12 (0x0028D100), which was matched first;
// its addresses and names were swapped for this function's.
// audio::LayerTemplate::vfunc_12 (0x006F04A0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00811D7C;

namespace audio {

class LayerTemplate
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual int vfunc_12();
};

int LayerTemplate::vfunc_12()
{
    return DAT_00811D7C;
}

}

// [TODO] 0x006F04B0 sub_006F04B0 (58 B)
// ============================================================================
// [VERIFIED] sub_006F04F0 (0x006F04F0, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F04F0 (0x006F04F0, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006ECAC0(int, int);
};

extern "C" char DAT_007728D0[];
extern "C" char DAT_00772918[];
extern "C" int DAT_0085D138;
extern "C" int __cdecl sub_006EC7A0(int);

class Class_006F04F0
{
public:
    Class_006F04F0* sub_006F04F0(int a1, int a2, int a3, int a4);
    void sub_006ED350(int, int, int, int);
    int m_Field00; // +0x00
};

Class_006F04F0* Class_006F04F0::sub_006F04F0(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_006ED350(a1, a2, a3, a4);
    m_Field00 = (int)DAT_00772918;
    t2 = sub_006EC7A0(88);
    if (t2) {
        ((Object*)t2)->sub_006ECAC0(a1, 0);
        *(int*)t2 = (int)DAT_007728D0;
        DAT_0085D138 = t2;
        return this;
    }
    DAT_0085D138 = 0;
    return this;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::LayerTemplate>::vfunc_03 (0x006F0560, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_03 (0x002D0FD0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::LayerTemplate>::vfunc_03 (0x006F0560, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F6A1C[];

namespace audio { class LayerTemplate; }

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

template <> void* om::EntityType<audio::LayerTemplate>::vfunc_03()
{
    return DAT_007F6A1C;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::LayerTemplate>::vfunc_02 (0x006F0570, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_02 (0x002D0FE0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::LayerTemplate>::vfunc_02 (0x006F0570, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085D138;

namespace audio { class LayerTemplate; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
};
}

template <> int om::EntityType<audio::LayerTemplate>::vfunc_02()
{
    return DAT_0085D138;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::LayerTemplate>::vfunc_01 (0x006F0580, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_01 (0x002D0FF0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::LayerTemplate>::vfunc_01 (0x006F0580, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006F0430(int);
};

extern "C" int DAT_00811D7C;
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class LayerTemplate; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
};
}

template <> int om::EntityType<audio::LayerTemplate>::vfunc_01(int a1)
{
    int r_eax;

    r_eax = DAT_00811D7C;
    if (r_eax) {
        r_eax += 4;
    } else {
        r_eax = 0;
    }
    r_eax = sub_006EE870(r_eax);
    if (r_eax) {
        return ((Object*)r_eax)->sub_006F0430(a1);
    }
    r_eax = 0;
    return r_eax;
}

// [TODO] 0x006F05B0 sub_006F05B0 (92 B)
// [TODO] 0x006F0610 audio::LayerTemplate::vfunc_03 (99 B)
// [TODO] 0x006F0680 sub_006F0680 (766 B)
// ============================================================================
// [VERIFIED] sub_006F0990 (0x006F0990, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F0990 (0x006F0990, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F6BB4[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006F0990(int a1)
{
    sub_006EE890((int)DAT_007F6BB4, a1);
}

// [TODO] 0x006F09B0 audio::StreamPlayerAllocator::vfunc_00 (44 B)
// [TODO] 0x006F09E0 audio::StreamPlayerAllocator::vfunc_01 (14 B)
// [TODO] 0x006F0A70 sub_006F0A70 (123 B)
// [TODO] 0x006F0AF0 sub_006F0AF0 (311 B)
// [TODO] 0x006F0C30 sub_006F0C30 (122 B)
// [TODO] 0x006F0D00 sub_006F0D00 (97 B)
// [TODO] 0x006F0D70 sub_006F0D70 (103 B)
// [TODO] 0x006F0DE0 om::TRbTree<audio::SeqPlayerTrack, 0>::Comp<audio::SeqPlayerTrack, 0, om::Name<om::CaseSensitive32BitKey>>::vfunc_00 (34 B)
// [TODO] 0x006F0E10 om::TRbTree<audio::SeqPlayerLayer, 0>::Comp<audio::SeqPlayerLayer, 0, om::Name<om::CaseSensitive32BitKey>>::vfunc_00 (29 B)
// [TODO] 0x006F0F30 sub_006F0F30 (189 B)
// [TODO] 0x006F0FF0 sub_006F0FF0 (128 B)
// ============================================================================
// [VERIFIED] sub_006F1070 (0x006F1070, 34 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D2970 (0x002D2970), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F1070 (0x006F1070, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field2C
{
    int sub_006F0D00(int);
};

class Class_006F1070
{
public:
    void sub_006F1070(int a1);
    void sub_006F0FF0(int);
    char m_pad00[0x2C];
    Field2C m_Field2C; // +0x2C
};

void Class_006F1070::sub_006F1070(int a1)
{
    if (!m_Field2C.sub_006F0D00(a1)) {
        sub_006F0FF0(a1);
    }
}

// [TODO] 0x006F1340 sub_006F1340 (10 B)
// [TODO] 0x006F1350 sub_006F1350 (51 B)
// [TODO] 0x006F1390 sub_006F1390 (15 B)
// [TODO] 0x006F13A0 sub_006F13A0 (29 B)
// [TODO] 0x006F13C0 sub_006F13C0 (20 B)
// [TODO] 0x006F13E0 sub_006F13E0 (34 B)
// [TODO] 0x006F1410 sub_006F1410 (41 B)
// [TODO] 0x006F1440 sub_006F1440 (40 B)
// [TODO] 0x006F1490 sub_006F1490 (71 B)
// [TODO] 0x006F1560 sub_006F1560 (111 B)
// [TODO] 0x006F15D0 sub_006F15D0 (10 B)
// [TODO] 0x006F1600 sub_006F1600 (50 B)
// [TODO] 0x006F1640 sub_006F1640 (37 B)
// [TODO] 0x006F1670 sub_006F1670 (72 B)
// [TODO] 0x006F16C0 sub_006F16C0 (11 B)
// [TODO] 0x006F16E0 sub_006F16E0 (16 B)
// [TODO] 0x006F16F0 sub_006F16F0 (16 B)
// [TODO] 0x006F1700 sub_006F1700 (16 B)
// [TODO] 0x006F1710 sub_006F1710 (16 B)
// [TODO] 0x006F1720 sub_006F1720 (16 B)
// [TODO] 0x006F1730 sub_006F1730 (16 B)
// [TODO] 0x006F1740 sub_006F1740 (11 B)
// [TODO] 0x006F1750 sub_006F1750 (139 B)
// [TODO] 0x006F17E0 sub_006F17E0 (22 B)
// [TODO] 0x006F1800 sub_006F1800 (12 B)
// [TODO] 0x006F1810 sub_006F1810 (45 B)
// [TODO] 0x006F1840 sub_006F1840 (20 B)
// [TODO] 0x006F1860 sub_006F1860 (72 B)
// [TODO] 0x006F18B0 sub_006F18B0 (111 B)
// [TODO] 0x006F1920 sub_006F1920 (9 B)
// [TODO] 0x006F1CB0 sub_006F1CB0 (312 B)
// [TODO] 0x006F1DF0 sub_006F1DF0 (85 B)
// [TODO] 0x006F1E50 sub_006F1E50 (17 B)
// [TODO] 0x006F1EF0 sub_006F1EF0 (396 B)
// [TODO] 0x006F2080 sub_006F2080 (357 B)
// [TODO] 0x006F21F0 sub_006F21F0 (127 B)
// [TODO] 0x006F2270 sub_006F2270 (8 B)
// [TODO] 0x006F22D0 sub_006F22D0 (58 B)
// [TODO] 0x006F2310 sub_006F2310 (22 B)
// [TODO] 0x006F2330 sub_006F2330 (71 B)
// [TODO] 0x006F2380 sub_006F2380 (34 B)
// [TODO] 0x006F23B0 sub_006F23B0 (51 B)
// [TODO] 0x006F23F0 sub_006F23F0 (62 B)
// [TODO] 0x006F2430 sub_006F2430 (21 B)
// [TODO] 0x006F2450 sub_006F2450 (27 B)
// [TODO] 0x006F2470 sub_006F2470 (75 B)
// [TODO] 0x006F24C0 sub_006F24C0 (75 B)
// [TODO] 0x006F2510 sub_006F2510 (91 B)
// [TODO] 0x006F2570 sub_006F2570 (80 B)
// [TODO] 0x006F25C0 sub_006F25C0 (55 B)
// [TODO] 0x006F2600 sub_006F2600 (603 B)
// [TODO] 0x006F2860 sub_006F2860 (439 B)
// [TODO] 0x006F2A20 sub_006F2A20 (19 B)
// [TODO] 0x006F2A40 sub_006F2A40 (168 B)
// [TODO] 0x006F2B30 sub_006F2B30 (151 B)
// ============================================================================
// [VERIFIED] sub_006F2BD0 (0x006F2BD0, 37 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D4D20 (0x002D4D20), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F2BD0 (0x006F2BD0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006F2BD0
{
public:
    int sub_006F2BD0(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

int Class_006F2BD0::sub_006F2BD0(int a1)
{
    int t1;

    *(int*)(a1 + 4) = 0;
    *(int*)a1 = m_Field00;
    t1 = m_Field00;
    if (m_Field00) {
        *(int*)(t1 + 4) = a1;
        m_Field00 = a1;
        return a1;
    }
    m_Field04 = a1;
    m_Field00 = a1;
    return a1;
}

// [TODO] 0x006F2C00 sub_006F2C00 (53 B)
// [TODO] 0x006F2C40 sub_006F2C40 (47 B)
// [TODO] 0x006F2C70 sub_006F2C70 (18 B)
// [TODO] 0x006F2C90 sub_006F2C90 (116 B)
// [TODO] 0x006F2EF0 om::SparksHeap::vfunc_00 (14 B)
// ============================================================================
// [VERIFIED] sub_006F2F00 (0x006F2F00, 33 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D5430 (0x002D5430), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F2F00 (0x006F2F00, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772770[];
extern "C" int __cdecl sub_006EFF60(int);

class Class_006F2F00
{
public:
    void sub_006F2F00();
    void sub_006ED0C0();
    int m_Field00; // +0x00
    char m_pad04[0x24];
    int m_Field28; // +0x28
};

void Class_006F2F00::sub_006F2F00()
{
    int r_eax;

    r_eax = m_Field28;
    m_Field00 = (int)DAT_00772770;
    if (r_eax) {
        r_eax = sub_006EFF60(r_eax);
    }
    sub_006ED0C0();
}

// [TODO] 0x006F2F30 sub_006F2F30 (451 B)
// [TODO] 0x006F3100 audio::Clip::vfunc_06 (143 B)
// [TODO] 0x006F3260 om::TRbTree<om::MetaAttribBase, 4>::Comp<om::MetaAttribBase, 4, const char*>::vfunc_00 (71 B)
// [TODO] 0x006F32B0 sub_006F32B0 (52 B)
// [TODO] 0x006F3300 sub_006F3300 (44 B)
// [TODO] 0x006F3330 sub_006F3330 (31 B)
// [TODO] 0x006F3350 sub_006F3350 (21 B)
// [TODO] 0x006F3370 sub_006F3370 (19 B)
// [TODO] 0x006F33D0 sub_006F33D0 (21 B)
// [TODO] 0x006F33F0 sub_006F33F0 (19 B)
// [TODO] 0x006F3410 sub_006F3410 (19 B)
// [TODO] 0x006F3430 sub_006F3430 (21 B)
// [TODO] 0x006F3460 audio::HalRsdFileStream::vfunc_00 (67 B)
// [TODO] 0x006F34B0 audio::HalRsdFileStream::vfunc_05 (61 B)
// [TODO] 0x006F34F0 audio::HalRsdFileStream::vfunc_01 (68 B)
// ============================================================================
// [VERIFIED] audio::HalRsdFileStream::vfunc_03 (0x006F3540, 41 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::HalRsdFileStream::vfunc_03 (0x002D64B0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::HalRsdFileStream::vfunc_03 (0x006F3540, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F1390(int);
extern "C" int __cdecl sub_006F13A0(int);

namespace audio {

class HalRsdFileStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
    char m_pad04[0x24];
    int m_Field28; // +0x28
};

int HalRsdFileStream::vfunc_03()
{
    if (sub_006F1390(m_Field28 & 15)) {
        return sub_006F13A0((int)(&m_Field28));
    }
    return 2048;
}

}

// [TODO] 0x006F3570 audio::HalRsdFileStream::vfunc_09 (32 B)
// ============================================================================
// [VERIFIED] audio::HalRsdFileStream::vfunc_10 (0x006F3590, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::CementLibrary::vfunc_01 (0x002ACEB0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::HalRsdFileStream::vfunc_10 (0x006F3590, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006EB6D0();
};

namespace audio {

class HalRsdFileStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_10();
};

void HalRsdFileStream::vfunc_10()
{
    ((Object*)(int)this + 16)->sub_006EB6D0();
}

}

// [TODO] 0x006F35A0 audio::HalRsdFileStream::vfunc_07 (117 B)
// [TODO] 0x006F3620 audio::HalRsdFileStream::vfunc_06 (79 B)
// [TODO] 0x006F3670 audio::HalRsdFileStream::vfunc_08 (32 B)
// [TODO] 0x006F36E0 audio::HalRsdFileStream::vfunc_11 (255 B)
// [TODO] 0x006F37E0 sub_006F37E0 (58 B)
// [TODO] 0x006F3820 sub_006F3820 (155 B)
// [TODO] 0x006F38C0 audio::HalRsdFileStream::vfunc_15 (45 B)
// [TODO] 0x006F38F0 sub_006F38F0 (154 B)
// [TODO] 0x006F3990 audio::HalRsdFileStream::vfunc_12 (77 B)
// [TODO] 0x006F39E0 sub_006F39E0 (66 B)
// [TODO] 0x006F3A30 sub_006F3A30 (116 B)
// [TODO] 0x006F3AB0 sub_006F3AB0 (19 B)
// [TODO] 0x006F3AD0 sub_006F3AD0 (15 B)
// [TODO] 0x006F3AE0 sub_006F3AE0 (82 B)
// [TODO] 0x006F3B40 sub_006F3B40 (204 B)
// [TODO] 0x006F3C10 sub_006F3C10 (57 B)
// [TODO] 0x006F3C50 sub_006F3C50 (51 B)
// [TODO] 0x006F3C90 sub_006F3C90 (146 B)
// [TODO] 0x006F3D30 sub_006F3D30 (61 B)
// [TODO] 0x006F3D70 sub_006F3D70 (11 B)
// [TODO] 0x006F3E30 sub_006F3E30 (181 B)
// [TODO] 0x006F4010 sub_006F4010 (595 B)
// [TODO] 0x006F4270 sub_006F4270 (59 B)
// [TODO] 0x006F42B0 sub_006F42B0 (1156 B)
// [TODO] 0x006F4740 sub_006F4740 (568 B)
// [TODO] 0x006F4980 sub_006F4980 (131 B)
// [TODO] 0x006F4A10 sub_006F4A10 (104 B)
// [TODO] 0x006F4A80 sub_006F4A80 (105 B)
// [TODO] 0x006F4AF0 sub_006F4AF0 (270 B)
// [TODO] 0x006F4C00 sub_006F4C00 (225 B)
// [TODO] 0x006F4D00 audio::OggVorbisStream::vfunc_00 (40 B)
// ============================================================================
// [VERIFIED] audio::OggVorbisStream::vfunc_12 (0x006F4D30, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::HalRadicalAdpcmDecodeStream::vfunc_12 (0x002E0A30), which was matched first;
// its addresses and names were swapped for this function's.
// audio::OggVorbisStream::vfunc_12 (0x006F4D30, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class OggVorbisStream
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17(int);
};

void OggVorbisStream::vfunc_12()
{
    if (this) {
        vfunc_17(1);
    }
}

}

// [TODO] 0x006F4D40 audio::OggVorbisStream::vfunc_05 (54 B)
// [TODO] 0x006F4D80 audio::OggVorbisStream::vfunc_01 (7 B)
// [TODO] 0x006F4D90 audio::OggVorbisStream::vfunc_02 (7 B)
// [TODO] 0x006F4DA0 audio::OggVorbisStream::vfunc_03 (15 B)
// ============================================================================
// [VERIFIED] AirplanePlaneCollisionReceiver::vfunc_00 (0x006F4DB0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AirplanePlaneCollisionReceiver::vfunc_00 (0x0009B2D0), which was matched first;
// its addresses and names were swapped for this function's.
// AirplanePlaneCollisionReceiver::vfunc_00 (0x006F4DB0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field04
{
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
};

class AirplanePlaneCollisionReceiver
{
public:
    virtual void vfunc_00();
    Field04* m_Field04; // +0x04
};

void AirplanePlaneCollisionReceiver::vfunc_00()
{
    m_Field04->vfunc_09();
}

// [TODO] 0x006F4DC0 audio::OggVorbisStream::vfunc_10 (8 B)
// [TODO] 0x006F4DD0 audio::OggVorbisStream::vfunc_04 (13 B)
// [TODO] 0x006F4DE0 audio::OggVorbisStream::vfunc_06 (117 B)
// [TODO] 0x006F4E60 audio::OggVorbisStream::vfunc_08 (27 B)
// [TODO] 0x006F4F10 sub_006F4F10 (73 B)
// [TODO] 0x006F4F60 audio::OggVorbisStream::vfunc_17 (95 B)
// [TODO] 0x006F4FC0 sub_006F4FC0 (53 B)
// [TODO] 0x006F5000 sub_006F5000 (33 B)
// [TODO] 0x006F5030 audio::OggVorbisStream::vfunc_11 (414 B)
// [TODO] 0x006F51D0 sub_006F51D0 (137 B)
// [TODO] 0x006F5260 sub_006F5260 (298 B)
// [TODO] 0x006F5390 audio::HalRadicalAdpcmDecodeStream::vfunc_11 (212 B)
// [TODO] 0x006F5470 audio::HalRadicalAdpcmDecodeStream::vfunc_08 (65 B)
// [TODO] 0x006F54C0 audio::HalRadicalAdpcmDecodeStream::vfunc_00 (32 B)
// [TODO] 0x006F54E0 audio::HalRadicalAdpcmDecodeStream::vfunc_01 (56 B)
// [TODO] 0x006F5520 audio::HalRadicalAdpcmDecodeStream::vfunc_03 (56 B)
// [TODO] 0x006F5560 audio::HalRadicalAdpcmDecodeStream::vfunc_04 (53 B)
// [TODO] 0x006F55A0 audio::HalRadicalAdpcmDecodeStream::vfunc_07 (82 B)
// [TODO] 0x006F5600 audio::HalRadicalAdpcmDecodeStream::vfunc_06 (89 B)
// [TODO] 0x006F5660 audio::HalRadicalAdpcmDecodeStream::vfunc_17 (44 B)
// [TODO] 0x006F5690 sub_006F5690 (72 B)
// [TODO] 0x006F56E0 sub_006F56E0 (69 B)
// ============================================================================
// [VERIFIED] sub_006F5730 (0x006F5730, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F5730 (0x006F5730, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00FB100C;

class Class_006F5730
{
public:
    void sub_006F5730();
};

void Class_006F5730::sub_006F5730()
{
    ((void (__cdecl*)(void))DAT_00FB100C)();
}

// ============================================================================
// [VERIFIED] audio::SeqEvent::vfunc_00 (0x006F5740, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEvent::vfunc_00 (0x002D6A00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEvent::vfunc_00 (0x006F5740, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006FF600(int, int);

namespace audio {

class SeqEvent
{
public:
    virtual void vfunc_00(int a1);
};

void SeqEvent::vfunc_00(int a1)
{
    sub_006FF600(a1, 0);
}

}

// [TODO] 0x006F5760 audio::SeqEvent::vfunc_01 (51 B)
// ============================================================================
// [VERIFIED] sub_006F57A0 (0x006F57A0, 15 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D6A60 (0x002D6A60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F57A0 (0x006F57A0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006F57A0
{
public:
    int sub_006F57A0(int a1, int a2);
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
};

int Class_006F57A0::sub_006F57A0(int a1, int a2)
{
    if (m_Field0C != a1) {
        m_Field0C = a1;
    }
    return a1;
}

// [TODO] 0x006F57B0 audio::SeqActionChannelSendVolumes::vfunc_05 (38 B)
// [TODO] 0x006F57E0 audio::SeqActionChannelSendVolumes::vfunc_02 (16 B)
// [TODO] 0x006F57F0 audio::SeqActionChannelSendVolumes::vfunc_01 (32 B)
// [TODO] 0x006F5810 audio::SeqActionChannelSendVolumes::vfunc_03 (16 B)
// [TODO] 0x006F5820 audio::SeqActionChannelSendVolumes::vfunc_04 (16 B)
// ============================================================================
// [VERIFIED] audio::SeqEvent::vfunc_04 (0x006F5830, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::BaseObject::vfunc_00 (0x00026BB0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEvent::vfunc_04 (0x006F5830, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772DC8[];
extern "C" void __cdecl sub_0043CE70(int);

namespace audio {

class SeqEvent
{
public:
    virtual SeqEvent* vfunc_04(int a1);
};

SeqEvent* SeqEvent::vfunc_04(int a1)
{
    *(int*)this = (int)DAT_00772DC8;
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] sub_006F5850 (0x006F5850, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00087E60 (0x00087E60), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F5850 (0x006F5850, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772DC8[];

class Class_006F5850
{
public:
    Class_006F5850* sub_006F5850();
    int m_Field00; // +0x00
};

Class_006F5850* Class_006F5850::sub_006F5850()
{
    m_Field00 = (int)DAT_00772DC8;
    return this;
}

// [TODO] 0x006F5860 sub_006F5860 (227 B)
// [TODO] 0x006F5950 om::TRbTree<audio::SeqEventTypeBase, 4>::Comp<audio::SeqEventTypeBase, 4, om::String>::vfunc_00 (86 B)
// [TODO] 0x006F59B0 sub_006F59B0 (40 B)
// [TODO] 0x006F59E0 sub_006F59E0 (119 B)
// [TODO] 0x006F5A60 audio::SeqEventContainer::vfunc_00 (90 B)
// [TODO] 0x006F5AC0 audio::SeqEventContainer::vfunc_01 (173 B)
// [TODO] 0x006F5B70 audio::SeqEventContainer::vfunc_05 (59 B)
// [TODO] 0x006F5BB0 sub_006F5BB0 (21 B)
// [TODO] 0x006F5C10 audio::SeqEventTypeBase::vfunc_00 (61 B)
// [TODO] 0x006F5C50 sub_006F5C50 (61 B)
// ============================================================================
// [VERIFIED] audio::SeqEventContainer::vfunc_04 (0x006F5C90, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventContainer::vfunc_04 (0x006F5C90, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006F5C50(void);
extern "C" void __cdecl sub_0043CE70(int);

namespace audio {

class SeqEventContainer
{
public:
    virtual SeqEventContainer* vfunc_04(int a1);
};

SeqEventContainer* SeqEventContainer::vfunc_04(int a1)
{
    sub_006F5C50();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] sub_006F5CB0 (0x006F5CB0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F5CB0 (0x006F5CB0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F6E60[];
extern "C" void __stdcall sub_006EE870(int);

class Class_006F5CB0
{
public:
    void sub_006F5CB0(int a1);
};

void Class_006F5CB0::sub_006F5CB0(int a1)
{
    a1 = (int)DAT_007F6E60;
    sub_006EE870(a1);
}

// ============================================================================
// [VERIFIED] sub_006F5CC0 (0x006F5CC0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F5CC0 (0x006F5CC0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F6E60[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006F5CC0(int a1)
{
    sub_006EE890((int)DAT_007F6E60, a1);
}

// [TODO] 0x006F5CE0 sub_006F5CE0 (130 B)
// [TODO] 0x006F5D70 sub_006F5D70 (291 B)
// [TODO] 0x006F5EA0 sub_006F5EA0 (190 B)
// ============================================================================
// [VERIFIED] sub_006F5F60 (0x006F5F60, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D7240 (0x002D7240), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F5F60 (0x006F5F60, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F2C00(int);
};

class Class_006F5F60
{
public:
    void sub_006F5F60(int a1);
};

void Class_006F5F60::sub_006F5F60(int a1)
{
    a1 = a1 + 20;
    ((Object*)(int)this + 40)->sub_006F2C00(a1);
}

// ============================================================================
// [VERIFIED] sub_006F5F80 (0x006F5F80, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D7240 (0x002D7240), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F5F80 (0x006F5F80, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F2C40(int);
};

class Class_006F5F80
{
public:
    void sub_006F5F80(int a1);
};

void Class_006F5F80::sub_006F5F80(int a1)
{
    a1 = a1 + 20;
    ((Object*)(int)this + 40)->sub_006F2C40(a1);
}

// [TODO] 0x006F5FA0 sub_006F5FA0 (53 B)
// [TODO] 0x006F5FE0 sub_006F5FE0 (53 B)
// ============================================================================
// [VERIFIED] audio::Mix::vfunc_12 (0x006F6060, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::MemoryAllocatorMalloc::vfunc_12 (0x0028D100), which was matched first;
// its addresses and names were swapped for this function's.
// audio::Mix::vfunc_12 (0x006F6060, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00811DA8;

namespace audio {

class Mix
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual int vfunc_12();
};

int Mix::vfunc_12()
{
    return DAT_00811DA8;
}

}

// ============================================================================
// [VERIFIED] sub_006F6070 (0x006F6070, 38 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D7350 (0x002D7350), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_006EE060();
};

// The links sit 0x10 bytes into each item.
struct Link
{
    Link* next;
};

struct Item
{
    char m_pad00[0x10];
    Link m_link;       // +0x10
    char m_pad14[0xC];
    Object* m_object;  // +0x20
};

static inline Item* ItemOf(Link* link)
{
    return link ? (Item*)((char*)link - 0x10) : 0;
}

class Class_006F6070
{
public:
    void sub_006F6070();

    char m_pad00[0x14];
    Link* m_first; // +0x14
};

// Walks the item list and calls the same method on each item's object.
void Class_006F6070::sub_006F6070()
{
    if (m_first) {
        for (Item* item = (Item*)((char*)m_first - 0x10); item; item = ItemOf(item->m_link.next))
            item->m_object->sub_006EE060();
    }
}

// ============================================================================
// [VERIFIED] sub_006F60A0 (0x006F60A0, 38 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D7350 (0x002D7350), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_006EE070();
};

// The links sit 0x10 bytes into each item.
struct Link
{
    Link* next;
};

struct Item
{
    char m_pad00[0x10];
    Link m_link;       // +0x10
    char m_pad14[0xC];
    Object* m_object;  // +0x20
};

static inline Item* ItemOf(Link* link)
{
    return link ? (Item*)((char*)link - 0x10) : 0;
}

class Class_006F60A0
{
public:
    void sub_006F60A0();

    char m_pad00[0x14];
    Link* m_first; // +0x14
};

// Walks the item list and calls the same method on each item's object.
void Class_006F60A0::sub_006F60A0()
{
    if (m_first) {
        for (Item* item = (Item*)((char*)m_first - 0x10); item; item = ItemOf(item->m_link.next))
            item->m_object->sub_006EE070();
    }
}

// ============================================================================
// [VERIFIED] sub_006F60D0 (0x006F60D0, 38 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D7350 (0x002D7350), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_006EE080();
};

// The links sit 0x10 bytes into each item.
struct Link
{
    Link* next;
};

struct Item
{
    char m_pad00[0x10];
    Link m_link;       // +0x10
    char m_pad14[0xC];
    Object* m_object;  // +0x20
};

static inline Item* ItemOf(Link* link)
{
    return link ? (Item*)((char*)link - 0x10) : 0;
}

class Class_006F60D0
{
public:
    void sub_006F60D0();

    char m_pad00[0x14];
    Link* m_first; // +0x14
};

// Walks the item list and calls the same method on each item's object.
void Class_006F60D0::sub_006F60D0()
{
    if (m_first) {
        for (Item* item = (Item*)((char*)m_first - 0x10); item; item = ItemOf(item->m_link.next))
            item->m_object->sub_006EE080();
    }
}

// ============================================================================
// [VERIFIED] sub_006F6100 (0x006F6100, 38 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D7350 (0x002D7350), which was matched first;
// its addresses and names were swapped for this function's.
struct Object
{
    void sub_006EE090();
};

// The links sit 0x10 bytes into each item.
struct Link
{
    Link* next;
};

struct Item
{
    char m_pad00[0x10];
    Link m_link;       // +0x10
    char m_pad14[0xC];
    Object* m_object;  // +0x20
};

static inline Item* ItemOf(Link* link)
{
    return link ? (Item*)((char*)link - 0x10) : 0;
}

class Class_006F6100
{
public:
    void sub_006F6100();

    char m_pad00[0x14];
    Link* m_first; // +0x14
};

// Walks the item list and calls the same method on each item's object.
void Class_006F6100::sub_006F6100()
{
    if (m_first) {
        for (Item* item = (Item*)((char*)m_first - 0x10); item; item = ItemOf(item->m_link.next))
            item->m_object->sub_006EE090();
    }
}

// [TODO] 0x006F6130 sub_006F6130 (66 B)
// [TODO] 0x006F6180 audio::MixStrip::vfunc_01 (143 B)
// [TODO] 0x006F6210 audio::Mix::vfunc_07 (158 B)
// [TODO] 0x006F62B0 om::TRbTree<audio::MixStrip, 4>::Comp<audio::MixStrip, 4, om::Name<om::CaseSensitive32BitKey>>::vfunc_00 (40 B)
// [TODO] 0x006F62E0 sub_006F62E0 (163 B)
// [TODO] 0x006F6390 sub_006F6390 (160 B)
// [TODO] 0x006F6430 sub_006F6430 (44 B)
// [TODO] 0x006F6460 audio::MixStrip::vfunc_00 (283 B)
// [TODO] 0x006F6580 audio::Mix::vfunc_06 (288 B)
// ============================================================================
// [VERIFIED] audio::Mix::vfunc_05 (0x006F66A0, 24 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::Mix::vfunc_05 (0x002D7990), which was matched first;
// its addresses and names were swapped for this function's.
// audio::Mix::vfunc_05 (0x006F66A0, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006F6430(void);

namespace audio {

class Mix
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    virtual void vfunc_06(int);
};

void Mix::vfunc_05(int a1)
{
    sub_006F6430();
    vfunc_06(a1);
}

}

// [TODO] 0x006F66C0 audio::Mix::vfunc_03 (74 B)
// ============================================================================
// [VERIFIED] om::MetaType<audio::ListenerEffectWin32>::vfunc_00 (0x006F6710, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::MetaType<audio::SeqEvent>::vfunc_00 (0x002D0EA0), which was matched first;
// its addresses and names were swapped for this function's.
// om::MetaType<audio::ListenerEffectWin32>::vfunc_00 (0x006F6710, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772E90[];
extern "C" void __cdecl sub_006EC7B0(int);
extern "C" void __cdecl sub_006ECB50(void);

namespace audio { class ListenerEffectWin32; }

namespace om { 
template <class T0> class MetaType
{
public:
    virtual MetaType<audio::ListenerEffectWin32>* vfunc_00(int a1);
};
}

template <> om::MetaType<audio::ListenerEffectWin32>* om::MetaType<audio::ListenerEffectWin32>::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772E90;
    sub_006ECB50();
    if (a1 & 1) {
        sub_006EC7B0((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] sub_006F6740 (0x006F6740, 102 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00065340 (0x00065340), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006F6740 (0x006F6740, 102 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006ECAC0(int, int);
};

extern "C" char DAT_00772E90[];
extern "C" char DAT_00772EA0[];
extern "C" int DAT_0085D4EC;
extern "C" int __cdecl sub_006EC7A0(int);

class Class_006F6740
{
public:
    Class_006F6740* sub_006F6740(int a1, int a2, int a3, int a4);
    void sub_006ED350(int, int, int, int);
    int m_Field00; // +0x00
};

Class_006F6740* Class_006F6740::sub_006F6740(int a1, int a2, int a3, int a4)
{
    int t2;

    sub_006ED350(a1, a2, a3, a4);
    m_Field00 = (int)DAT_00772EA0;
    t2 = sub_006EC7A0(88);
    if (t2) {
        ((Object*)t2)->sub_006ECAC0(a1, 0);
        *(int*)t2 = (int)DAT_00772E90;
        DAT_0085D4EC = t2;
        return this;
    }
    DAT_0085D4EC = 0;
    return this;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::ListenerEffectWin32>::vfunc_03 (0x006F67B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_03 (0x002D0FD0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::ListenerEffectWin32>::vfunc_03 (0x006F67B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007C5AF8[];

namespace audio { class ListenerEffectWin32; }

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

template <> void* om::EntityType<audio::ListenerEffectWin32>::vfunc_03()
{
    return DAT_007C5AF8;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::ListenerEffectWin32>::vfunc_02 (0x006F67C0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as om::EntityType<audio::Mix>::vfunc_02 (0x002D0FE0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::ListenerEffectWin32>::vfunc_02 (0x006F67C0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085D4EC;

namespace audio { class ListenerEffectWin32; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
};
}

template <> int om::EntityType<audio::ListenerEffectWin32>::vfunc_02()
{
    return DAT_0085D4EC;
}

// ============================================================================
// [VERIFIED] om::EntityType<audio::Mix>::vfunc_00 (0x006F67D0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_03 (0x000227A0), which was matched first;
// its addresses and names were swapped for this function's.
// om::EntityType<audio::Mix>::vfunc_00 (0x006F67D0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006ED0A0(void);
extern "C" void __cdecl sub_0043CE70(int);

namespace audio { class Mix; }

namespace om { 
template <class T0> class EntityType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual EntityType<audio::Mix>* vfunc_00(int a1);
};
}

template <> om::EntityType<audio::Mix>* om::EntityType<audio::Mix>::vfunc_00(int a1)
{
    sub_006ED0A0();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

// [TODO] 0x006F67F0 om::EntityType<audio::ListenerEffectWin32>::vfunc_01 (62 B)
// ============================================================================
// [VERIFIED] audio::ListenerEffectWin32::vfunc_12 (0x006F6830, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::MemoryAllocatorMalloc::vfunc_12 (0x0028D100), which was matched first;
// its addresses and names were swapped for this function's.
// audio::ListenerEffectWin32::vfunc_12 (0x006F6830, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00811DAC;

namespace audio {

class ListenerEffectWin32
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual int vfunc_12();
};

int ListenerEffectWin32::vfunc_12()
{
    return DAT_00811DAC;
}

}

// [TODO] 0x006F6840 audio::ListenerEffectWin32::vfunc_03 (61 B)
// [TODO] 0x006F6880 sub_006F6880 (155 B)
// ============================================================================
// [VERIFIED] audio::SeqEventNestTrack::vfunc_00 (0x006F6920, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_01 (0x002D8D00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventNestTrack::vfunc_00 (0x006F6920, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006ECC20(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventNestTrack
{
public:
    virtual void vfunc_00();
    virtual int vfunc_00(int a1);
};

int SeqEventNestTrack::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006ECC20(a1, (int)this + 8)) goto L_2D;
        return 1;
    }
L_2D:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventNestTrack::vfunc_03 (0x006F6960, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns a value kept in the game's data.
// ============================================================================
// bin: pc
// va: 0x006F6960
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventNestTrack::vfunc_03 (0x006F6960, 6 bytes)
extern "C" int DAT_0085D4F0;

namespace audio {

class SeqEventNestTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventNestTrack::vfunc_03()
{
    return DAT_0085D4F0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventNestTrack::vfunc_04 (0x006F6970, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_04 (0x002D8D90), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventNestTrack::vfunc_04 (0x006F6970, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_006EBBD0();
};

extern "C" char DAT_007F6FE8[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventNestTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventNestTrack* vfunc_04(int a1);
    void sub_006F5730();
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

SeqEventNestTrack* SeqEventNestTrack::vfunc_04(int a1)
{
    m_Field08.sub_006EBBD0();
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F6FE8, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F69A0 audio::SeqEventType<audio::SeqEventNestTrack>::vfunc_01 (88 B)
// ============================================================================
// [VERIFIED] sub_006F6A00 (0x006F6A00, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00772F2C[];
extern "C" char DAT_00772F50[];
extern "C" char DAT_00772F5C[];
extern "C" Object* DAT_0085D4F0;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F6A00(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_00772F5C, 0);
    second.sub_006EB7A0(DAT_00772F50, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00772F2C;
        DAT_0085D4F0 = made;
    } else {
        DAT_0085D4F0 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// [TODO] 0x006F6A80 audio::SeqEventNestTrack::vfunc_02 (130 B)
// ============================================================================
// [VERIFIED] audio::SeqAction::vfunc_00 (0x006F6B10, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::BaseObject::vfunc_00 (0x00026BB0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqAction::vfunc_00 (0x006F6B10, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" void __cdecl sub_0043CE70(int);

namespace audio {

class SeqAction
{
public:
    virtual SeqAction* vfunc_00(int a1);
};

SeqAction* SeqAction::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionChannelSendVolumes::vfunc_00 (0x006F6B30, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionChannelSendVolumes::vfunc_00 (0x006F6B30, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7144[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionChannelSendVolumes
{
public:
    virtual SeqActionChannelSendVolumes* vfunc_00(int a1);
};

SeqActionChannelSendVolumes* SeqActionChannelSendVolumes::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7144, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] om::DynBehaviour::vfunc_00 (0x006F6B60, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::BaseObject::vfunc_00 (0x00026BB0), which was matched first;
// its addresses and names were swapped for this function's.
// om::DynBehaviour::vfunc_00 (0x006F6B60, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F9C[];
extern "C" void __cdecl sub_0043CE70(int);

namespace om {

class DynBehaviour
{
public:
    virtual DynBehaviour* vfunc_00(int a1);
};

DynBehaviour* DynBehaviour::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F9C;
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x006F6B80 audio::SeqEventChannelSendVolumes::vfunc_02 (67 B)
// ============================================================================
// [VERIFIED] audio::ChannelSendVolumeFadeBehaviour::vfunc_00 (0x006F6BD0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::ChannelSendVolumeFadeBehaviour::vfunc_00 (0x006F6BD0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F9C[];
extern "C" char DAT_007F714C[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class ChannelSendVolumeFadeBehaviour
{
public:
    virtual ChannelSendVolumeFadeBehaviour* vfunc_00(int a1);
};

ChannelSendVolumeFadeBehaviour* ChannelSendVolumeFadeBehaviour::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F9C;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F714C, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F6C00 audio::ChannelSendVolumeFadeBehaviour::vfunc_01 (403 B)
// [TODO] 0x006F6DA0 sub_006F6DA0 (58 B)
// ============================================================================
// [VERIFIED] sub_006F6DE0 (0x006F6DE0, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00772FA8[];
extern "C" char DAT_00772FDC[];
extern "C" char DAT_00772FF0[];
extern "C" Object* DAT_0085D4F4;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F6DE0(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_00772FF0, 0);
    second.sub_006EB7A0(DAT_00772FDC, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00772FA8;
        DAT_0085D4F4 = made;
    } else {
        DAT_0085D4F4 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSendVolumes::vfunc_03 (0x006F6EC0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F6EC0
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventChannelSendVolumes::vfunc_03 (0x006F6EC0, 6 bytes)
extern "C" int DAT_0085D4F4;

namespace audio {

class SeqEventChannelSendVolumes
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventChannelSendVolumes::vfunc_03()
{
    return DAT_0085D4F4;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSendVolumes::vfunc_04 (0x006F6ED0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventChannelSendVolumes::vfunc_04 (0x006F6ED0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F713C[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventChannelSendVolumes
{
public:
    virtual SeqEventChannelSendVolumes* vfunc_04(int a1);
};

SeqEventChannelSendVolumes* SeqEventChannelSendVolumes::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F713C, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F6F00 audio::SeqActionChannelSendVolumes::vfunc_06 (214 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventChannelSendVolumes>::vfunc_01 (0x006F6FE0, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventChannelSendVolumes>::vfunc_01 (0x002D93F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventChannelSendVolumes>::vfunc_01 (0x006F6FE0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006F6E60();
};

extern "C" char DAT_007F713C[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventChannelSendVolumes; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventChannelSendVolumes>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F713C);
    if (t1) {
        return ((Object*)t1)->sub_006F6E60();
    }
    return 0;
}

// [TODO] 0x006F7000 sub_006F7000 (68 B)
// [TODO] 0x006F7050 sub_006F7050 (68 B)
// [TODO] 0x006F70A0 audio::SeqEventChannelSendVolumes::vfunc_01 (88 B)
// [TODO] 0x006F7100 audio::SeqEventChannelSendVolumes::vfunc_00 (86 B)
// ============================================================================
// [VERIFIED] audio::SeqActionChannelSends::vfunc_00 (0x006F7160, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionChannelSends::vfunc_00 (0x006F7160, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7200[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionChannelSends
{
public:
    virtual SeqActionChannelSends* vfunc_00(int a1);
};

SeqActionChannelSends* SeqActionChannelSends::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7200, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSends::vfunc_03 (0x006F71F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F71F0
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventChannelSends::vfunc_03 (0x006F71F0, 6 bytes)
extern "C" int DAT_0085D4FC;

namespace audio {

class SeqEventChannelSends
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventChannelSends::vfunc_03()
{
    return DAT_0085D4FC;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSends::vfunc_04 (0x006F7200, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventChannelSends::vfunc_04 (0x006F7200, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F71F8[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventChannelSends
{
public:
    virtual SeqEventChannelSends* vfunc_04(int a1);
};

SeqEventChannelSends* SeqEventChannelSends::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F71F8, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelSends::vfunc_00 (0x006F7230, 72 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventChannelSends::vfunc_00 (0x002D9630), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventChannelSends::vfunc_00 (0x006F7230, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006ED500(int, int);
extern "C" bool __cdecl sub_006EC1E0(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventChannelSends
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x104];
    int m_Field108; // +0x108
};

int SeqEventChannelSends::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006ED500(a1, (int)(&m_Field108))) goto L_41;
        if (!sub_006EC1E0(a1, (int)this + 8)) goto L_41;
        return 1;
    }
L_41:
    return 0;
}

}

// [TODO] 0x006F7280 audio::SeqEventChannelSends::vfunc_02 (67 B)
// [TODO] 0x006F72D0 audio::SeqActionChannelSends::vfunc_06 (43 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventChannelSends>::vfunc_01 (0x006F7300, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventChannelSendVolumes>::vfunc_01 (0x002D93F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventChannelSends>::vfunc_01 (0x006F7300, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006F7190();
};

extern "C" char DAT_007F71F8[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventChannelSends; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventChannelSends>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F71F8);
    if (t1) {
        return ((Object*)t1)->sub_006F7190();
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_006F7320 (0x006F7320, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_0077305C[];
extern "C" char DAT_007730A8[];
extern "C" char DAT_007730B8[];
extern "C" Object* DAT_0085D4FC;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F7320(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_007730B8, 0);
    second.sub_006EB7A0(DAT_007730A8, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_0077305C;
        DAT_0085D4FC = made;
    } else {
        DAT_0085D4FC = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// [TODO] 0x006F73A0 audio::SeqEventChannelSends::vfunc_01 (71 B)
// ============================================================================
// [VERIFIED] audio::SeqCommand::vfunc_01 (0x006F73F0, 31 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::BaseObject::vfunc_00 (0x00026BB0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqCommand::vfunc_01 (0x006F73F0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007730E0[];
extern "C" void __cdecl sub_0043CE70(int);

namespace audio {

class SeqCommand
{
public:
    virtual SeqCommand* vfunc_01(int a1);
};

SeqCommand* SeqCommand::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_007730E0;
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventCondition::vfunc_01 (0x006F7410, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventCondition::vfunc_01 (0x002D9810), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventCondition::vfunc_01 (0x006F7410, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006ECBD0(int, int);
extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventCondition
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    bool sub_006F5AC0(int);
};

int SeqEventCondition::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        if (!sub_006F5AC0(a1)) goto L_39;
        if (!sub_006ECBD0(a1, (int)this + 16)) goto L_39;
        return 1;
    }
L_39:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventConditionElse::vfunc_01 (0x006F7450, 47 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventConditionElse::vfunc_01 (0x002D9850), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventConditionElse::vfunc_01 (0x006F7450, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventConditionElse
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    bool sub_006F5AC0(int);
};

int SeqEventConditionElse::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        if (!sub_006F5AC0(a1)) goto L_28;
        return 1;
    }
L_28:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventCondition::vfunc_00 (0x006F7480, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventCondition::vfunc_01 (0x002D9810), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventCondition::vfunc_00 (0x006F7480, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006ECC20(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventCondition
{
public:
    virtual void vfunc_00();
    virtual int vfunc_00(int a1);
    bool sub_006F5A60(int);
};

int SeqEventCondition::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006F5A60(a1)) goto L_39;
        if (!sub_006ECC20(a1, (int)this + 16)) goto L_39;
        return 1;
    }
L_39:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventConditionElse::vfunc_00 (0x006F74C0, 47 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventConditionElse::vfunc_01 (0x002D9850), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventConditionElse::vfunc_00 (0x006F74C0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventConditionElse
{
public:
    virtual void vfunc_00();
    virtual int vfunc_00(int a1);
    bool sub_006F5A60(int);
};

int SeqEventConditionElse::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006F5A60(a1)) goto L_28;
        return 1;
    }
L_28:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventCondition::vfunc_03 (0x006F74F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F74F0
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventCondition::vfunc_03 (0x006F74F0, 6 bytes)
extern "C" int DAT_0085D500;

namespace audio {

class SeqEventCondition
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventCondition::vfunc_03()
{
    return DAT_0085D500;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventCondition::vfunc_04 (0x006F7500, 72 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventCondition::vfunc_04 (0x002D9900), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventCondition::vfunc_04 (0x006F7500, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_006EBBD0();
};

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int);
};

extern "C" char DAT_007730EC[];
extern "C" char DAT_007F732C[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventCondition
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventCondition* vfunc_04(int a1);
    void sub_006F5C50();
    char m_pad04[0xC];
    Field10 m_Field10; // +0x10
    char m_pad11[0xB];
    int m_Field1C; // +0x1C
};

SeqEventCondition* SeqEventCondition::vfunc_04(int a1)
{
    int t1;

    t1 = m_Field1C;
    *(int*)this = (int)DAT_007730EC;
    if (m_Field1C) {
        ((Object*)t1)->vfunc_04(1);
        m_Field1C = 0;
    }
    m_Field10.sub_006EBBD0();
    sub_006F5C50();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F732C, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqCommandCondition::vfunc_01 (0x006F7550, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqCommandCondition::vfunc_01 (0x006F7550, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007730E0[];
extern "C" char DAT_007F733C[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqCommandCondition
{
public:
    virtual SeqCommandCondition* vfunc_01(int a1);
};

SeqCommandCondition* SeqCommandCondition::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_007730E0;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F733C, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] sub_006F7580 (0x006F7580, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773108[];
extern "C" char DAT_00773128[];
extern "C" char DAT_00773134[];
extern "C" Object* DAT_0085D500;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F7580(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_00773134, 0);
    second.sub_006EB7A0(DAT_00773128, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773108;
        DAT_0085D500 = made;
    } else {
        DAT_0085D500 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] sub_006F7600 (0x006F7600, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773114[];
extern "C" char DAT_00773148[];
extern "C" char DAT_00773150[];
extern "C" Object* DAT_0085D504;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F7600(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_00773150, 0);
    second.sub_006EB7A0(DAT_00773148, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773114;
        DAT_0085D504 = made;
    } else {
        DAT_0085D504 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqEventConditionElse::vfunc_03 (0x006F7680, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F7680
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventConditionElse::vfunc_03 (0x006F7680, 6 bytes)
extern "C" int DAT_0085D504;

namespace audio {

class SeqEventConditionElse
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventConditionElse::vfunc_03()
{
    return DAT_0085D504;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventConditionElse::vfunc_04 (0x006F7690, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventConditionElse::vfunc_04 (0x006F7690, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7334[];
extern "C" void __cdecl sub_006F5C50(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventConditionElse
{
public:
    virtual SeqEventConditionElse* vfunc_04(int a1);
};

SeqEventConditionElse* SeqEventConditionElse::vfunc_04(int a1)
{
    sub_006F5C50();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7334, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F76C0 audio::SeqEventCondition::vfunc_02 (72 B)
// [TODO] 0x006F7710 audio::SeqCommandCondition::vfunc_00 (213 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventConditionElse>::vfunc_01 (0x006F77F0, 58 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventConditionElse>::vfunc_01 (0x002D9BF0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventConditionElse>::vfunc_01 (0x006F77F0, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F5850();
};

extern "C" char DAT_0077316C[];
extern "C" char DAT_007F7334[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventConditionElse; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventConditionElse>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F7334);
    if (t1) {
        ((Object*)t1)->sub_006F5850();
        *(int*)(t1 + 8) = 0;
        *(int*)(t1 + 12) = 0;
        *(int*)(t1 + 16) = 0;
        *(int*)(t1 + 20) = 0;
        *(int*)t1 = (int)DAT_0077316C;
        return t1;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventCondition>::vfunc_01 (0x006F78C0, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventChannelSendVolumes>::vfunc_01 (0x002D93F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventCondition>::vfunc_01 (0x006F78C0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006F7830();
};

extern "C" char DAT_007F732C[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventCondition; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventCondition>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F732C);
    if (t1) {
        return ((Object*)t1)->sub_006F7830();
    }
    return 0;
}

// [TODO] 0x006F78E0 audio::SeqActionWait::vfunc_02 (21 B)
// [TODO] 0x006F7900 audio::SeqActionWait::vfunc_01 (15 B)
// [TODO] 0x006F7910 audio::SeqActionWait::vfunc_03 (15 B)
// [TODO] 0x006F7920 audio::SeqActionWait::vfunc_04 (15 B)
// ============================================================================
// [VERIFIED] audio::SeqEventWait::vfunc_03 (0x006F7930, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F7930
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventWait::vfunc_03 (0x006F7930, 6 bytes)
extern "C" int DAT_0085D508;

namespace audio {

class SeqEventWait
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventWait::vfunc_03()
{
    return DAT_0085D508;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventWait::vfunc_04 (0x006F7940, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_04 (0x002D8D90), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventWait::vfunc_04 (0x006F7940, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_006EBBD0();
};

extern "C" char DAT_007F73CC[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventWait
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventWait* vfunc_04(int a1);
    void sub_006F5730();
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

SeqEventWait* SeqEventWait::vfunc_04(int a1)
{
    m_Field08.sub_006EBBD0();
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F73CC, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionWait::vfunc_00 (0x006F7970, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionWait::vfunc_00 (0x006F7970, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F73D4[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionWait
{
public:
    virtual SeqActionWait* vfunc_00(int a1);
};

SeqActionWait* SeqActionWait::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F73D4, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F79A0 audio::SeqActionWait::vfunc_05 (232 B)
// [TODO] 0x006F7A90 audio::SeqEventType<audio::SeqEventWait>::vfunc_01 (88 B)
// ============================================================================
// [VERIFIED] sub_006F7AF0 (0x006F7AF0, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773198[];
extern "C" char DAT_007731EC[];
extern "C" char DAT_007731F4[];
extern "C" Object* DAT_0085D508;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F7AF0(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_007731F4, 0);
    second.sub_006EB7A0(DAT_007731EC, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773198;
        DAT_0085D508 = made;
    } else {
        DAT_0085D508 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// [TODO] 0x006F7B70 audio::SeqEventWait::vfunc_02 (67 B)
// ============================================================================
// [VERIFIED] audio::SeqEventWaitBeat::vfunc_00 (0x006F7BC0, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventWaitBeat::vfunc_00 (0x002D9FE0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventWaitBeat::vfunc_00 (0x006F7BC0, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_00700D90(int);
};

extern "C" bool __cdecl sub_006ED500(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventWaitBeat
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
    char m_pad09[0x7];
    int m_Field10; // +0x10
};

int SeqEventWaitBeat::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006ED500(a1, (int)(&m_Field10))) goto L_3A;
        if (!m_Field08.sub_00700D90(a1)) goto L_3A;
        return 1;
    }
L_3A:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionWaitBeat::vfunc_00 (0x006F7C10, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionWaitBeat::vfunc_00 (0x006F7C10, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7478[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionWaitBeat
{
public:
    virtual SeqActionWaitBeat* vfunc_00(int a1);
};

SeqActionWaitBeat* SeqActionWaitBeat::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7478, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F7C40 audio::SeqActionWaitBeat::vfunc_05 (93 B)
// ============================================================================
// [VERIFIED] sub_006F7CA0 (0x006F7CA0, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773228[];
extern "C" char DAT_0077324C[];
extern "C" char DAT_00773258[];
extern "C" Object* DAT_0085D510;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F7CA0(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_00773258, 0);
    second.sub_006EB7A0(DAT_0077324C, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773228;
        DAT_0085D510 = made;
    } else {
        DAT_0085D510 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqEventWaitBeat::vfunc_03 (0x006F7D80, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F7D80
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventWaitBeat::vfunc_03 (0x006F7D80, 6 bytes)
extern "C" int DAT_0085D510;

namespace audio {

class SeqEventWaitBeat
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventWaitBeat::vfunc_03()
{
    return DAT_0085D510;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventWaitBeat::vfunc_04 (0x006F7D90, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_04 (0x002D8D90), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventWaitBeat::vfunc_04 (0x006F7D90, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_00700EE0();
};

extern "C" char DAT_007F7470[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventWaitBeat
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventWaitBeat* vfunc_04(int a1);
    void sub_006F5730();
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

SeqEventWaitBeat* SeqEventWaitBeat::vfunc_04(int a1)
{
    m_Field08.sub_00700EE0();
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7470, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F7DC0 audio::SeqEventWaitBeat::vfunc_01 (67 B)
// [TODO] 0x006F7E10 audio::SeqEventWaitBeat::vfunc_02 (73 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventWaitBeat>::vfunc_01 (0x006F7E60, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventChannelSendVolumes>::vfunc_01 (0x002D93F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventWaitBeat>::vfunc_01 (0x006F7E60, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006F7D20();
};

extern "C" char DAT_007F7470[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventWaitBeat; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventWaitBeat>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F7470);
    if (t1) {
        return ((Object*)t1)->sub_006F7D20();
    }
    return 0;
}

// ============================================================================
// [VERIFIED] audio::SeqActionWaitBeat::vfunc_02 (0x006F7E80, 60 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionWaitBeat::vfunc_02 (0x002DA2A0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionWaitBeat::vfunc_02 (0x006F7E80, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006F0D00(int);
};

namespace audio {

class SeqActionWaitBeat
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1, int a2);
    void sub_006F57A0(int, int);
    int m_Field04; // +0x04
    char m_pad08[0xC];
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

void SeqActionWaitBeat::vfunc_02(int a1, int a2)
{
    int t2;

    t2 = ((Object*)*(int*)(*(int*)(*(int*)(a1 + 20) + 36) + 52) + 44)->sub_006F0D00(m_Field04 + 16);
    m_Field18 = t2;
    if (t2) {
        m_Field14 = *(int*)(t2 + 56);
    }
    sub_006F57A0(2, a1);
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventNestTrack::vfunc_01 (0x006F7EC0, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_01 (0x002D8D00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventNestTrack::vfunc_01 (0x006F7EC0, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006ECBD0(int, int);
extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventNestTrack
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
};

int SeqEventNestTrack::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        if (!sub_006ECBD0(a1, (int)this + 8)) goto L_2D;
        return 1;
    }
L_2D:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionExpression::vfunc_00 (0x006F7F00, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionExpression::vfunc_00 (0x006F7F00, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F751C[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionExpression
{
public:
    virtual SeqActionExpression* vfunc_00(int a1);
};

SeqActionExpression* SeqActionExpression::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F751C, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventExpression::vfunc_03 (0x006F7F30, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F7F30
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventExpression::vfunc_03 (0x006F7F30, 6 bytes)
extern "C" int DAT_0085D518;

namespace audio {

class SeqEventExpression
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventExpression::vfunc_03()
{
    return DAT_0085D518;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventExpression::vfunc_04 (0x006F7F40, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_04 (0x002D8D90), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventExpression::vfunc_04 (0x006F7F40, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_006EBBD0();
};

extern "C" char DAT_007F7514[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventExpression
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventExpression* vfunc_04(int a1);
    void sub_006F5730();
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

SeqEventExpression* SeqEventExpression::vfunc_04(int a1)
{
    m_Field08.sub_006EBBD0();
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7514, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F7F70 audio::SeqEventExpression::vfunc_02 (67 B)
// [TODO] 0x006F7FC0 audio::SeqActionExpression::vfunc_06 (68 B)
// [TODO] 0x006F8010 audio::SeqEventType<audio::SeqEventExpression>::vfunc_01 (88 B)
// ============================================================================
// [VERIFIED] sub_006F8070 (0x006F8070, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773298[];
extern "C" char DAT_007732EC[];
extern "C" char DAT_007732FC[];
extern "C" Object* DAT_0085D518;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F8070(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_007732FC, 0);
    second.sub_006EB7A0(DAT_007732EC, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773298;
        DAT_0085D518 = made;
    } else {
        DAT_0085D518 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// [TODO] 0x006F8140 audio::SeqEventStopTrack::vfunc_01 (103 B)
// [TODO] 0x006F81B0 audio::SeqEventStopTrack::vfunc_00 (103 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventStopTrack>::vfunc_01 (0x006F8220, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventChannelSendVolumes>::vfunc_01 (0x002D93F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventStopTrack>::vfunc_01 (0x006F8220, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006F80F0();
};

extern "C" char DAT_007F75B8[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventStopTrack; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventStopTrack>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F75B8);
    if (t1) {
        return ((Object*)t1)->sub_006F80F0();
    }
    return 0;
}

// ============================================================================
// [VERIFIED] audio::SeqEventStopTrack::vfunc_03 (0x006F8240, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F8240
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventStopTrack::vfunc_03 (0x006F8240, 6 bytes)
extern "C" int DAT_0085D51C;

namespace audio {

class SeqEventStopTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventStopTrack::vfunc_03()
{
    return DAT_0085D51C;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionStopTrack::vfunc_00 (0x006F8250, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionStopTrack::vfunc_00 (0x006F8250, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F75C0[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionStopTrack
{
public:
    virtual SeqActionStopTrack* vfunc_00(int a1);
};

SeqActionStopTrack* SeqActionStopTrack::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F75C0, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventStopTrack::vfunc_04 (0x006F8280, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventStopTrack::vfunc_04 (0x002DA660), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventStopTrack::vfunc_04 (0x006F8280, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_006EBBD0();
};

extern "C" char DAT_007F75B8[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventStopTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventStopTrack* vfunc_04(int a1);
    void sub_006F5730();
    char m_pad04[0xC];
    Field10 m_Field10; // +0x10
};

SeqEventStopTrack* SeqEventStopTrack::vfunc_04(int a1)
{
    m_Field10.sub_006EBBD0();
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F75B8, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F82B0 audio::SeqEventStopTrack::vfunc_02 (67 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventNestTrack>::vfunc_00 (0x006F8300, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as FightTree::FightActionController<fight::EnterExitScriptTrack>::vfunc_03 (0x000227A0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventNestTrack>::vfunc_00 (0x006F8300, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006F59B0(void);
extern "C" void __cdecl sub_0043CE70(int);

namespace audio { class SeqEventNestTrack; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual SeqEventType<audio::SeqEventNestTrack>* vfunc_00(int a1);
};
}

template <> audio::SeqEventType<audio::SeqEventNestTrack>* audio::SeqEventType<audio::SeqEventNestTrack>::vfunc_00(int a1)
{
    sub_006F59B0();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] sub_006F8320 (0x006F8320, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_0077333C[];
extern "C" char DAT_00773364[];
extern "C" char DAT_00773370[];
extern "C" Object* DAT_0085D51C;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F8320(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_00773370, 0);
    second.sub_006EB7A0(DAT_00773364, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_0077333C;
        DAT_0085D51C = made;
    } else {
        DAT_0085D51C = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// [TODO] 0x006F83A0 audio::SeqActionStopTrack::vfunc_06 (335 B)
// [TODO] 0x006F84F0 audio::SeqEventPlayTrack::vfunc_01 (103 B)
// [TODO] 0x006F8560 audio::SeqEventPlayTrack::vfunc_00 (103 B)
// ============================================================================
// [VERIFIED] audio::SeqActionPlayTrack::vfunc_00 (0x006F85D0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionPlayTrack::vfunc_00 (0x006F85D0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7664[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionPlayTrack
{
public:
    virtual SeqActionPlayTrack* vfunc_00(int a1);
};

SeqActionPlayTrack* SeqActionPlayTrack::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7664, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventPlayTrack::vfunc_03 (0x006F8650, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F8650
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventPlayTrack::vfunc_03 (0x006F8650, 6 bytes)
extern "C" int DAT_0085D520;

namespace audio {

class SeqEventPlayTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventPlayTrack::vfunc_03()
{
    return DAT_0085D520;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventPlayTrack::vfunc_04 (0x006F8660, 45 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventPlayTrack::vfunc_04 (0x002DAA30), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventPlayTrack::vfunc_04 (0x006F8660, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_006EBBD0();
};

extern "C" char DAT_007F765C[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventPlayTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventPlayTrack* vfunc_04(int a1);
    void sub_006F5730();
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
};

SeqEventPlayTrack* SeqEventPlayTrack::vfunc_04(int a1)
{
    m_Field14.sub_006EBBD0();
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F765C, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F8690 audio::SeqEventPlayTrack::vfunc_02 (67 B)
// [TODO] 0x006F86E0 audio::SeqActionPlayTrack::vfunc_06 (187 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventPlayTrack>::vfunc_01 (0x006F87A0, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventChannelSendVolumes>::vfunc_01 (0x002D93F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventPlayTrack>::vfunc_01 (0x006F87A0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006F8600();
};

extern "C" char DAT_007F765C[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventPlayTrack; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventPlayTrack>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F765C);
    if (t1) {
        return ((Object*)t1)->sub_006F8600();
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_006F87C0 (0x006F87C0, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773398[];
extern "C" char DAT_007733DC[];
extern "C" char DAT_007733E4[];
extern "C" Object* DAT_0085D520;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F87C0(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_007733E4, 0);
    second.sub_006EB7A0(DAT_007733DC, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773398;
        DAT_0085D520 = made;
    } else {
        DAT_0085D520 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqActionChannelVolumes::vfunc_00 (0x006F8840, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionChannelVolumes::vfunc_00 (0x006F8840, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7748[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionChannelVolumes
{
public:
    virtual SeqActionChannelVolumes* vfunc_00(int a1);
};

SeqActionChannelVolumes* SeqActionChannelVolumes::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7748, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F8870 sub_006F8870 (83 B)
// ============================================================================
// [VERIFIED] audio::SeqEventChannelVolumes::vfunc_03 (0x006F8930, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F8930
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventChannelVolumes::vfunc_03 (0x006F8930, 6 bytes)
extern "C" int DAT_0085D524;

namespace audio {

class SeqEventChannelVolumes
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventChannelVolumes::vfunc_03()
{
    return DAT_0085D524;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventChannelVolumes::vfunc_04 (0x006F8940, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventChannelVolumes::vfunc_04 (0x006F8940, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7740[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventChannelVolumes
{
public:
    virtual SeqEventChannelVolumes* vfunc_04(int a1);
};

SeqEventChannelVolumes* SeqEventChannelVolumes::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7740, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F8970 audio::SeqEventChannelVolumes::vfunc_02 (67 B)
// ============================================================================
// [VERIFIED] audio::ChannelVolumeFadeBehaviour::vfunc_00 (0x006F89C0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::ChannelVolumeFadeBehaviour::vfunc_00 (0x006F89C0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F9C[];
extern "C" char DAT_007F7750[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class ChannelVolumeFadeBehaviour
{
public:
    virtual ChannelVolumeFadeBehaviour* vfunc_00(int a1);
};

ChannelVolumeFadeBehaviour* ChannelVolumeFadeBehaviour::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F9C;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7750, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F89F0 audio::ChannelVolumeFadeBehaviour::vfunc_01 (771 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventChannelVolumes>::vfunc_01 (0x006F8D00, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventChannelSendVolumes>::vfunc_01 (0x002D93F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventChannelVolumes>::vfunc_01 (0x006F8D00, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006F88D0();
};

extern "C" char DAT_007F7740[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventChannelVolumes; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventChannelVolumes>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F7740);
    if (t1) {
        return ((Object*)t1)->sub_006F88D0();
    }
    return 0;
}

// [TODO] 0x006F8D20 sub_006F8D20 (53 B)
// [TODO] 0x006F8D60 sub_006F8D60 (53 B)
// ============================================================================
// [VERIFIED] sub_006F8DA0 (0x006F8DA0, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773408[];
extern "C" char DAT_00773458[];
extern "C" char DAT_00773468[];
extern "C" Object* DAT_0085D524;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F8DA0(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_00773468, 0);
    second.sub_006EB7A0(DAT_00773458, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773408;
        DAT_0085D524 = made;
    } else {
        DAT_0085D524 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// [TODO] 0x006F8E20 audio::SeqEventChannelVolumes::vfunc_01 (88 B)
// [TODO] 0x006F8E80 audio::SeqEventChannelVolumes::vfunc_00 (86 B)
// [TODO] 0x006F8EE0 audio::SeqActionChannelVolumes::vfunc_06 (180 B)
// ============================================================================
// [VERIFIED] audio::SeqEventVarVolumeRand::vfunc_01 (0x006F8FA0, 49 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarVolumeRand::vfunc_01 (0x002DB360), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarVolumeRand::vfunc_01 (0x006F8FA0, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006F33F0(int, int);
extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventVarVolumeRand
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

void SeqEventVarVolumeRand::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        sub_006F33F0(a1, m_Field08);
    }
    sub_006F33F0(a1, m_Field0C);
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolumeRand::vfunc_00 (0x006F8FE0, 69 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarVolumeRand::vfunc_00 (0x002DB3A0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarVolumeRand::vfunc_00 (0x006F8FE0, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F33D0(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventVarVolumeRand
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

int SeqEventVarVolumeRand::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006F33D0(a1, (int)(&m_Field08))) goto L_3E;
        if (!sub_006F33D0(a1, (int)this + 12)) goto L_3E;
        return 1;
    }
L_3E:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionVarVolumeRand::vfunc_00 (0x006F9030, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionVarVolumeRand::vfunc_00 (0x006F9030, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7800[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionVarVolumeRand
{
public:
    virtual SeqActionVarVolumeRand* vfunc_00(int a1);
};

SeqActionVarVolumeRand* SeqActionVarVolumeRand::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7800, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolumeRand::vfunc_03 (0x006F9060, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F9060
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventVarVolumeRand::vfunc_03 (0x006F9060, 6 bytes)
extern "C" int DAT_0085D52C;

namespace audio {

class SeqEventVarVolumeRand
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventVarVolumeRand::vfunc_03()
{
    return DAT_0085D52C;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolumeRand::vfunc_04 (0x006F9070, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarVolumeRand::vfunc_04 (0x006F9070, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F77F8[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventVarVolumeRand
{
public:
    virtual SeqEventVarVolumeRand* vfunc_04(int a1);
};

SeqEventVarVolumeRand* SeqEventVarVolumeRand::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F77F8, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F90A0 audio::SeqEventVarVolumeRand::vfunc_02 (67 B)
// [TODO] 0x006F90F0 audio::SeqActionVarVolumeRand::vfunc_06 (51 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventVarVolumeRand>::vfunc_01 (0x006F9130, 55 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventVarVolumeRand>::vfunc_01 (0x002DB4F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventVarVolumeRand>::vfunc_01 (0x006F9130, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F5850();
};

extern "C" char DAT_007734BC[];
extern "C" char DAT_007F77F8[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventVarVolumeRand; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventVarVolumeRand>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F77F8);
    if (t1) {
        ((Object*)t1)->sub_006F5850();
        *(int*)t1 = (int)DAT_007734BC;
        *(int*)(t1 + 8) = 0x3F000000;
        *(int*)(t1 + 12) = 0x3F800000;
        return t1;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_006F9170 (0x006F9170, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773490[];
extern "C" char DAT_007734D4[];
extern "C" char DAT_007734DC[];
extern "C" Object* DAT_0085D52C;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F9170(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_007734DC, 0);
    second.sub_006EB7A0(DAT_007734D4, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773490;
        DAT_0085D52C = made;
    } else {
        DAT_0085D52C = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolume::vfunc_01 (0x006F91F0, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarVolume::vfunc_01 (0x002DB5B0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarVolume::vfunc_01 (0x006F91F0, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F33F0(int, int);
extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventVarVolume
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

int SeqEventVarVolume::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        if (!sub_006F33F0(a1, m_Field08)) goto L_2D;
        return 1;
    }
L_2D:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolume::vfunc_00 (0x006F9230, 32 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarVolume::vfunc_00 (0x002DB5F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarVolume::vfunc_00 (0x006F9230, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006F33D0(int, int);
extern "C" void __stdcall sub_006F5740(int);

namespace audio {

class SeqEventVarVolume
{
public:
    virtual void vfunc_00(int a1);
};

void SeqEventVarVolume::vfunc_00(int a1)
{
    sub_006F5740(a1);
    sub_006F33D0(a1, (int)this + 8);
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionVarVolume::vfunc_00 (0x006F9250, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionVarVolume::vfunc_00 (0x006F9250, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F78A4[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionVarVolume
{
public:
    virtual SeqActionVarVolume* vfunc_00(int a1);
};

SeqActionVarVolume* SeqActionVarVolume::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F78A4, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolume::vfunc_03 (0x006F9280, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F9280
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventVarVolume::vfunc_03 (0x006F9280, 6 bytes)
extern "C" int DAT_0085D530;

namespace audio {

class SeqEventVarVolume
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventVarVolume::vfunc_03()
{
    return DAT_0085D530;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarVolume::vfunc_04 (0x006F9290, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarVolume::vfunc_04 (0x006F9290, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F789C[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventVarVolume
{
public:
    virtual SeqEventVarVolume* vfunc_04(int a1);
};

SeqEventVarVolume* SeqEventVarVolume::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F789C, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F92C0 audio::SeqEventVarVolume::vfunc_02 (67 B)
// ============================================================================
// [VERIFIED] audio::SeqActionVarVolume::vfunc_06 (0x006F9310, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionVarVolume::vfunc_06 (0x002DB6D0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionVarVolume::vfunc_06 (0x006F9310, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class SeqActionVarVolume
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int a1);
    int m_Field04; // +0x04
};

void SeqActionVarVolume::vfunc_06(int a1)
{
    int t1;

    t1 = m_Field04 + 8;
    *(int*)(*(int*)(a1 + 4) + 32) = m_Field04 + 8;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventVarVolume>::vfunc_01 (0x006F9330, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventVarVolume>::vfunc_01 (0x002DB6F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventVarVolume>::vfunc_01 (0x006F9330, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F5850();
};

extern "C" char DAT_00773530[];
extern "C" char DAT_007F789C[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventVarVolume; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventVarVolume>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F789C);
    if (t1) {
        ((Object*)t1)->sub_006F5850();
        *(int*)t1 = (int)DAT_00773530;
        *(int*)(t1 + 8) = 0x3F800000;
        return t1;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_006F9360 (0x006F9360, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773504[];
extern "C" char DAT_00773548[];
extern "C" char DAT_00773550[];
extern "C" Object* DAT_0085D530;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F9360(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_00773550, 0);
    second.sub_006EB7A0(DAT_00773548, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773504;
        DAT_0085D530 = made;
    } else {
        DAT_0085D530 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqEventVarTempo::vfunc_01 (0x006F93E0, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarTempo::vfunc_01 (0x002DB7A0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarTempo::vfunc_01 (0x006F93E0, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_00700CE0(int);
};

extern "C" bool __cdecl sub_006F33F0(int, int);
extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventVarTempo
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
    char m_pad09[0x7];
    int m_Field10; // +0x10
};

int SeqEventVarTempo::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        if (!m_Field08.sub_00700CE0(a1)) goto L_3A;
        if (!sub_006F33F0(a1, m_Field10)) goto L_3A;
        return 1;
    }
L_3A:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarTempo::vfunc_00 (0x006F9430, 65 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarTempo::vfunc_00 (0x002DB7F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarTempo::vfunc_00 (0x006F9430, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_00700CA0(int);
};

extern "C" bool __cdecl sub_006F33D0(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventVarTempo
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

int SeqEventVarTempo::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!m_Field08.sub_00700CA0(a1)) goto L_3A;
        if (!sub_006F33D0(a1, (int)this + 16)) goto L_3A;
        return 1;
    }
L_3A:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionVarTempo::vfunc_00 (0x006F9480, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionVarTempo::vfunc_00 (0x006F9480, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7948[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionVarTempo
{
public:
    virtual SeqActionVarTempo* vfunc_00(int a1);
};

SeqActionVarTempo* SeqActionVarTempo::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7948, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarTempo::vfunc_03 (0x006F94B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F94B0
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventVarTempo::vfunc_03 (0x006F94B0, 6 bytes)
extern "C" int DAT_0085D534;

namespace audio {

class SeqEventVarTempo
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventVarTempo::vfunc_03()
{
    return DAT_0085D534;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarTempo::vfunc_04 (0x006F94C0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarTempo::vfunc_04 (0x006F94C0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7940[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventVarTempo
{
public:
    virtual SeqEventVarTempo* vfunc_04(int a1);
};

SeqEventVarTempo* SeqEventVarTempo::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7940, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F94F0 audio::SeqEventVarTempo::vfunc_02 (67 B)
// [TODO] 0x006F9540 audio::SeqActionVarTempo::vfunc_06 (41 B)
// [TODO] 0x006F9570 audio::SeqEventType<audio::SeqEventVarTempo>::vfunc_01 (59 B)
// ============================================================================
// [VERIFIED] sub_006F95B0 (0x006F95B0, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773574[];
extern "C" char DAT_007735B8[];
extern "C" char DAT_007735C0[];
extern "C" Object* DAT_0085D534;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F95B0(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_007735C0, 0);
    second.sub_006EB7A0(DAT_007735B8, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773574;
        DAT_0085D534 = made;
    } else {
        DAT_0085D534 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPosDist::vfunc_01 (0x006F9630, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarPosDist::vfunc_01 (0x002DB9F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarPosDist::vfunc_01 (0x006F9630, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_00700CE0(int);
};

extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventVarPosDist
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

int SeqEventVarPosDist::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        if (!m_Field08.sub_00700CE0(a1)) goto L_29;
        return 1;
    }
L_29:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPosDist::vfunc_00 (0x006F9660, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarPosDist::vfunc_01 (0x002DB9F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarPosDist::vfunc_00 (0x006F9660, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_00700CA0(int);
};

extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventVarPosDist
{
public:
    virtual void vfunc_00();
    virtual int vfunc_00(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

int SeqEventVarPosDist::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!m_Field08.sub_00700CA0(a1)) goto L_29;
        return 1;
    }
L_29:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionVarPosDist::vfunc_00 (0x006F9690, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionVarPosDist::vfunc_00 (0x006F9690, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F79EC[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionVarPosDist
{
public:
    virtual SeqActionVarPosDist* vfunc_00(int a1);
};

SeqActionVarPosDist* SeqActionVarPosDist::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F79EC, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPosDist::vfunc_03 (0x006F96C0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F96C0
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventVarPosDist::vfunc_03 (0x006F96C0, 6 bytes)
extern "C" int DAT_0085D538;

namespace audio {

class SeqEventVarPosDist
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventVarPosDist::vfunc_03()
{
    return DAT_0085D538;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPosDist::vfunc_04 (0x006F96D0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarPosDist::vfunc_04 (0x006F96D0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F79E4[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventVarPosDist
{
public:
    virtual SeqEventVarPosDist* vfunc_04(int a1);
};

SeqEventVarPosDist* SeqEventVarPosDist::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F79E4, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F9700 audio::SeqEventVarPosDist::vfunc_02 (67 B)
// [TODO] 0x006F9750 audio::SeqActionVarPosDist::vfunc_06 (29 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventVarPosDist>::vfunc_01 (0x006F9770, 55 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventVarPosDist>::vfunc_01 (0x002DBB30), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventVarPosDist>::vfunc_01 (0x006F9770, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F5850();
};

extern "C" char DAT_00773610[];
extern "C" char DAT_007F79E4[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventVarPosDist; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventVarPosDist>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F79E4);
    if (t1) {
        ((Object*)t1)->sub_006F5850();
        *(int*)t1 = (int)DAT_00773610;
        *(int*)(t1 + 8) = 0x3F800000;
        *(int*)(t1 + 12) = 0x42C80000;
        return t1;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_006F97B0 (0x006F97B0, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_007735E4[];
extern "C" char DAT_00773628[];
extern "C" char DAT_00773630[];
extern "C" Object* DAT_0085D538;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F97B0(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_00773630, 0);
    second.sub_006EB7A0(DAT_00773628, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_007735E4;
        DAT_0085D538 = made;
    } else {
        DAT_0085D538 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPitchRand::vfunc_01 (0x006F9830, 69 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarPitchRand::vfunc_01 (0x002DBBF0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarPitchRand::vfunc_01 (0x006F9830, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F33F0(int, int);
extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventVarPitchRand
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

int SeqEventVarPitchRand::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        if (!sub_006F33F0(a1, m_Field08)) goto L_3E;
        if (!sub_006F33F0(a1, m_Field0C)) goto L_3E;
        return 1;
    }
L_3E:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionVarPitchRand::vfunc_00 (0x006F9880, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionVarPitchRand::vfunc_00 (0x006F9880, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7AA0[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionVarPitchRand
{
public:
    virtual SeqActionVarPitchRand* vfunc_00(int a1);
};

SeqActionVarPitchRand* SeqActionVarPitchRand::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7AA0, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPitchRand::vfunc_03 (0x006F98B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F98B0
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventVarPitchRand::vfunc_03 (0x006F98B0, 6 bytes)
extern "C" int DAT_0085D53C;

namespace audio {

class SeqEventVarPitchRand
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventVarPitchRand::vfunc_03()
{
    return DAT_0085D53C;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPitchRand::vfunc_04 (0x006F98C0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarPitchRand::vfunc_04 (0x006F98C0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7A98[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventVarPitchRand
{
public:
    virtual SeqEventVarPitchRand* vfunc_04(int a1);
};

SeqEventVarPitchRand* SeqEventVarPitchRand::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7A98, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F98F0 audio::SeqEventVarPitchRand::vfunc_02 (67 B)
// [TODO] 0x006F9940 audio::SeqActionVarPitchRand::vfunc_06 (51 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventVarPitchRand>::vfunc_01 (0x006F9980, 55 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventVarPitchRand>::vfunc_01 (0x002DBD40), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventVarPitchRand>::vfunc_01 (0x006F9980, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F5850();
};

extern "C" char DAT_00773680[];
extern "C" char DAT_007F7A98[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventVarPitchRand; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventVarPitchRand>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F7A98);
    if (t1) {
        ((Object*)t1)->sub_006F5850();
        *(int*)t1 = (int)DAT_00773680;
        *(int*)(t1 + 8) = 0x3F4CCCCD;
        *(int*)(t1 + 12) = 0x3F99999A;
        return t1;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_006F99C0 (0x006F99C0, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773654[];
extern "C" char DAT_00773698[];
extern "C" char DAT_007736A4[];
extern "C" Object* DAT_0085D53C;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F99C0(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_007736A4, 0);
    second.sub_006EB7A0(DAT_00773698, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773654;
        DAT_0085D53C = made;
    } else {
        DAT_0085D53C = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPitch::vfunc_00 (0x006F9A40, 52 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_01 (0x002D8D00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarPitch::vfunc_00 (0x006F9A40, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F33D0(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventVarPitch
{
public:
    virtual void vfunc_00();
    virtual int vfunc_00(int a1);
};

int SeqEventVarPitch::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006F33D0(a1, (int)this + 8)) goto L_2D;
        return 1;
    }
L_2D:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionVarPitch::vfunc_00 (0x006F9A80, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionVarPitch::vfunc_00 (0x006F9A80, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7B44[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionVarPitch
{
public:
    virtual SeqActionVarPitch* vfunc_00(int a1);
};

SeqActionVarPitch* SeqActionVarPitch::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7B44, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPitch::vfunc_03 (0x006F9AB0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F9AB0
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventVarPitch::vfunc_03 (0x006F9AB0, 6 bytes)
extern "C" int DAT_0085D540;

namespace audio {

class SeqEventVarPitch
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventVarPitch::vfunc_03()
{
    return DAT_0085D540;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventVarPitch::vfunc_04 (0x006F9AC0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventVarPitch::vfunc_04 (0x006F9AC0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7B3C[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventVarPitch
{
public:
    virtual SeqEventVarPitch* vfunc_04(int a1);
};

SeqEventVarPitch* SeqEventVarPitch::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7B3C, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F9AF0 audio::SeqEventVarPitch::vfunc_02 (67 B)
// ============================================================================
// [VERIFIED] audio::SeqActionVarPitch::vfunc_06 (0x006F9B40, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionVarPitch::vfunc_06 (0x002DBF00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionVarPitch::vfunc_06 (0x006F9B40, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class SeqActionVarPitch
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int a1);
    int m_Field04; // +0x04
};

void SeqActionVarPitch::vfunc_06(int a1)
{
    int t1;

    t1 = m_Field04 + 8;
    *(int*)(*(int*)(a1 + 4) + 36) = m_Field04 + 8;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventVarPitch>::vfunc_01 (0x006F9B60, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventVarVolume>::vfunc_01 (0x002DB6F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventVarPitch>::vfunc_01 (0x006F9B60, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F5850();
};

extern "C" char DAT_007736F8[];
extern "C" char DAT_007F7B3C[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventVarPitch; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventVarPitch>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F7B3C);
    if (t1) {
        ((Object*)t1)->sub_006F5850();
        *(int*)t1 = (int)DAT_007736F8;
        *(int*)(t1 + 8) = 0x3F800000;
        return t1;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_006F9B90 (0x006F9B90, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_007736CC[];
extern "C" char DAT_0073C6BC[];
extern "C" char DAT_00773710[];
extern "C" Object* DAT_0085D540;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F9B90(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_00773710, 0);
    second.sub_006EB7A0(DAT_0073C6BC, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_007736CC;
        DAT_0085D540 = made;
    } else {
        DAT_0085D540 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqEventStream::vfunc_01 (0x006F9C10, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarPosDist::vfunc_01 (0x002DB9F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventStream::vfunc_01 (0x006F9C10, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_00559000(int);
};

extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventStream
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

int SeqEventStream::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        if (!m_Field08.sub_00559000(a1)) goto L_29;
        return 1;
    }
L_29:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventStream::vfunc_00 (0x006F9C40, 48 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventVarPosDist::vfunc_01 (0x002DB9F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventStream::vfunc_00 (0x006F9C40, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    bool sub_006EC4F0(int);
};

extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventStream
{
public:
    virtual void vfunc_00();
    virtual int vfunc_00(int a1);
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
};

int SeqEventStream::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!m_Field08.sub_006EC4F0(a1)) goto L_29;
        return 1;
    }
L_29:
    return 0;
}

}

// [TODO] 0x006F9C70 audio::SeqActionStream::vfunc_02 (62 B)
// [TODO] 0x006F9CB0 audio::SeqActionStream::vfunc_03 (52 B)
// [TODO] 0x006F9CF0 sub_006F9CF0 (48 B)
// [TODO] 0x006F9D20 sub_006F9D20 (247 B)
// ============================================================================
// [VERIFIED] audio::SeqEventStream::vfunc_03 (0x006F9E20, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006F9E20
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventStream::vfunc_03 (0x006F9E20, 6 bytes)
extern "C" int DAT_0085D544;

namespace audio {

class SeqEventStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventStream::vfunc_03()
{
    return DAT_0085D544;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventStream::vfunc_04 (0x006F9E30, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventStream::vfunc_04 (0x006F9E30, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7BB0[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventStream
{
public:
    virtual SeqEventStream* vfunc_04(int a1);
};

SeqEventStream* SeqEventStream::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7BB0, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionStream::vfunc_00 (0x006F9E60, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionStream::vfunc_00 (0x006F9E60, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7BB8[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionStream
{
public:
    virtual SeqActionStream* vfunc_00(int a1);
};

SeqActionStream* SeqActionStream::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7BB8, (int)this);
    }
    return this;
}

}

// [TODO] 0x006F9E90 sub_006F9E90 (119 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventStream>::vfunc_01 (0x006F9F10, 49 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventStream>::vfunc_01 (0x002DC2F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventStream>::vfunc_01 (0x006F9F10, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_004A1B60();
    void sub_006F5850();
};

extern "C" char DAT_0077374C[];
extern "C" char DAT_007F7BB0[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventStream; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventStream>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F7BB0);
    if (t1) {
        ((Object*)t1)->sub_006F5850();
        *(int*)t1 = (int)DAT_0077374C;
        ((Object*)t1 + 8)->sub_004A1B60();
        return t1;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_006F9F50 (0x006F9F50, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773740[];
extern "C" char DAT_00773780[];
extern "C" char DAT_00773788[];
extern "C" Object* DAT_0085D544;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006F9F50(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_00773788, 0);
    second.sub_006EB7A0(DAT_00773780, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773740;
        DAT_0085D544 = made;
    } else {
        DAT_0085D544 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// [TODO] 0x006F9FD0 audio::SeqEventStream::vfunc_02 (96 B)
// [TODO] 0x006FA030 sub_006FA030 (824 B)
// [TODO] 0x006FA370 audio::SeqActionStream::vfunc_01 (133 B)
// [TODO] 0x006FA400 audio::SeqActionStream::vfunc_05 (580 B)
// [TODO] 0x006FA650 audio::SeqActionSilence::vfunc_02 (33 B)
// ============================================================================
// [VERIFIED] audio::SeqActionSilence::vfunc_01 (0x006FA680, 29 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionSilence::vfunc_01 (0x002DCAD0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionSilence::vfunc_01 (0x006FA680, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_006DC040(void);

namespace audio {

class SeqActionSilence
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1);
    void sub_006F57A0(int, int);
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

void SeqActionSilence::vfunc_01(int a1)
{
    m_Field1C = sub_006DC040();
    sub_006F57A0(3, a1);
}

}

// [TODO] 0x006FA6A0 audio::SeqActionWaitBeat::vfunc_03 (15 B)
// [TODO] 0x006FA6B0 audio::SeqActionWaitBeat::vfunc_04 (15 B)
// [TODO] 0x006FA6C0 audio::SeqActionSilence::vfunc_05 (113 B)
// ============================================================================
// [VERIFIED] audio::SeqEventSilence::vfunc_03 (0x006FA740, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006FA740
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventSilence::vfunc_03 (0x006FA740, 6 bytes)
extern "C" int DAT_0085D548;

namespace audio {

class SeqEventSilence
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventSilence::vfunc_03()
{
    return DAT_0085D548;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventSilence::vfunc_04 (0x006FA750, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventSilence::vfunc_04 (0x006FA750, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7C4C[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventSilence
{
public:
    virtual SeqEventSilence* vfunc_04(int a1);
};

SeqEventSilence* SeqEventSilence::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7C4C, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionSilence::vfunc_00 (0x006FA780, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionSilence::vfunc_00 (0x006FA780, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7C54[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionSilence
{
public:
    virtual SeqActionSilence* vfunc_00(int a1);
};

SeqActionSilence* SeqActionSilence::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7C54, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventSilence>::vfunc_01 (0x006FA7B0, 55 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventSilence>::vfunc_01 (0x002DCBC0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventSilence>::vfunc_01 (0x006FA7B0, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F5850();
};

extern "C" char DAT_007737B4[];
extern "C" char DAT_007F7C4C[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventSilence; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventSilence>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F7C4C);
    if (t1) {
        ((Object*)t1)->sub_006F5850();
        *(int*)t1 = (int)DAT_007737B4;
        *(int*)(t1 + 8) = 500;
        *(int*)(t1 + 12) = 1000;
        return t1;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_006FA7F0 (0x006FA7F0, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_007737A8[];
extern "C" char DAT_007737E8[];
extern "C" char DAT_007737F0[];
extern "C" Object* DAT_0085D548;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006FA7F0(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_007737F0, 0);
    second.sub_006EB7A0(DAT_007737E8, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_007737A8;
        DAT_0085D548 = made;
    } else {
        DAT_0085D548 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// [TODO] 0x006FA870 audio::SeqEventSilence::vfunc_02 (112 B)
// [TODO] 0x006FA8E0 audio::SeqEventLogicRepeat::vfunc_01 (109 B)
// [TODO] 0x006FA950 audio::SeqEventLogicRepeat::vfunc_00 (153 B)
// ============================================================================
// [VERIFIED] sub_006FA9F0 (0x006FA9F0, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773810[];
extern "C" char DAT_00773818[];
extern "C" char DAT_0077381C[];
extern "C" Object* DAT_0085D54C;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006FA9F0(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_0077381C, 0);
    second.sub_006EB7A0(DAT_00773818, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773810;
        DAT_0085D54C = made;
    } else {
        DAT_0085D54C = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] sub_006FAA70 (0x006FAA70, 34 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002DCE80 (0x002DCE80), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006FAA70 (0x006FAA70, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00773834[];
extern "C" void __cdecl sub_006F5850(void);

class Class_006FAA70
{
public:
    Class_006FAA70* sub_006FAA70();
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    bool m_Field10; // +0x10
    bool m_Field11; // +0x11
};

Class_006FAA70* Class_006FAA70::sub_006FAA70()
{
    sub_006F5850();
    m_Field08 = 0;
    m_Field0C = 0;
    m_Field10 = true;
    m_Field11 = true;
    m_Field00 = (int)DAT_00773834;
    return this;
}

// ============================================================================
// [VERIFIED] audio::SeqEventLogicRepeat::vfunc_04 (0x006FAAA0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventLogicRepeat::vfunc_04 (0x006FAAA0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7CF8[];
extern "C" void __cdecl sub_006F5C50(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventLogicRepeat
{
public:
    virtual SeqEventLogicRepeat* vfunc_04(int a1);
};

SeqEventLogicRepeat* SeqEventLogicRepeat::vfunc_04(int a1)
{
    sub_006F5C50();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7CF8, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventLogicRepeat::vfunc_03 (0x006FAAD0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006FAAD0
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventLogicRepeat::vfunc_03 (0x006FAAD0, 6 bytes)
extern "C" int DAT_0085D54C;

namespace audio {

class SeqEventLogicRepeat
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventLogicRepeat::vfunc_03()
{
    return DAT_0085D54C;
}

}

// [TODO] 0x006FAAE0 sub_006FAAE0 (116 B)
// ============================================================================
// [VERIFIED] audio::SeqCommandLogicRepeat::vfunc_01 (0x006FAB60, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqCommandLogicRepeat::vfunc_01 (0x006FAB60, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007730E0[];
extern "C" char DAT_007F7D00[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqCommandLogicRepeat
{
public:
    virtual SeqCommandLogicRepeat* vfunc_01(int a1);
};

SeqCommandLogicRepeat* SeqCommandLogicRepeat::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_007730E0;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7D00, (int)this);
    }
    return this;
}

}

// [TODO] 0x006FAB90 audio::SeqCommandLogicRepeat::vfunc_00 (114 B)
// [TODO] 0x006FAC10 audio::SeqEventType<audio::SeqEventLogicRepeat>::vfunc_01 (63 B)
// [TODO] 0x006FAC50 audio::SeqEventLogicRepeat::vfunc_02 (58 B)
// ============================================================================
// [VERIFIED] audio::SeqEventLogicOr::vfunc_01 (0x006FAC90, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventLogicOr::vfunc_01 (0x002DD0A0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventLogicOr::vfunc_01 (0x006FAC90, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F33F0(int, int);
extern "C" bool __stdcall sub_006F5760(int);

namespace audio {

class SeqEventLogicOr
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
    bool sub_006F5AC0(int);
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

int SeqEventLogicOr::vfunc_01(int a1)
{
    if (sub_006F5760(a1)) {
        if (!sub_006F33F0(a1, m_Field10)) goto L_39;
        if (!sub_006F5AC0(a1)) goto L_39;
        return 1;
    }
L_39:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventLogicOr::vfunc_00 (0x006FACD0, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventLogicOr::vfunc_00 (0x002DD0E0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventLogicOr::vfunc_00 (0x006FACD0, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F33D0(int, int);
extern "C" bool __stdcall sub_006F5740(int);

namespace audio {

class SeqEventLogicOr
{
public:
    virtual int vfunc_00(int a1);
    bool sub_006F5A60(int);
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

int SeqEventLogicOr::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006F33D0(a1, (int)(&m_Field10))) goto L_39;
        if (!sub_006F5A60(a1)) goto L_39;
        return 1;
    }
L_39:
    return 0;
}

}

// ============================================================================
// [VERIFIED] audio::SeqCommandLogicOr::vfunc_01 (0x006FAD10, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqCommandLogicOr::vfunc_01 (0x006FAD10, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007730E0[];
extern "C" char DAT_007F7D9C[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqCommandLogicOr
{
public:
    virtual SeqCommandLogicOr* vfunc_01(int a1);
};

SeqCommandLogicOr* SeqCommandLogicOr::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_007730E0;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7D9C, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] sub_006FAD40 (0x006FAD40, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773868[];
extern "C" char DAT_00771844[];
extern "C" char DAT_0077387C[];
extern "C" Object* DAT_0085D554;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006FAD40(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_0077387C, 0);
    second.sub_006EB7A0(DAT_00771844, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773868;
        DAT_0085D554 = made;
    } else {
        DAT_0085D554 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqEventLogicOr::vfunc_03 (0x006FADC0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006FADC0
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventLogicOr::vfunc_03 (0x006FADC0, 6 bytes)
extern "C" int DAT_0085D554;

namespace audio {

class SeqEventLogicOr
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventLogicOr::vfunc_03()
{
    return DAT_0085D554;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventLogicOr::vfunc_04 (0x006FADD0, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventLogicOr::vfunc_04 (0x006FADD0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7D94[];
extern "C" void __cdecl sub_006F5C50(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventLogicOr
{
public:
    virtual SeqEventLogicOr* vfunc_04(int a1);
};

SeqEventLogicOr* SeqEventLogicOr::vfunc_04(int a1)
{
    sub_006F5C50();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7D94, (int)this);
    }
    return this;
}

}

// [TODO] 0x006FAE00 audio::SeqEventLogicOr::vfunc_02 (59 B)
// [TODO] 0x006FAE40 audio::SeqCommandLogicOr::vfunc_00 (290 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventLogicOr>::vfunc_01 (0x006FAF70, 62 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventLogicOr>::vfunc_01 (0x002DD360), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventLogicOr>::vfunc_01 (0x006FAF70, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_006F5850();
};

extern "C" char DAT_00773890[];
extern "C" char DAT_007F7D94[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventLogicOr; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventLogicOr>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F7D94);
    if (t1) {
        ((Object*)t1)->sub_006F5850();
        *(int*)(t1 + 8) = 0;
        *(int*)(t1 + 12) = 0;
        *(int*)t1 = (int)DAT_00773890;
        *(int*)(t1 + 16) = 0x3F000000;
        return t1;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] audio::SeqActionCrossFade::vfunc_04 (0x006FAFB0, 40 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionCrossFade::vfunc_04 (0x002DD3A0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionCrossFade::vfunc_04 (0x006FAFB0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_006FDB80();
};

namespace audio {

class SeqActionCrossFade
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    void sub_006F57A0(int, int);
    char m_pad04[0x10];
    Field14* m_Field14; // +0x14
};

void SeqActionCrossFade::vfunc_04(int a1)
{
    if (m_Field14) {
        m_Field14->sub_006FDB80();
        m_Field14 = 0;
    }
    sub_006F57A0(0, a1);
}

}

// [TODO] 0x006FAFE0 sub_006FAFE0 (86 B)
// [TODO] 0x006FB040 audio::SeqEventCrossFade::vfunc_00 (192 B)
// ============================================================================
// [VERIFIED] audio::SeqActionCrossFade::vfunc_00 (0x006FB100, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionCrossFade::vfunc_00 (0x006FB100, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7E40[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionCrossFade
{
public:
    virtual SeqActionCrossFade* vfunc_00(int a1);
};

SeqActionCrossFade* SeqActionCrossFade::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7E40, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] sub_006FB130 (0x006FB130, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_007738BC[];
extern "C" char DAT_007738E0[];
extern "C" char DAT_007738E8[];
extern "C" Object* DAT_0085D558;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006FB130(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_007738E8, 0);
    second.sub_006EB7A0(DAT_007738E0, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_007738BC;
        DAT_0085D558 = made;
    } else {
        DAT_0085D558 = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// ============================================================================
// [VERIFIED] audio::SeqEventCrossFade::vfunc_03 (0x006FB240, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006FB240
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventCrossFade::vfunc_03 (0x006FB240, 6 bytes)
extern "C" int DAT_0085D558;

namespace audio {

class SeqEventCrossFade
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventCrossFade::vfunc_03()
{
    return DAT_0085D558;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventCrossFade::vfunc_04 (0x006FB250, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventCrossFade::vfunc_04 (0x002DD640), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventCrossFade::vfunc_04 (0x006FB250, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field1C
{
    void sub_006EBBD0();
};

struct Field2C
{
    void sub_00700EE0();
};

extern "C" char DAT_007F7E38[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventCrossFade
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual SeqEventCrossFade* vfunc_04(int a1);
    void sub_006F5730();
    char m_pad04[0x18];
    Field1C m_Field1C; // +0x1C
    char m_pad1D[0xF];
    Field2C m_Field2C; // +0x2C
};

SeqEventCrossFade* SeqEventCrossFade::vfunc_04(int a1)
{
    m_Field2C.sub_00700EE0();
    m_Field1C.sub_006EBBD0();
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7E38, (int)this);
    }
    return this;
}

}

// [TODO] 0x006FB290 audio::SeqEventCrossFade::vfunc_01 (194 B)
// [TODO] 0x006FB360 audio::SeqEventCrossFade::vfunc_02 (76 B)
// [TODO] 0x006FB3B0 audio::SeqActionCrossFade::vfunc_05 (181 B)
// [TODO] 0x006FB470 sub_006FB470 (52 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventCrossFade>::vfunc_01 (0x006FB4B0, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventChannelSendVolumes>::vfunc_01 (0x002D93F0), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventCrossFade>::vfunc_01 (0x006FB4B0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_006FB1B0();
};

extern "C" char DAT_007F7E38[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventCrossFade; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventCrossFade>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F7E38);
    if (t1) {
        return ((Object*)t1)->sub_006FB1B0();
    }
    return 0;
}

// [TODO] 0x006FB4D0 audio::SeqActionCrossFade::vfunc_02 (288 B)
// [TODO] 0x006FB5F0 audio::SeqActionCrossFade::vfunc_01 (411 B)
// [TODO] 0x006FB790 audio::SeqEventClip::vfunc_01 (65 B)
// [TODO] 0x006FB7E0 audio::SeqActionClip::vfunc_02 (44 B)
// ============================================================================
// [VERIFIED] audio::SeqActionClip::vfunc_03 (0x006FB810, 54 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionClip::vfunc_03 (0x002DDC10), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionClip::vfunc_03 (0x006FB810, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006EFC90(int);
extern "C" int __cdecl sub_006EFCE0(int);

namespace audio {

class SeqActionClip
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1);
    void sub_006F57A0(int, int);
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

void SeqActionClip::vfunc_03(int a1)
{
    int t1;

    t1 = m_Field1C;
    if (m_Field1C) {
        if (sub_006EFCE0(t1) != 1) goto L_24;
        sub_006EFC90(m_Field1C);
    }
L_24:
    sub_006F57A0(4, a1);
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionClip::vfunc_04 (0x006FB850, 54 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqActionClip::vfunc_04 (0x002DDC50), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionClip::vfunc_04 (0x006FB850, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006EFC90(int);
extern "C" int __cdecl sub_006EFCE0(int);

namespace audio {

class SeqActionClip
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    void sub_006F57A0(int, int);
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

void SeqActionClip::vfunc_04(int a1)
{
    int t1;

    t1 = m_Field1C;
    if (m_Field1C) {
        if (sub_006EFCE0(t1) != 1) goto L_24;
        sub_006EFC90(m_Field1C);
    }
L_24:
    sub_006F57A0(5, a1);
}

}

// [TODO] 0x006FB890 sub_006FB890 (217 B)
// ============================================================================
// [VERIFIED] audio::SeqEventClip::vfunc_03 (0x006FB970, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventNestTrack::vfunc_03 (PC 0x006F6960), which was matched first;
// its addresses and names were swapped for this function's.
// bin: pc
// va: 0x006FB970
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventClip::vfunc_03 (0x006FB970, 6 bytes)
extern "C" int DAT_0085D55C;

namespace audio {

class SeqEventClip
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventClip::vfunc_03()
{
    return DAT_0085D55C;
}

}

// ============================================================================
// [VERIFIED] audio::SeqEventClip::vfunc_04 (0x006FB980, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::StatePropSoundPlayer::vfunc_00 (0x00082430), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventClip::vfunc_04 (0x006FB980, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7EAC[];
extern "C" void __cdecl sub_006F5730(void);
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqEventClip
{
public:
    virtual SeqEventClip* vfunc_04(int a1);
};

SeqEventClip* SeqEventClip::vfunc_04(int a1)
{
    sub_006F5730();
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7EAC, (int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] audio::SeqActionClip::vfunc_00 (0x006FB9B0, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundManager::SoundPlayerHandle::vfunc_00 (0x00077F00), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqActionClip::vfunc_00 (0x006FB9B0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00772F80[];
extern "C" char DAT_007F7EB4[];
extern "C" void __cdecl sub_006EE890(int, int);

namespace audio {

class SeqActionClip
{
public:
    virtual SeqActionClip* vfunc_00(int a1);
};

SeqActionClip* SeqActionClip::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772F80;
    if (a1 & 1) {
        sub_006EE890((int)DAT_007F7EB4, (int)this);
    }
    return this;
}

}

// [TODO] 0x006FB9E0 sub_006FB9E0 (380 B)
// [TODO] 0x006FBB60 sub_006FBB60 (119 B)
// ============================================================================
// [VERIFIED] audio::SeqEventType<audio::SeqEventClip>::vfunc_01 (0x006FBBE0, 53 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as audio::SeqEventType<audio::SeqEventClip>::vfunc_01 (0x002DE200), which was matched first;
// its addresses and names were swapped for this function's.
// audio::SeqEventType<audio::SeqEventClip>::vfunc_01 (0x006FBBE0, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_004A1B60();
    void sub_006F5850();
};

extern "C" char DAT_0077393C[];
extern "C" char DAT_007F7EAC[];
extern "C" int __cdecl sub_006EE870(int);

namespace audio { class SeqEventClip; }

namespace audio { 
template <class T0> class SeqEventType
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
};
}

template <> int audio::SeqEventType<audio::SeqEventClip>::vfunc_01()
{
    int t1;

    t1 = sub_006EE870((int)DAT_007F7EAC);
    if (t1) {
        ((Object*)t1)->sub_006F5850();
        *(int*)t1 = (int)DAT_0077393C;
        *(bool*)(t1 + 12) = false;
        ((Object*)t1 + 16)->sub_004A1B60();
        return t1;
    }
    return 0;
}

// ============================================================================
// [VERIFIED] sub_006FBC20 (0x006FBC20, 116 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_002D8E20 (0x002D8E20), which was matched first;
// its addresses and names were swapped for this function's.
struct Name
{
    int data[3];
    void sub_006EB7A0(const char* text, int flags);
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F5BB0(Name* a, Name* b);
};

extern "C" char DAT_00773930[];
extern "C" char DAT_00756358[];
extern "C" char DAT_00773970[];
extern "C" Object* DAT_0085D55C;
extern "C" void* __cdecl sub_0043CE00(unsigned int size);

// Makes the single instance: builds it from two names and keeps it in a global (or null).
void __cdecl sub_006FBC20(void)
{
    Name first, second;

    first.sub_006EB7A0(DAT_00773970, 0);
    second.sub_006EB7A0(DAT_00756358, 0);
    Object* made = (Object*)sub_0043CE00(44);
    if (made) {
        made->sub_006F5BB0(&second, &first);
        *(void**)made = DAT_00773930;
        DAT_0085D55C = made;
    } else {
        DAT_0085D55C = 0;
    }
    second.sub_006EBBD0();
    first.sub_006EBBD0();
}

// [TODO] 0x006FBCA0 audio::SeqEventClip::vfunc_00 (104 B)
// [TODO] 0x006FBD10 audio::SeqEventClip::vfunc_02 (79 B)
// [TODO] 0x006FBD60 audio::SeqActionClip::vfunc_05 (472 B)
// [TODO] 0x006FBF40 audio::SeqActionClip::vfunc_01 (105 B)
// [TODO] 0x006FBFB0 sub_006FBFB0 (415 B)
// [TODO] 0x006FC150 sub_006FC150 (310 B)
// [TODO] 0x006FC290 sub_006FC290 (106 B)
// [TODO] 0x006FC300 sub_006FC300 (30 B)
// [TODO] 0x006FC320 sub_006FC320 (1486 B)
// [TODO] 0x006FC910 sub_006FC910 (26 B)
// [TODO] 0x006FCF70 sub_006FCF70 (31 B)
// [TODO] 0x006FCF90 sub_006FCF90 (69 B)
// [TODO] 0x006FCFE0 sub_006FCFE0 (45 B)
// [TODO] 0x006FD010 sub_006FD010 (43 B)
// [TODO] 0x006FD040 sub_006FD040 (666 B)
// [TODO] 0x006FD740 sub_006FD740 (237 B)
// ============================================================================
// [VERIFIED] sub_006FD830 (0x006FD830, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006FD830 (0x006FD830, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7F30[];
extern "C" void __stdcall sub_006EE870(int);

class Class_006FD830
{
public:
    void sub_006FD830(int a1);
};

void Class_006FD830::sub_006FD830(int a1)
{
    a1 = (int)DAT_007F7F30;
    sub_006EE870(a1);
}

// ============================================================================
// [VERIFIED] sub_006FD840 (0x006FD840, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006FD840 (0x006FD840, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7F30[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006FD840(int a1)
{
    sub_006EE890((int)DAT_007F7F30, a1);
}

// ============================================================================
// [VERIFIED] sub_006FD860 (0x006FD860, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006FD860 (0x006FD860, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7F38[];
extern "C" void __stdcall sub_006EE870(int);

class Class_006FD860
{
public:
    void sub_006FD860(int a1);
};

void Class_006FD860::sub_006FD860(int a1)
{
    a1 = (int)DAT_007F7F38;
    sub_006EE870(a1);
}

// ============================================================================
// [VERIFIED] sub_006FD870 (0x006FD870, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006FD870 (0x006FD870, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7F40[];
extern "C" void __stdcall sub_006EE870(int);

class Class_006FD870
{
public:
    void sub_006FD870(int a1);
};

void Class_006FD870::sub_006FD870(int a1)
{
    a1 = (int)DAT_007F7F40;
    sub_006EE870(a1);
}

// [TODO] 0x006FD880 sub_006FD880 (245 B)
// [TODO] 0x006FD980 sub_006FD980 (57 B)
// ============================================================================
// [VERIFIED] sub_006FD9C0 (0x006FD9C0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006FD9C0 (0x006FD9C0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7F4C[];
extern "C" void __stdcall sub_006EE870(int);

class Class_006FD9C0
{
public:
    void sub_006FD9C0(int a1);
};

void Class_006FD9C0::sub_006FD9C0(int a1)
{
    a1 = (int)DAT_007F7F4C;
    sub_006EE870(a1);
}

// ============================================================================
// [VERIFIED] sub_006FD9D0 (0x006FD9D0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006FD9D0 (0x006FD9D0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7F4C[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006FD9D0(int a1)
{
    sub_006EE890((int)DAT_007F7F4C, a1);
}

// [TODO] 0x006FD9F0 SoundLoadSequence::vfunc_00 (6 B)
// [TODO] 0x006FDA00 sub_006FDA00 (5 B)
// [TODO] 0x006FDA10 sub_006FDA10 (221 B)
// [TODO] 0x006FDAF0 sub_006FDAF0 (24 B)
// [TODO] 0x006FDB80 sub_006FDB80 (40 B)
// [TODO] 0x006FDBB0 sub_006FDBB0 (179 B)
// [TODO] 0x006FDC70 sub_006FDC70 (336 B)
// [TODO] 0x006FDDC0 sub_006FDDC0 (249 B)
// [TODO] 0x006FDEC0 sub_006FDEC0 (146 B)
// [TODO] 0x006FDF60 sub_006FDF60 (77 B)
// [TODO] 0x006FDFB0 sub_006FDFB0 (115 B)
// [TODO] 0x006FE030 sub_006FE030 (114 B)
// [TODO] 0x006FE0B0 sub_006FE0B0 (175 B)
// [TODO] 0x006FE160 sub_006FE160 (429 B)
// [TODO] 0x006FE310 sub_006FE310 (140 B)
// ============================================================================
// [VERIFIED] sub_006FE3A0 (0x006FE3A0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006FE3A0 (0x006FE3A0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7F60[];
extern "C" void __stdcall sub_006EE870(int);

class Class_006FE3A0
{
public:
    void sub_006FE3A0(int a1);
};

void Class_006FE3A0::sub_006FE3A0(int a1)
{
    a1 = (int)DAT_007F7F60;
    sub_006EE870(a1);
}

// ============================================================================
// [VERIFIED] sub_006FE3B0 (0x006FE3B0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006FE3B0 (0x006FE3B0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7F60[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006FE3B0(int a1)
{
    sub_006EE890((int)DAT_007F7F60, a1);
}

// ============================================================================
// [VERIFIED] sub_006FE3D0 (0x006FE3D0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006FE3D0 (0x006FE3D0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7F68[];
extern "C" void __stdcall sub_006EE870(int);

class Class_006FE3D0
{
public:
    void sub_006FE3D0(int a1);
};

void Class_006FE3D0::sub_006FE3D0(int a1)
{
    a1 = (int)DAT_007F7F68;
    sub_006EE870(a1);
}

// ============================================================================
// [VERIFIED] sub_006FE3E0 (0x006FE3E0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006FE3E0 (0x006FE3E0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007F7F68[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_006FE3E0(int a1)
{
    sub_006EE890((int)DAT_007F7F68, a1);
}

// [TODO] 0x006FE400 sub_006FE400 (29 B)
// [TODO] 0x006FE420 sub_006FE420 (124 B)
// [TODO] 0x006FE4A0 sub_006FE4A0 (98 B)
// [TODO] 0x006FE510 sub_006FE510 (47 B)
// [TODO] 0x006FE540 sub_006FE540 (230 B)
// [TODO] 0x006FE670 sub_006FE670 (9 B)
// [TODO] 0x006FE680 sub_006FE680 (29 B)
// [TODO] 0x006FE6A0 sub_006FE6A0 (196 B)
// [TODO] 0x006FE770 sub_006FE770 (56 B)
// [TODO] 0x006FE7B0 sub_006FE7B0 (24 B)
// [TODO] 0x006FE7D0 sub_006FE7D0 (21 B)
// [TODO] 0x006FE7F0 sub_006FE7F0 (62 B)
// [TODO] 0x006FE830 sub_006FE830 (125 B)
// [TODO] 0x006FE8B0 sub_006FE8B0 (711 B)
// [TODO] 0x006FEB80 sub_006FEB80 (79 B)
// [TODO] 0x006FEBD0 sub_006FEBD0 (1986 B)
// [TODO] 0x006FF3A0 sub_006FF3A0 (14 B)
// [TODO] 0x006FF3B0 sub_006FF3B0 (50 B)
// [TODO] 0x006FF3F0 sub_006FF3F0 (154 B)
// [TODO] 0x006FF490 om::TRbTree<om::PointerUid, 0>::Comp<om::PointerUid, 0, unsigned __int64>::vfunc_00 (61 B)
// [TODO] 0x006FF4D0 sub_006FF4D0 (155 B)
// [TODO] 0x006FF570 sub_006FF570 (12 B)
// [TODO] 0x006FF580 sub_006FF580 (118 B)
// [TODO] 0x006FF600 sub_006FF600 (58 B)
// [TODO] 0x006FF700 sub_006FF700 (49 B)
// [TODO] 0x006FF740 sub_006FF740 (98 B)
// [TODO] 0x006FF7B0 sub_006FF7B0 (35 B)
// [TODO] 0x006FF8A0 sub_006FF8A0 (134 B)
// [TODO] 0x006FF930 sub_006FF930 (14 B)
// ============================================================================
// [VERIFIED] sub_006FFB20 (0x006FFB20, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_006FFB20 (0x006FFB20, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00490965(void);

class Class_006FFB20
{
public:
    void sub_006FFB20();
};

void Class_006FFB20::sub_006FFB20()
{
    sub_00490965();
}

// ============================================================================
// [VERIFIED] sub_007001D0 (0x007001D0, 13 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_0007F7F0 (0x0007F7F0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_007001D0 (0x007001D0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FB3D4[];
extern "C" void __stdcall sub_006EE870(int);

class Class_007001D0
{
public:
    void sub_007001D0(int a1);
};

void Class_007001D0::sub_007001D0(int a1)
{
    a1 = (int)DAT_007FB3D4;
    sub_006EE870(a1);
}

// ============================================================================
// [VERIFIED] sub_007001E0 (0x007001E0, 19 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00081980 (0x00081980), which was matched first;
// its addresses and names were swapped for this function's.
// sub_007001E0 (0x007001E0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FB3D4[];
extern "C" void __cdecl sub_006EE890(int, int);

void __cdecl sub_007001E0(int a1)
{
    sub_006EE890((int)DAT_007FB3D4, a1);
}

// [TODO] 0x00700200 FETextObject::vfunc_46 (4 B)
// [TODO] 0x00700210 sub_00700210 (223 B)
// [TODO] 0x007002F0 sub_007002F0 (77 B)
// [TODO] 0x00700340 sub_00700340 (51 B)
// [TODO] 0x00700380 sub_00700380 (44 B)
// [TODO] 0x007003B0 sub_007003B0 (42 B)
// ============================================================================
// [VERIFIED] sub_007003E0 (0x007003E0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_007003E0 (0x007003E0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00FB1258;

class Class_007003E0
{
public:
    void sub_007003E0();
};

void Class_007003E0::sub_007003E0()
{
    ((void (__cdecl*)(void))DAT_00FB1258)();
}

// [TODO] 0x00700660 sub_00700660 (125 B)
// [TODO] 0x007006E0 sub_007006E0 (90 B)
// [TODO] 0x00700740 sub_00700740 (37 B)
// [TODO] 0x00700770 sub_00700770 (42 B)
// [TODO] 0x007007A0 sub_007007A0 (47 B)
// [TODO] 0x007007D0 sub_007007D0 (86 B)
// [TODO] 0x00700830 sub_00700830 (608 B)
// [TODO] 0x00700A90 sub_00700A90 (53 B)
// [TODO] 0x00700AD0 sub_00700AD0 (114 B)
// [TODO] 0x00700B50 sub_00700B50 (8 B)
// [TODO] 0x00700C30 sub_00700C30 (103 B)
// [TODO] 0x00700CA0 sub_00700CA0 (56 B)
// [TODO] 0x00700CE0 sub_00700CE0 (58 B)
// [TODO] 0x00700D20 sub_00700D20 (104 B)
// [TODO] 0x00700D90 sub_00700D90 (131 B)
// [TODO] 0x00700E20 sub_00700E20 (139 B)
// ============================================================================
// [VERIFIED] sub_00700EE0 (0x00700EE0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00700EE0 (0x00700EE0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00700EB0(void);

class Class_00700EE0
{
public:
    void sub_00700EE0();
};

void Class_00700EE0::sub_00700EE0()
{
    sub_00700EB0();
}

// [TODO] 0x00700EF0 sub_00700EF0 (16 B)
// [TODO] 0x00700F00 sub_00700F00 (18 B)
// [TODO] 0x00700F20 sub_00700F20 (12 B)
// [TODO] 0x00700F30 sub_00700F30 (12 B)
// [TODO] 0x00700FD0 movie::PlayerBink::vfunc_07 (135 B)
// [TODO] 0x00701060 movie::PlayerBink::vfunc_11 (113 B)
// [TODO] 0x007010E0 movie::PlayerBink::vfunc_14 (36 B)
// [TODO] 0x00701110 movie::PlayerBink::vfunc_15 (54 B)
// [TODO] 0x00701150 movie::PlayerBink::vfunc_16 (14 B)
// [TODO] 0x00701160 sub_00701160 (139 B)
// [TODO] 0x007011F0 sub_007011F0 (5421 B)
// [TODO] 0x00701220 sub_00701220 (3291 B)
// [TODO] 0x00701230 movie::PlayerBink::vfunc_04 (75 B)
// [TODO] 0x00701280 movie::PlayerBink::vfunc_05 (12 B)
// [TODO] 0x00701290 movie::PlayerBink::vfunc_06 (196 B)
// [TODO] 0x00701360 movie::PlayerBink::vfunc_08 (35 B)
// [TODO] 0x00701390 movie::PlayerBink::vfunc_09 (46 B)
// [TODO] 0x007013C0 movie::PlayerBink::vfunc_10 (46 B)
// [TODO] 0x00701580 movie::PlayerBink::vfunc_00 (8 B)
// [TODO] 0x00701590 sub_00701590 (101 B)
// ============================================================================
// [VERIFIED] movie::PlayerBink::vfunc_03 (0x00701630, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// movie::PlayerBink::vfunc_03 (0x00701630, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);
extern "C" void __cdecl sub_00701590(void);

namespace movie {

class PlayerBink
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual PlayerBink* vfunc_03(int a1);
};

PlayerBink* PlayerBink::vfunc_03(int a1)
{
    sub_00701590();
    if (a1 & 1) {
        sub_006DC430(DAT_007F5A70, (int)this);
    }
    return this;
}

}

// [TODO] 0x00701660 sub_00701660 (98 B)
// ============================================================================
// [VERIFIED] GameMemorySegmentCollection::vfunc_01 (0x007016D0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GameMemorySegmentCollection::vfunc_01 (0x00026D90), which was matched first;
// its addresses and names were swapped for this function's.
// GameMemorySegmentCollection::vfunc_01 (0x007016D0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0043C590();
};

class GameMemorySegmentCollection
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void GameMemorySegmentCollection::vfunc_01()
{
    ((Object*)(int)this + 4)->sub_0043C590();
}

// ============================================================================
// [VERIFIED] movie::RenderStrategyBink::vfunc_04 (0x007016E0, 8 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as movie::RenderStrategyBink::vfunc_04 (0x002E3070), which was matched first;
// its addresses and names were swapped for this function's.
// movie::RenderStrategyBink::vfunc_04 (0x007016E0, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace movie {

class RenderStrategyBink
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    char m_pad04[0x2C];
    int m_Field30; // +0x30
};

void RenderStrategyBink::vfunc_04()
{
    m_Field30 = 0;
}

}

// [TODO] 0x007016F0 movie::RenderStrategyBink::vfunc_05 (136 B)
// [TODO] 0x00701780 movie::RenderStrategyBink::vfunc_06 (36 B)
// [TODO] 0x007017B0 movie::RenderStrategyBink::vfunc_09 (802 B)
// [TODO] 0x00701AE0 movie::RenderStrategyBink::vfunc_00 (8 B)
// ============================================================================
// [VERIFIED] movie::RenderStrategyBink::vfunc_03 (0x00701B90, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as core::ControllerSystemXBox::vfunc_03 (0x00248820), which was matched first;
// its addresses and names were swapped for this function's.
// movie::RenderStrategyBink::vfunc_03 (0x00701B90, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_007F5A70;
extern "C" void __cdecl sub_006DC430(int, int);
extern "C" void __cdecl sub_00701660(void);

namespace movie {

class RenderStrategyBink
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual RenderStrategyBink* vfunc_03(int a1);
};

RenderStrategyBink* RenderStrategyBink::vfunc_03(int a1)
{
    sub_00701660();
    if (a1 & 1) {
        sub_006DC430(DAT_007F5A70, (int)this);
    }
    return this;
}

}

// [TODO] 0x00701BC0 movie::RenderStrategyBink::vfunc_07 (746 B)
// ============================================================================
// [VERIFIED] sub_00702090 (0x00702090, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702090 (0x00702090, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00FB4980;

class Class_00702090
{
public:
    void sub_00702090();
};

void Class_00702090::sub_00702090()
{
    ((void (__cdecl*)(void))DAT_00FB4980)();
}

// [TODO] 0x007021C0 sub_007021C0 (35 B)
// [TODO] 0x007025A0 movie::BinkCallback::vfunc_04 (218 B)
// [TODO] 0x00702680 movie::BinkCallback::vfunc_03 (8 B)
// [TODO] 0x00702690 movie::BinkCallback::vfunc_00 (63 B)
// ============================================================================
// [VERIFIED] sub_0070271E (0x0070271E, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0070271E (0x0070271E, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F2F4;

class Class_0070271E
{
public:
    void sub_0070271E();
};

void Class_0070271E::sub_0070271E()
{
    ((void (__cdecl*)(void))DAT_0072F2F4)();
}

// ============================================================================
// [VERIFIED] sub_00702724 (0x00702724, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702724 (0x00702724, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F340;

class Class_00702724
{
public:
    void sub_00702724();
};

void Class_00702724::sub_00702724()
{
    ((void (__cdecl*)(void))DAT_0072F340)();
}

// ============================================================================
// [VERIFIED] sub_0070272A (0x0070272A, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0070272A (0x0070272A, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F33C;

class Class_0070272A
{
public:
    void sub_0070272A();
};

void Class_0070272A::sub_0070272A()
{
    ((void (__cdecl*)(void))DAT_0072F33C)();
}

// ============================================================================
// [VERIFIED] sub_00702730 (0x00702730, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702730 (0x00702730, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F344;

class Class_00702730
{
public:
    void sub_00702730();
};

void Class_00702730::sub_00702730()
{
    ((void (__cdecl*)(void))DAT_0072F344)();
}

// ============================================================================
// [VERIFIED] sub_00702736 (0x00702736, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702736 (0x00702736, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F338;

class Class_00702736
{
public:
    void sub_00702736();
};

void Class_00702736::sub_00702736()
{
    ((void (__cdecl*)(void))DAT_0072F338)();
}

// ============================================================================
// [VERIFIED] sub_0070273C (0x0070273C, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0070273C (0x0070273C, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F334;

class Class_0070273C
{
public:
    void sub_0070273C();
};

void Class_0070273C::sub_0070273C()
{
    ((void (__cdecl*)(void))DAT_0072F334)();
}

// ============================================================================
// [VERIFIED] sub_00702742 (0x00702742, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702742 (0x00702742, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F330;

class Class_00702742
{
public:
    void sub_00702742();
};

void Class_00702742::sub_00702742()
{
    ((void (__cdecl*)(void))DAT_0072F330)();
}

// [TODO] 0x00702748 sub_00702748 (38 B)
// [TODO] 0x0070276E sub_0070276E (18 B)
// [TODO] 0x00702780 type_info::vfunc_00 (75 B)
// ============================================================================
// [VERIFIED] sub_007027CC (0x007027CC, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_007027CC (0x007027CC, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F220;

class Class_007027CC
{
public:
    void sub_007027CC();
};

void Class_007027CC::sub_007027CC()
{
    ((void (__cdecl*)(void))DAT_0072F220)();
}

// [TODO] 0x007027E6 fight::ConditionFactory::vfunc_07 (6 B)
// ============================================================================
// [VERIFIED] sub_00702810 (0x00702810, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702810 (0x00702810, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0041EA26(void);

class Class_00702810
{
public:
    void sub_00702810();
};

void Class_00702810::sub_00702810()
{
    sub_0041EA26();
}

// [TODO] 0x0070284D sub_0070284D (74 B)
// [TODO] 0x00702897 sub_00702897 (24 B)
// [TODO] 0x007028AF sub_007028AF (47 B)
// [TODO] 0x0070290D sub_0070290D (72 B)
// [TODO] 0x00702955 sub_00702955 (24 B)
// [TODO] 0x0070297C sub_0070297C (117 B)
// [TODO] 0x00702A00 sub_00702A00 (31 B)
// ============================================================================
// [VERIFIED] sub_00702A20 (0x00702A20, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702A20 (0x00702A20, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F1B0;

class Class_00702A20
{
public:
    void sub_00702A20();
};

void Class_00702A20::sub_00702A20()
{
    ((void (__cdecl*)(void))DAT_0072F1B0)();
}

// ============================================================================
// [VERIFIED] sub_00702A26 (0x00702A26, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702A26 (0x00702A26, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F120;

class Class_00702A26
{
public:
    void sub_00702A26();
};

void Class_00702A26::sub_00702A26()
{
    ((void (__cdecl*)(void))DAT_0072F120)();
}

// [TODO] 0x00702CB0 sub_00702CB0 (52 B)
// [TODO] 0x00702D90 sub_00702D90 (117 B)
// ============================================================================
// [VERIFIED] sub_00702E06 (0x00702E06, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702E06 (0x00702E06, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F164;

class Class_00702E06
{
public:
    void sub_00702E06();
};

void Class_00702E06::sub_00702E06()
{
    ((void (__cdecl*)(void))DAT_0072F164)();
}

// ============================================================================
// [VERIFIED] sub_00702E0C (0x00702E0C, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702E0C (0x00702E0C, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F16C;

class Class_00702E0C
{
public:
    void sub_00702E0C();
};

void Class_00702E0C::sub_00702E0C()
{
    ((void (__cdecl*)(void))DAT_0072F16C)();
}

// ============================================================================
// [VERIFIED] sub_00702E14 (0x00702E14, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00023D40 (0x00023D40), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702E14 (0x00702E14, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0049AB8F(void);

class Class_00702E14
{
public:
    void sub_00702E14();
};

void Class_00702E14::sub_00702E14()
{
    sub_0049AB8F();
}

// [TODO] 0x00702E4F sub_00702E4F (17 B)
// ============================================================================
// [VERIFIED] sub_00702E66 (0x00702E66, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702E66 (0x00702E66, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F174;

class Class_00702E66
{
public:
    void sub_00702E66();
};

void Class_00702E66::sub_00702E66()
{
    ((void (__cdecl*)(void))DAT_0072F174)();
}

// ============================================================================
// [VERIFIED] sub_00702E6C (0x00702E6C, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702E6C (0x00702E6C, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F17C;

class Class_00702E6C
{
public:
    void sub_00702E6C();
};

void Class_00702E6C::sub_00702E6C()
{
    ((void (__cdecl*)(void))DAT_0072F17C)();
}

// ============================================================================
// [VERIFIED] sub_00702E72 (0x00702E72, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702E72 (0x00702E72, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F18C;

class Class_00702E72
{
public:
    void sub_00702E72();
};

void Class_00702E72::sub_00702E72()
{
    ((void (__cdecl*)(void))DAT_0072F18C)();
}

// [TODO] 0x00702E78 sub_00702E78 (68 B)
// ============================================================================
// [VERIFIED] sub_00702F00 (0x00702F00, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702F00 (0x00702F00, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F194;

class Class_00702F00
{
public:
    void sub_00702F00();
};

void Class_00702F00::sub_00702F00()
{
    ((void (__cdecl*)(void))DAT_0072F194)();
}

// [TODO] 0x00702F06 sub_00702F06 (18 B)
// ============================================================================
// [VERIFIED] sub_00702F18 (0x00702F18, 3 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// sub_00702F18 (PC 0x00702F18, 3 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_00702F18(void)
{
    return 0;
}

// ============================================================================
// [VERIFIED] sub_00702F1C (0x00702F1C, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00702F1C (0x00702F1C, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F1AC;

class Class_00702F1C
{
public:
    void sub_00702F1C();
};

void Class_00702F1C::sub_00702F1C()
{
    ((void (__cdecl*)(void))DAT_0072F1AC)();
}

// ============================================================================
// [VERIFIED] pure3d::pddiDevice::vfunc_03 (0x00702F40, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LOSManager::LOSManagerFlowClient::vfunc_00 (0x000179C0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::pddiDevice::vfunc_03 (0x00702F40, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007747AC[];
extern "C" void __cdecl sub_0043CE70(int);
extern "C" void __cdecl sub_0065C9D0(void);

namespace pure3d {

class pddiDevice
{
public:
    virtual pddiDevice* vfunc_03(int a1);
};

pddiDevice* pddiDevice::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_007747AC;
    sub_0065C9D0();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x00702F70 sub_00702F70 (107 B)
// [TODO] 0x00702FE0 pure3d::d3dDevice::vfunc_05 (63 B)
// [TODO] 0x00703020 pure3d::d3dDevice::vfunc_04 (728 B)
// [TODO] 0x00703300 pure3d::d3dDevice::vfunc_06 (10 B)
// [TODO] 0x00703310 pure3d::d3dDevice::vfunc_08 (78 B)
// [TODO] 0x00703360 pure3d::d3dDevice::vfunc_09 (63 B)
// [TODO] 0x007033A0 pure3d::d3dDevice::vfunc_10 (183 B)
// [TODO] 0x00703460 pure3d::d3dDevice::vfunc_11 (109 B)
// [TODO] 0x007034D0 pure3d::d3dDevice::vfunc_15 (112 B)
// [TODO] 0x00703540 pure3d::d3dDevice::vfunc_12 (22 B)
// [TODO] 0x00703560 sub_00703560 (47 B)
// ============================================================================
// [VERIFIED] pure3d::d3dDevice::vfunc_03 (0x00703590, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dDevice::vfunc_03 (0x00703590, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00702F70(void);
extern "C" void __cdecl sub_0043CE70(int);

namespace pure3d {

class d3dDevice
{
public:
    virtual d3dDevice* vfunc_03(int a1);
};

d3dDevice* d3dDevice::vfunc_03(int a1)
{
    sub_00702F70();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] pure3d::pddiPrimBuffer::vfunc_03 (0x00703610, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LOSManager::LOSManagerFlowClient::vfunc_00 (0x000179C0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::pddiPrimBuffer::vfunc_03 (0x00703610, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0077484C[];
extern "C" void __cdecl sub_0043CE70(int);
extern "C" void __cdecl sub_0065C9D0(void);

namespace pure3d {

class pddiPrimBuffer
{
public:
    virtual pddiPrimBuffer* vfunc_03(int a1);
};

pddiPrimBuffer* pddiPrimBuffer::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_0077484C;
    sub_0065C9D0();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x00703640 sub_00703640 (72 B)
// [TODO] 0x00703690 sub_00703690 (276 B)
// [TODO] 0x007037B0 sub_007037B0 (159 B)
// [TODO] 0x00703850 sub_00703850 (117 B)
// [TODO] 0x007038D0 sub_007038D0 (161 B)
// [TODO] 0x00703980 sub_00703980 (128 B)
// [TODO] 0x00703A00 pure3d::d3dPrimBuffer::vfunc_04 (138 B)
// [TODO] 0x00703A90 pure3d::d3dPrimBuffer::vfunc_05 (70 B)
// [TODO] 0x00703AE0 pure3d::d3dPrimBuffer::vfunc_07 (48 B)
// [TODO] 0x00703B10 pure3d::d3dPrimBuffer::vfunc_08 (27 B)
// [TODO] 0x00703B30 pure3d::d3dPrimBuffer::vfunc_10 (16 B)
// [TODO] 0x00703B40 pure3d::d3dPrimBuffer::vfunc_11 (62 B)
// [TODO] 0x00703B80 pure3d::d3dPrimBuffer::vfunc_12 (61 B)
// [TODO] 0x00703BC0 pure3d::d3dPrimBuffer::vfunc_09 (85 B)
// [TODO] 0x00703C20 sub_00703C20 (64 B)
// [TODO] 0x00703C60 pure3d::d3dPrimBuffer::vfunc_15 (322 B)
// ============================================================================
// [VERIFIED] pure3d::d3dContext::vfunc_13 (0x00703DB0, 3 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dContext::vfunc_13 (0x0029D5D0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dContext::vfunc_13 (0x00703DB0, 3 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class d3dContext
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13(int a1, int a2, int a3, int a4);
};

void d3dContext::vfunc_13(int a1, int a2, int a3, int a4)
{
}

}

// [TODO] 0x00703DC0 pure3d::d3dPrimBufferStream::vfunc_15 (3 B)
// ============================================================================
// [VERIFIED] pure3d::d3dPrimBufferStream::vfunc_24 (0x00703DD0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as renderer::InstanceRenderable::vfunc_10 (0x00054F90), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dPrimBufferStream::vfunc_24 (0x00703DD0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_007037B0(void);

namespace pure3d {

class d3dPrimBufferStream
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
    virtual void vfunc_24();
};

void d3dPrimBufferStream::vfunc_24()
{
    sub_007037B0();
}

}

// [TODO] 0x00703DE0 sub_00703DE0 (9 B)
// [TODO] 0x00703F80 sub_00703F80 (77 B)
// ============================================================================
// [VERIFIED] pure3d::d3dPrimBuffer::vfunc_03 (0x00703FD0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dPrimBuffer::vfunc_03 (0x00703FD0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00703850(void);
extern "C" void __cdecl sub_0043CE70(int);

namespace pure3d {

class d3dPrimBuffer
{
public:
    virtual d3dPrimBuffer* vfunc_03(int a1);
};

d3dPrimBuffer* d3dPrimBuffer::vfunc_03(int a1)
{
    sub_00703850();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x00703FF0 sub_00703FF0 (119 B)
// [TODO] 0x00704070 pure3d::d3dPrimBufferStream::vfunc_00 (48 B)
// [TODO] 0x007040A0 pure3d::d3dPrimBufferStream::vfunc_01 (263 B)
// [TODO] 0x007041B0 pure3d::d3dPrimBufferStream::vfunc_11 (42 B)
// [TODO] 0x007041E0 pure3d::d3dPrimBufferStream::vfunc_13 (37 B)
// [TODO] 0x00704210 pure3d::d3dPrimBufferStream::vfunc_16 (21 B)
// [TODO] 0x00704230 pure3d::d3dPrimBufferStream::vfunc_09 (41 B)
// [TODO] 0x00704260 pure3d::d3dPrimBufferStream::vfunc_10 (41 B)
// [TODO] 0x00704290 pure3d::d3dPrimBufferStream::vfunc_07 (41 B)
// [TODO] 0x007042C0 pure3d::d3dPrimBufferStream::vfunc_08 (41 B)
// [TODO] 0x007042F0 pure3d::d3dPrimBufferStream::vfunc_17 (61 B)
// [TODO] 0x00704330 pure3d::d3dPrimBufferStream::vfunc_18 (41 B)
// [TODO] 0x00704360 pure3d::d3dPrimBufferStream::vfunc_23 (51 B)
// [TODO] 0x007043A0 pure3d::d3dPrimBufferStream::vfunc_22 (64 B)
// [TODO] 0x007043E0 pure3d::d3dPrimBufferStream::vfunc_21 (59 B)
// [TODO] 0x00704420 pure3d::d3dPrimBufferStream::vfunc_20 (68 B)
// [TODO] 0x00704470 pure3d::d3dPrimBufferStream::vfunc_19 (81 B)
// [TODO] 0x00704770 sub_00704770 (346 B)
// ============================================================================
// [VERIFIED] pure3d::d3dErrorShader::vfunc_04 (0x007048D0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dVehicleShader::vfunc_04 (0x002829C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x007048D0
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dErrorShader::vfunc_04 (0x007048D0, 6 bytes)
extern "C" char DAT_007FB648[];

namespace pure3d {

class d3dErrorShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dErrorShader::vfunc_04()
{
    return DAT_007FB648;
}

}

// [TODO] 0x007048E0 sub_007048E0 (50 B)
// [TODO] 0x00704920 pure3d::d3dErrorShader::vfunc_15 (226 B)
// [TODO] 0x00704A10 sub_00704A10 (36 B)
// ============================================================================
// [VERIFIED] pure3d::d3dReflShader::vfunc_16 (0x00704A40, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dReflShader::vfunc_16 (0x00704A40, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FB7F0[];

namespace pure3d {

class d3dReflShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_16();
};

void* d3dReflShader::vfunc_16()
{
    return DAT_007FB7F0;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dReflShader::vfunc_17 (0x00704A50, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dReflShader::vfunc_17 (0x00704A50, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FB718[];

namespace pure3d {

class d3dReflShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_17();
};

void* d3dReflShader::vfunc_17()
{
    return DAT_007FB718;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dReflShader::vfunc_18 (0x00704A60, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dReflShader::vfunc_18 (0x00704A60, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FB6D0[];

namespace pure3d {

class d3dReflShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_18();
};

void* d3dReflShader::vfunc_18()
{
    return DAT_007FB6D0;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dReflShader::vfunc_19 (0x00704A70, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dReflShader::vfunc_19 (0x00704A70, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FB838[];

namespace pure3d {

class d3dReflShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_19();
};

void* d3dReflShader::vfunc_19()
{
    return DAT_007FB838;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dReflShader::vfunc_04 (0x00704A80, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dVehicleShader::vfunc_04 (0x002829C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00704A80
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dReflShader::vfunc_04 (0x00704A80, 6 bytes)
extern "C" char DAT_007FB6AC[];

namespace pure3d {

class d3dReflShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dReflShader::vfunc_04()
{
    return DAT_007FB6AC;
}

}

// [TODO] 0x00704A90 pure3d::d3dReflShader::vfunc_13 (164 B)
// [TODO] 0x00704B40 pure3d::d3dReflShader::vfunc_14 (156 B)
// [TODO] 0x00704BE0 sub_00704BE0 (49 B)
// [TODO] 0x00704C20 pure3d::d3dReflShader::vfunc_03 (68 B)
// [TODO] 0x00704C70 pure3d::d3dReflShader::vfunc_15 (977 B)
// ============================================================================
// [VERIFIED] pure3d::d3dPointSpriteShader::vfunc_16 (0x00705050, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dPointSpriteShader::vfunc_16 (0x00705050, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FB9D8[];

namespace pure3d {

class d3dPointSpriteShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_16();
};

void* d3dPointSpriteShader::vfunc_16()
{
    return DAT_007FB9D8;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPointSpriteShader::vfunc_17 (0x00705060, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dPointSpriteShader::vfunc_17 (0x00705060, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FBA08[];

namespace pure3d {

class d3dPointSpriteShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_17();
};

void* d3dPointSpriteShader::vfunc_17()
{
    return DAT_007FBA08;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPointSpriteShader::vfunc_18 (0x00705070, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dPointSpriteShader::vfunc_18 (0x00705070, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FB918[];

namespace pure3d {

class d3dPointSpriteShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_18();
};

void* d3dPointSpriteShader::vfunc_18()
{
    return DAT_007FB918;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dPointSpriteShader::vfunc_04 (0x00705080, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dVehicleShader::vfunc_04 (0x002829C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00705080
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dPointSpriteShader::vfunc_04 (0x00705080, 6 bytes)
extern "C" char DAT_007FB8F4[];

namespace pure3d {

class d3dPointSpriteShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dPointSpriteShader::vfunc_04()
{
    return DAT_007FB8F4;
}

}

// [TODO] 0x00705090 pure3d::d3dPointSpriteShader::vfunc_14 (54 B)
// [TODO] 0x007050F0 sub_007050F0 (102 B)
// [TODO] 0x00705160 pure3d::d3dPointSpriteShader::vfunc_03 (53 B)
// [TODO] 0x007051A0 pure3d::d3dPointSpriteShader::vfunc_15 (446 B)
// [TODO] 0x00705360 sub_00705360 (111 B)
// ============================================================================
// [VERIFIED] pure3d::d3dLayeredShader::vfunc_16 (0x007053D0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dLayeredShader::vfunc_16 (0x007053D0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FBC28[];

namespace pure3d {

class d3dLayeredShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_16();
};

void* d3dLayeredShader::vfunc_16()
{
    return DAT_007FBC28;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dLayeredShader::vfunc_17 (0x007053E0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dLayeredShader::vfunc_17 (0x007053E0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FBC70[];

namespace pure3d {

class d3dLayeredShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_17();
};

void* d3dLayeredShader::vfunc_17()
{
    return DAT_007FBC70;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dLayeredShader::vfunc_18 (0x007053F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dLayeredShader::vfunc_18 (0x007053F0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FBB50[];

namespace pure3d {

class d3dLayeredShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_18();
};

void* d3dLayeredShader::vfunc_18()
{
    return DAT_007FBB50;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dLayeredShader::vfunc_19 (0x00705400, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dLayeredShader::vfunc_19 (0x00705400, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FBBB0[];

namespace pure3d {

class d3dLayeredShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_19();
};

void* d3dLayeredShader::vfunc_19()
{
    return DAT_007FBBB0;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dLayeredShader::vfunc_04 (0x00705410, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dVehicleShader::vfunc_04 (0x002829C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00705410
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dLayeredShader::vfunc_04 (0x00705410, 6 bytes)
extern "C" char DAT_00769BD0[];

namespace pure3d {

class d3dLayeredShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dLayeredShader::vfunc_04()
{
    return DAT_00769BD0;
}

}

// [TODO] 0x00705420 pure3d::d3dLayeredShader::vfunc_24 (17 B)
// ============================================================================
// [VERIFIED] sub_00705430 (0x00705430, 1 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_006DEDF0 (PC 0x006DEDF0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00705430 (PC 0x00705430, 1 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

void __cdecl sub_00705430(void)
{
}

// [TODO] 0x007054B0 sub_007054B0 (109 B)
// [TODO] 0x00705520 sub_00705520 (1337 B)
// [TODO] 0x00705A60 pure3d::d3dLayeredShader::vfunc_13 (89 B)
// [TODO] 0x00705AC0 pure3d::d3dLayeredShader::vfunc_14 (66 B)
// [TODO] 0x00705B10 sub_00705B10 (155 B)
// [TODO] 0x00705BB0 pure3d::d3dLayeredShader::vfunc_03 (68 B)
// [TODO] 0x00705C00 pure3d::d3dLayeredShader::vfunc_15 (844 B)
// [TODO] 0x00705FA0 sub_00705FA0 (927 B)
// [TODO] 0x00706340 pure3d::d3dLayeredShader::vfunc_25 (743 B)
// [TODO] 0x00706680 pure3d::d3dSpecularShader::vfunc_24 (20 B)
// ============================================================================
// [VERIFIED] pure3d::d3dSpecularShader::vfunc_04 (0x007066A0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dVehicleShader::vfunc_04 (0x002829C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x007066A0
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dSpecularShader::vfunc_04 (0x007066A0, 6 bytes)
extern "C" char DAT_007FBFE8[];

namespace pure3d {

class d3dSpecularShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dSpecularShader::vfunc_04()
{
    return DAT_007FBFE8;
}

}

// [TODO] 0x007066B0 sub_007066B0 (1058 B)
// [TODO] 0x00706AE0 sub_00706AE0 (147 B)
// ============================================================================
// [VERIFIED] pure3d::d3dSpecularShader::vfunc_16 (0x00706B80, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dSpecularShader::vfunc_16 (0x00706B80, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FBFA0[];

namespace pure3d {

class d3dSpecularShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_16();
};

void* d3dSpecularShader::vfunc_16()
{
    return DAT_007FBFA0;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dSpecularShader::vfunc_17 (0x00706B90, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dSpecularShader::vfunc_17 (0x00706B90, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FBE98[];

namespace pure3d {

class d3dSpecularShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_17();
};

void* d3dSpecularShader::vfunc_17()
{
    return DAT_007FBE98;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dSpecularShader::vfunc_18 (0x00706BA0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dSpecularShader::vfunc_18 (0x00706BA0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FBE50[];

namespace pure3d {

class d3dSpecularShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_18();
};

void* d3dSpecularShader::vfunc_18()
{
    return DAT_007FBE50;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dSpecularShader::vfunc_19 (0x00706BB0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dSpecularShader::vfunc_19 (0x00706BB0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FBF40[];

namespace pure3d {

class d3dSpecularShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_19();
};

void* d3dSpecularShader::vfunc_19()
{
    return DAT_007FBF40;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dSpecularShader::vfunc_03 (0x00706BC0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dSpecularShader::vfunc_03 (0x00706BC0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0065B580(void);
extern "C" void __cdecl sub_0043CE70(int);

namespace pure3d {

class d3dSpecularShader
{
public:
    virtual d3dSpecularShader* vfunc_03(int a1);
};

d3dSpecularShader* d3dSpecularShader::vfunc_03(int a1)
{
    sub_0065B580();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x00706BE0 pure3d::d3dSpecularShader::vfunc_15 (683 B)
// [TODO] 0x00706D62 pure3d::BMPHandler::vfunc_17 (297 B)
// [TODO] 0x00706E90 sub_00706E90 (1067 B)
// [TODO] 0x007072C0 pure3d::d3dSpecularShader::vfunc_25 (77 B)
// ============================================================================
// [VERIFIED] pure3d::d3dCharacterShader::vfunc_16 (0x00707310, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dCharacterShader::vfunc_16 (0x00707310, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC198[];

namespace pure3d {

class d3dCharacterShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_16();
};

void* d3dCharacterShader::vfunc_16()
{
    return DAT_007FC198;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dCharacterShader::vfunc_17 (0x00707320, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dCharacterShader::vfunc_17 (0x00707320, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC0C0[];

namespace pure3d {

class d3dCharacterShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_17();
};

void* d3dCharacterShader::vfunc_17()
{
    return DAT_007FC0C0;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dCharacterShader::vfunc_18 (0x00707330, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dCharacterShader::vfunc_18 (0x00707330, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC078[];

namespace pure3d {

class d3dCharacterShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_18();
};

void* d3dCharacterShader::vfunc_18()
{
    return DAT_007FC078;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dCharacterShader::vfunc_19 (0x00707340, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dCharacterShader::vfunc_19 (0x00707340, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0085D760[];

namespace pure3d {

class d3dCharacterShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_19();
};

void* d3dCharacterShader::vfunc_19()
{
    return DAT_0085D760;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dCharacterShader::vfunc_04 (0x00707350, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dVehicleShader::vfunc_04 (0x002829C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00707350
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dCharacterShader::vfunc_04 (0x00707350, 6 bytes)
extern "C" char DAT_0073E280[];

namespace pure3d {

class d3dCharacterShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dCharacterShader::vfunc_04()
{
    return DAT_0073E280;
}

}

// [TODO] 0x00707360 pure3d::d3dShader::vfunc_22 (38 B)
// [TODO] 0x00707390 pure3d::d3dCharacterShader::vfunc_24 (17 B)
// ============================================================================
// [VERIFIED] sub_007073A0 (0x007073A0, 1 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_006DEDF0 (PC 0x006DEDF0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_007073A0 (PC 0x007073A0, 1 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

void __cdecl sub_007073A0(void)
{
}

// [TODO] 0x007073B0 sub_007073B0 (1319 B)
// [TODO] 0x007078E0 sub_007078E0 (77 B)
// [TODO] 0x00707930 pure3d::d3dCharacterShader::vfunc_03 (68 B)
// [TODO] 0x00707980 pure3d::d3dCharacterShader::vfunc_15 (417 B)
// [TODO] 0x00707B30 sub_00707B30 (593 B)
// ============================================================================
// [VERIFIED] sub_00707D80 (0x00707D80, 1 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_006DEDF0 (PC 0x006DEDF0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00707D80 (PC 0x00707D80, 1 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

void __cdecl sub_00707D80(void)
{
}

// [TODO] 0x00707D90 pure3d::d3dCharacterShader::vfunc_25 (58 B)
// [TODO] 0x00707DD0 sub_00707DD0 (50 B)
// [TODO] 0x00707E60 sub_00707E60 (57 B)
// ============================================================================
// [VERIFIED] pure3d::d3dVehicleShader::vfunc_04 (0x00707EA0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dVehicleShader::vfunc_04 (0x002829C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00707EA0
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dVehicleShader::vfunc_04 (0x00707EA0, 6 bytes)
extern "C" char DAT_007331B0[];

namespace pure3d {

class d3dVehicleShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dVehicleShader::vfunc_04()
{
    return DAT_007331B0;
}

}

// [TODO] 0x00707EB0 pure3d::d3dVehicleShader::vfunc_36 (35 B)
// [TODO] 0x00707EE0 pure3d::d3dVehicleShader::vfunc_37 (15 B)
// ============================================================================
// [VERIFIED] pure3d::d3dVehicleShader::vfunc_16 (0x00707EF0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dVehicleShader::vfunc_16 (0x00707EF0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC550[];

namespace pure3d {

class d3dVehicleShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_16();
};

void* d3dVehicleShader::vfunc_16()
{
    return DAT_007FC550;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dVehicleShader::vfunc_17 (0x00707F00, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dVehicleShader::vfunc_17 (0x00707F00, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC4C0[];

namespace pure3d {

class d3dVehicleShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_17();
};

void* d3dVehicleShader::vfunc_17()
{
    return DAT_007FC4C0;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dVehicleShader::vfunc_18 (0x00707F10, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dVehicleShader::vfunc_18 (0x00707F10, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC418[];

namespace pure3d {

class d3dVehicleShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_18();
};

void* d3dVehicleShader::vfunc_18()
{
    return DAT_007FC418;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dVehicleShader::vfunc_19 (0x00707F20, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dVehicleShader::vfunc_19 (0x00707F20, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC508[];

namespace pure3d {

class d3dVehicleShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_19();
};

void* d3dVehicleShader::vfunc_19()
{
    return DAT_007FC508;
}

}

// [TODO] 0x00707F30 pure3d::d3dVehicleShader::vfunc_26 (463 B)
// [TODO] 0x00708100 pure3d::d3dVehicleShader::vfunc_31 (13 B)
// [TODO] 0x00708110 pure3d::d3dVehicleShader::vfunc_30 (13 B)
// [TODO] 0x00708120 pure3d::d3dVehicleShader::vfunc_28 (13 B)
// [TODO] 0x00708130 pure3d::d3dVehicleShader::vfunc_32 (115 B)
// [TODO] 0x007081B0 pure3d::d3dVehicleShader::vfunc_33 (92 B)
// [TODO] 0x00708210 pure3d::d3dVehicleShader::vfunc_34 (92 B)
// [TODO] 0x00708270 sub_00708270 (104 B)
// [TODO] 0x007082E0 pure3d::d3dVehicleShader::vfunc_35 (104 B)
// [TODO] 0x00708350 sub_00708350 (1058 B)
// [TODO] 0x007087B0 sub_007087B0 (255 B)
// ============================================================================
// [VERIFIED] pure3d::d3dVehicleShader::vfunc_03 (0x007088B0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionManager::CollisionManagerFlowClient::vfunc_00 (0x00016060), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dVehicleShader::vfunc_03 (0x007088B0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00707E60(void);
extern "C" void __cdecl sub_0043CE70(int);

namespace pure3d {

class d3dVehicleShader
{
public:
    virtual d3dVehicleShader* vfunc_03(int a1);
};

d3dVehicleShader* d3dVehicleShader::vfunc_03(int a1)
{
    sub_00707E60();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// [TODO] 0x007088D0 pure3d::d3dVehicleShader::vfunc_15 (292 B)
// [TODO] 0x00708A00 pure3d::d3dVehicleShader::vfunc_25 (1058 B)
// ============================================================================
// [VERIFIED] pure3d::d3dShadowShader::vfunc_16 (0x00708F50, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dShadowShader::vfunc_16 (0x00708F50, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC7E0[];

namespace pure3d {

class d3dShadowShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_16();
};

void* d3dShadowShader::vfunc_16()
{
    return DAT_007FC7E0;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dShadowShader::vfunc_17 (0x00708F60, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dShadowShader::vfunc_17 (0x00708F60, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC690[];

namespace pure3d {

class d3dShadowShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_17();
};

void* d3dShadowShader::vfunc_17()
{
    return DAT_007FC690;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dShadowShader::vfunc_18 (0x00708F70, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dShadowShader::vfunc_18 (0x00708F70, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC648[];

namespace pure3d {

class d3dShadowShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_18();
};

void* d3dShadowShader::vfunc_18()
{
    return DAT_007FC648;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dShadowShader::vfunc_19 (0x00708F80, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dShadowShader::vfunc_19 (0x00708F80, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC768[];

namespace pure3d {

class d3dShadowShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_19();
};

void* d3dShadowShader::vfunc_19()
{
    return DAT_007FC768;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dShadowShader::vfunc_04 (0x00708F90, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dVehicleShader::vfunc_04 (0x002829C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00708F90
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dShadowShader::vfunc_04 (0x00708F90, 6 bytes)
extern "C" char DAT_0072F5B0[];

namespace pure3d {

class d3dShadowShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dShadowShader::vfunc_04()
{
    return DAT_0072F5B0;
}

}

// [TODO] 0x00708FA0 pure3d::d3dShadowShader::vfunc_15 (136 B)
// [TODO] 0x00709030 sub_00709030 (44 B)
// [TODO] 0x00709060 pure3d::d3dShadowShader::vfunc_03 (53 B)
// ============================================================================
// [VERIFIED] pure3d::d3dShadowDecalShader::vfunc_16 (0x007090A0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dShadowDecalShader::vfunc_16 (0x007090A0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC968[];

namespace pure3d {

class d3dShadowDecalShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_16();
};

void* d3dShadowDecalShader::vfunc_16()
{
    return DAT_007FC968;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dShadowDecalShader::vfunc_17 (0x007090B0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dShadowDecalShader::vfunc_17 (0x007090B0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC890[];

namespace pure3d {

class d3dShadowDecalShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_17();
};

void* d3dShadowDecalShader::vfunc_17()
{
    return DAT_007FC890;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dShadowDecalShader::vfunc_18 (0x007090C0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dShadowDecalShader::vfunc_18 (0x007090C0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FC848[];

namespace pure3d {

class d3dShadowDecalShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_18();
};

void* d3dShadowDecalShader::vfunc_18()
{
    return DAT_007FC848;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dShadowDecalShader::vfunc_19 (0x007090D0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dShadowDecalShader::vfunc_19 (0x007090D0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0085D788[];

namespace pure3d {

class d3dShadowDecalShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_19();
};

void* d3dShadowDecalShader::vfunc_19()
{
    return DAT_0085D788;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dShadowDecalShader::vfunc_04 (0x007090E0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dVehicleShader::vfunc_04 (0x002829C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x007090E0
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dShadowDecalShader::vfunc_04 (0x007090E0, 6 bytes)
extern "C" char DAT_00769C04[];

namespace pure3d {

class d3dShadowDecalShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dShadowDecalShader::vfunc_04()
{
    return DAT_00769C04;
}

}

// [TODO] 0x007090F0 pure3d::d3dShadowDecalShader::vfunc_14 (23 B)
// [TODO] 0x00709110 sub_00709110 (83 B)
// [TODO] 0x00709170 pure3d::d3dShadowDecalShader::vfunc_03 (53 B)
// [TODO] 0x007091B0 pure3d::d3dShadowDecalShader::vfunc_15 (408 B)
// [TODO] 0x00709350 sub_00709350 (25 B)
// ============================================================================
// [VERIFIED] pure3d::d3dDecalShader::vfunc_04 (0x00709370, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dVehicleShader::vfunc_04 (0x002829C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00709370
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dDecalShader::vfunc_04 (0x00709370, 6 bytes)
extern "C" char DAT_00769C24[];

namespace pure3d {

class d3dDecalShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dDecalShader::vfunc_04()
{
    return DAT_00769C24;
}

}

// [TODO] 0x00709380 pure3d::d3dDecalShader::vfunc_15 (171 B)
// ============================================================================
// [VERIFIED] pure3d::d3dDecalShader::vfunc_14 (0x00709430, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as renderer::InstanceRenderable::vfunc_10 (0x00054F90), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dDecalShader::vfunc_14 (0x00709430, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0065BC10(void);

namespace pure3d {

class d3dDecalShader
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
    virtual void vfunc_14();
};

void d3dDecalShader::vfunc_14()
{
    sub_0065BC10();
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dDecalShader::vfunc_03 (0x00709440, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as LOSManager::LOSManagerFlowClient::vfunc_00 (0x000179C0), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dDecalShader::vfunc_03 (0x00709440, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00774EA4[];
extern "C" void __cdecl sub_0043CE70(int);
extern "C" void __cdecl sub_0065B580(void);

namespace pure3d {

class d3dDecalShader
{
public:
    virtual d3dDecalShader* vfunc_03(int a1);
};

d3dDecalShader* d3dDecalShader::vfunc_03(int a1)
{
    *(int*)this = (int)DAT_00774EA4;
    sub_0065B580();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dVertexFadeShader::vfunc_04 (0x00709470, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::d3dVehicleShader::vfunc_04 (0x002829C0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00709470
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dVertexFadeShader::vfunc_04 (0x00709470, 6 bytes)
extern "C" char DAT_007FC9FC[];

namespace pure3d {

class d3dVertexFadeShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dVertexFadeShader::vfunc_04()
{
    return DAT_007FC9FC;
}

}

// [TODO] 0x00709480 pure3d::ParticleEmitter::vfunc_33 (44 B)
// [TODO] 0x007094B0 pure3d::d3dVertexFadeShader::vfunc_24 (20 B)
// [TODO] 0x007094D0 sub_007094D0 (1239 B)
// [TODO] 0x007099B0 sub_007099B0 (63 B)
// ============================================================================
// [VERIFIED] pure3d::d3dVertexFadeShader::vfunc_16 (0x007099F0, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dVertexFadeShader::vfunc_16 (0x007099F0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FCAF8[];

namespace pure3d {

class d3dVertexFadeShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_16();
};

void* d3dVertexFadeShader::vfunc_16()
{
    return DAT_007FCAF8;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dVertexFadeShader::vfunc_17 (0x00709A00, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dVertexFadeShader::vfunc_17 (0x00709A00, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FCA50[];

namespace pure3d {

class d3dVertexFadeShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_17();
};

void* d3dVertexFadeShader::vfunc_17()
{
    return DAT_007FCA50;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dVertexFadeShader::vfunc_18 (0x00709A10, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dVertexFadeShader::vfunc_18 (0x00709A10, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FCB70[];

namespace pure3d {

class d3dVertexFadeShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_18();
};

void* d3dVertexFadeShader::vfunc_18()
{
    return DAT_007FCB70;
}

}

// ============================================================================
// [VERIFIED] pure3d::d3dVertexFadeShader::vfunc_19 (0x00709A20, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as pure3d::TargaHandler::vfunc_07 (0x0004A760), which was matched first;
// its addresses and names were swapped for this function's.
// pure3d::d3dVertexFadeShader::vfunc_19 (0x00709A20, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_007FCB28[];

namespace pure3d {

class d3dVertexFadeShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_19();
};

void* d3dVertexFadeShader::vfunc_19()
{
    return DAT_007FCB28;
}

}

// [TODO] 0x00709A30 pure3d::d3dVertexFadeShader::vfunc_15 (629 B)
// [TODO] 0x00709CB0 sub_00709CB0 (740 B)
// [TODO] 0x00709FA0 pure3d::d3dVertexFadeShader::vfunc_25 (66 B)
// ============================================================================
// [VERIFIED] sub_00709FE2 (0x00709FE2, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_00012130 (0x00012130), which was matched first;
// its addresses and names were swapped for this function's.
// sub_00709FE2 (0x00709FE2, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F308;

class Class_00709FE2
{
public:
    void sub_00709FE2();
};

void Class_00709FE2::sub_00709FE2()
{
    ((void (__cdecl*)(void))DAT_0072F308)();
}

// ============================================================================
// [VERIFIED] sub_0072C940 (0x0072C940, 1 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_006DEDF0 (PC 0x006DEDF0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0072C940 (PC 0x0072C940, 1 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

void __cdecl sub_0072C940(void)
{
}

// ============================================================================
// [VERIFIED] sub_0072CC00 (0x0072CC00, 1 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_006DEDF0 (PC 0x006DEDF0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0072CC00 (PC 0x0072CC00, 1 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

void __cdecl sub_0072CC00(void)
{
}

// ============================================================================
// [VERIFIED] sub_0072CC10 (0x0072CC10, 1 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_006DEDF0 (PC 0x006DEDF0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0072CC10 (PC 0x0072CC10, 1 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

void __cdecl sub_0072CC10(void)
{
}

// ============================================================================
// [VERIFIED] sub_0072CD30 (0x0072CD30, 1 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as sub_006DEDF0 (PC 0x006DEDF0), which was matched first;
// its addresses and names were swapped for this function's.
// sub_0072CD30 (PC 0x0072CD30, 1 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

void __cdecl sub_0072CD30(void)
{
}

