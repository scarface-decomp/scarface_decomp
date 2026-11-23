// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/DealerSpawnObject.cpp (6 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 6 of 8 functions matched (75.00%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] DealerSpawnObject::vfunc_00 (0x001A6920, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// DealerSpawnObject::vfunc_00 (0x001A6920, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00417448[];

class DealerSpawnObject
{
public:
    virtual void* vfunc_00();
};

void* DealerSpawnObject::vfunc_00()
{
    return DAT_00417448;
}

// ============================================================================
// [VERIFIED] DealerSpawnObject::vfunc_35 (0x001A6930, 68 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001A6930
// what: 
// tool: the portal's starter code (no AI)

// DealerSpawnObject::vfunc_35 (Proto 0x001A6930, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001A6530(int);
};

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
    virtual int vfunc_35();
    char m_pad04[0x7C];
    int m_Field80; // +0x80
    char m_pad84[0xC];
    int m_Field90; // +0x90
    char m_pad94[0x4];
    int m_Field98; // +0x98
};

int DealerSpawnObject::vfunc_35()
{
    int r_eax, r_ebp, r_ebx, r_edi;

    r_eax = m_Field98;
    if (r_eax > 0) {
        r_edi = (int)(&m_Field90);
        r_ebx = (int)(&m_Field80);
        r_ebp = 4;
        do {
            if (*(unsigned char*)r_edi) {
                r_eax = ((Object*)*(int*)r_ebx)->sub_001A6530(8);
                *(bool*)r_edi = false;
                m_Field98 -= 1;
            }
            r_ebx += 4;
            r_edi += 1;
            r_ebp -= 1;
        } while (r_ebp);
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] DealerSpawnObject::vfunc_37 (0x001A6980, 9 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CallForVehicleSpawnObject::vfunc_39 (0x001D8FB0), which was matched first;
// its addresses and names were swapped for this function's.
// DealerSpawnObject::vfunc_37 (0x001A6980, 9 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_00383E60;

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
    virtual float vfunc_37(int a1, int a2);
};

float DealerSpawnObject::vfunc_37(int a1, int a2)
{
    return DAT_00383E60;
}

// ============================================================================
// [VERIFIED] DealerSpawnObject::vfunc_38 (0x001A6990, 64 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// DealerSpawnObject::vfunc_38 (Proto 0x001A6990, 64 bytes)
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
    virtual int vfunc_38(int a1, int a2);
    char m_pad04[0x98];
    int m_Field9C; // +0x9C
    int m_FieldA0; // +0xA0
};

int DealerSpawnObject::vfunc_38(int a1, int a2)
{
    int r_eax, r_edx;

    r_eax = m_Field9C;
    r_eax -= 1;
    m_Field9C = r_eax;
    r_eax = 0;
    r_edx = (int)(&m_FieldA0);
L_20:
    if (*(int*)r_edx != a1) {
        r_eax += 1;
        r_edx += 4;
        if (r_eax < 3) goto L_20;
        return r_eax;
    }
    *(int*)((int)this + (r_eax * 4) + 160) = 0;
    return r_eax;
}

// ============================================================================
// [VERIFIED] DealerSpawnObject::vfunc_01 (0x001A6BA0, 43 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as GameGroup::vfunc_01 (0x000290E0), which was matched first;
// its addresses and names were swapped for this function's.
// DealerSpawnObject::vfunc_01 (0x001A6BA0, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A19F4[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_001A6930(void);

class DealerSpawnObject
{
public:
    virtual void vfunc_00();
    virtual DealerSpawnObject* vfunc_01(int a1);
    void sub_001B0CB0();
};

DealerSpawnObject* DealerSpawnObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_003A19F4;
    sub_001A6930();
    sub_001B0CB0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] DealerSpawnObject::vfunc_43 (0x0021E9A0, 6 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// DealerSpawnObject::vfunc_43 (Proto 0x0021E9A0, 6 bytes)
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
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual int vfunc_43();
};

int DealerSpawnObject::vfunc_43()
{
    return 8;
}

