// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/PropSpawnObject.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] PropSpawnObject::vfunc_00 (0x001AB000, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// PropSpawnObject::vfunc_00 (0x001AB000, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00415990[];

class PropSpawnObject
{
public:
    virtual void* vfunc_00();
};

void* PropSpawnObject::vfunc_00()
{
    return DAT_00415990;
}

// ============================================================================
// [VERIFIED] PropSpawnObject::vfunc_39 (0x001AB1A0, 100 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// bin: proto
// va: 0x001AB1A0
// what: 
// tool: the portal's starter code (no AI)

// PropSpawnObject::vfunc_39 (Proto 0x001AB1A0, 100 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field8C
{
    int sub_001AAA20();
};

extern "C" void __cdecl sub_001AAE30(int);

class PropSpawnObject
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
    virtual void vfunc_39(int a1, int a2);
    char m_pad04[0x84];
    int m_Field88; // +0x88
    Field8C* m_Field8C; // +0x8C
    char m_pad90[0x8];
    int m_Field98; // +0x98
    char m_pad9C[0x8];
    int m_FieldA4; // +0xA4
    char m_padA8[0x1];
    unsigned char m_FieldA9; // +0xA9
};

void PropSpawnObject::vfunc_39(int a1, int a2)
{
    int t2, t4, t5;
    unsigned char t3;

    sub_001AAE30(a1);
    t2 = m_Field88;
    if (m_FieldA4 > m_Field88) {
        if (t2 > -1) goto L_60;
    }
    t3 = m_FieldA9;
    if (!(m_FieldA9 & 1)) {
        m_FieldA9 = (unsigned char)(t3 | 2);
        return;
    }
    m_Field98 = (int)m_Field8C;
    t4 = m_Field8C->sub_001AAA20();
    t5 = *(int*)(t4 + 4);
    if ((unsigned int)*(int*)(t4 + 4) < (unsigned int)*(int*)(t4 + 8)) {
        *(int*)(t4 + 4) = t5 + 4;
        if (!t5) goto L_60;
        *(int*)t5 = (int)this;
    }
L_60:
    ;
}

// ============================================================================
// [VERIFIED] PropSpawnObject::vfunc_01 (0x001AB550, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// PropSpawnObject::vfunc_01 (0x001AB550, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001AB010(void);
extern "C" void __cdecl sub_00025160(int);

class PropSpawnObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual PropSpawnObject* vfunc_01(int a1);
};

PropSpawnObject* PropSpawnObject::vfunc_01(int a1)
{
    sub_001AB010();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] PropSpawnObject::vfunc_05 (0x001AB570, 154 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// PropSpawnObject::vfunc_05 (Proto 0x001AB570, 154 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001AB2D0();
};

extern "C" int DAT_00460AF8;
extern "C" void __cdecl sub_00025160(int);
extern "C" int __cdecl sub_001AAAA0(void);
extern "C" int __stdcall sub_001B0CD0(int);

class PropSpawnObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0x90];
    int m_FieldA0; // +0xA0
    int m_FieldA4; // +0xA4
};

int PropSpawnObject::vfunc_05(int a1)
{
    int r_eax, r_ebx, r_ecx, r_esi;

    r_ecx = (int)this;
    r_ebx = a1;
    r_eax = sub_001B0CD0(a1);
    if (!((unsigned char)a1)) goto L_91;
    r_eax = DAT_00460AF8;
    m_FieldA0 = r_eax;
    r_eax = sub_001AAAA0();
    r_esi = m_Field0C;
    r_ebx = r_eax;
    r_eax = sub_001AAAA0();
    r_ecx = *(int*)r_eax;
    r_eax = *(int*)(r_eax + 4);
    if (r_ecx != r_eax) {
        do {
            if (*(int*)*(int*)r_ecx == r_esi) goto L_96;
            r_ecx += 4;
        } while (r_ecx != r_eax);
    }
    r_esi = r_eax;
L_45:
    if (r_esi != *(int*)(r_ebx + 4)) {
        r_eax = *(int*)r_esi;
        r_ecx = *(int*)(r_eax + 4);
        m_FieldA4 = r_ecx;
        sub_00025160(*(int*)r_esi);
        r_ecx = *(int*)(r_ebx + 4);
        r_eax = r_esi + 4;
        if (r_eax != r_ecx) {
            r_esi -= r_eax;
            do {
                *(int*)(r_esi + r_eax) = *(int*)r_eax;
                r_eax += 4;
            } while (r_eax != r_ecx);
        }
        *(int*)(r_ebx + 4) += -4;
    }
    r_eax = DAT_00460AF8;
    if (!r_eax) {
        r_ecx = (int)this;
        r_eax = ((Object*)r_ecx)->sub_001AB2D0();
    }
L_91:
    return r_eax;
L_96:
    r_esi = r_ecx;
    goto L_45;
}

