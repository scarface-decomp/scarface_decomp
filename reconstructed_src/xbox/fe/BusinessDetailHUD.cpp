// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, fe/BusinessDetailHUD.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 10 functions matched (40.00%). NOT COMPLETE YET.
// The 6 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] BusinessDetailHUD::vfunc_00 (0x00190890, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns BusinessDetailHUD's static class record (ConcreteClassRep<BusinessDetailHUD>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// BusinessDetailHUD::vfunc_00 (0x00190890, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00436398[];

class BusinessDetailHUD
{
public:
    virtual void* vfunc_00();
};

void* BusinessDetailHUD::vfunc_00()
{
    return DAT_00436398;
}

// ============================================================================
// [VERIFIED] BusinessDetailHUD::vfunc_32 (0x001908A0, 72 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: xb
// va: 0x001908A0
// what: 
// tool: the portal's starter code (no AI)

// BusinessDetailHUD::vfunc_32 (0x001908A0, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001C4500(int);
};

extern "C" int DAT_0048E54C;
extern "C" void __stdcall sub_00193200(int);

class BusinessDetailHUD
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
    virtual void vfunc_32(int a1);
    void sub_001AF5C0();
    char m_pad04[0x5C];
    unsigned char m_Field60; // +0x60
    char m_pad61[0x9];
    bool m_Field6A; // +0x6A
};

void BusinessDetailHUD::vfunc_32(int a1)
{
    int r_eax;

    if (m_Field60 & 1) {
        r_eax = a1;
        sub_00193200(a1);
        r_eax = m_Field6A;
        if (!((unsigned char)r_eax)) goto L_44;
        r_eax = ((Object*)DAT_0048E54C)->sub_001C4500(0);
        if (r_eax == 2) {
            sub_001AF5C0();
            m_Field6A = false;
            return;
        }
        if (r_eax != 4) goto L_44;
        m_Field6A = false;
    }
L_44:
    ;
}

// ============================================================================
// [VERIFIED] BusinessDetailHUD::vfunc_01 (0x00192AB0, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: BusinessDetailHUD's deleting destructor: destroys the object, frees its memory when asked (flag bit 0), and returns it.
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// BusinessDetailHUD::vfunc_01 (0x00192AB0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00193F80(void);
extern "C" void __cdecl sub_00027600(int);

class BusinessDetailHUD
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual BusinessDetailHUD* vfunc_01(int a1);
};

BusinessDetailHUD* BusinessDetailHUD::vfunc_01(int a1)
{
    sub_00193F80();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] BusinessDetailHUD::vfunc_29 (0x00193FD0, 5 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as SoundEntityLoader::vfunc_04 (0x00064FA0), which was matched first;
// its addresses and names were swapped for this function's.
// BusinessDetailHUD::vfunc_29 (0x00193FD0, 5 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00193150(void);

class BusinessDetailHUD
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_29();
};

void BusinessDetailHUD::vfunc_29()
{
    sub_00193150();
}

