// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/DealerSpawnObject.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 4 of 9 functions matched (44.44%). NOT COMPLETE YET.
// The 5 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] DealerSpawnObject::vfunc_39 (0x001DE930, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CallForVehicleSpawnObject::vfunc_39 (0x001D8FB0), which was matched first;
// its addresses and names were swapped for this function's.
// DealerSpawnObject::vfunc_39 (0x001DE930, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003A4904;

class DealerSpawnObject
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
    virtual float vfunc_39(int a1, int a2);
};

float DealerSpawnObject::vfunc_39(int a1, int a2)
{
    return DAT_003A4904;
}

// ============================================================================
// [VERIFIED] DealerSpawnObject::vfunc_40 (0x001DE940, 64 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// DealerSpawnObject::vfunc_40 (0x001DE940, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class DealerSpawnObject
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
    virtual int vfunc_40(int a1, int a2);
    char m_pad04[0x94];
    int m_Field98; // +0x98
    int m_Field9C; // +0x9C
};

int DealerSpawnObject::vfunc_40(int a1, int a2)
{
    int r_eax, r_edx;

    r_eax = m_Field98;
    r_eax -= 1;
    m_Field98 = r_eax;
    r_eax = 0;
    r_edx = (int)(&m_Field9C);
L_20:
    if (*(int*)r_edx != a1) {
        r_eax += 1;
        r_edx += 4;
        if (r_eax < 3) goto L_20;
        return r_eax;
    }
    *(int*)((int)this + (r_eax * 4) + 156) = 0;
    return r_eax;
}

// ============================================================================
// [VERIFIED] DealerSpawnObject::vfunc_00 (0x001DEA80, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// DealerSpawnObject::vfunc_00 (0x001DEA80, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043DB7C[];

class DealerSpawnObject
{
public:
    virtual void* vfunc_00();
};

void* DealerSpawnObject::vfunc_00()
{
    return DAT_0043DB7C;
}

// ============================================================================
// [VERIFIED] DealerSpawnObject::vfunc_01 (0x001DEC90, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GameGroup::vfunc_01 (0x000290E0), which was matched first;
// its addresses and names were swapped for this function's.
// DealerSpawnObject::vfunc_01 (0x001DEC90, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C784C[];
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_001DE8E0(void);

class DealerSpawnObject
{
public:
    virtual void vfunc_00();
    virtual DealerSpawnObject* vfunc_01(int a1);
    void sub_001EA010();
};

DealerSpawnObject* DealerSpawnObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003C784C;
    sub_001DE8E0();
    sub_001EA010();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

