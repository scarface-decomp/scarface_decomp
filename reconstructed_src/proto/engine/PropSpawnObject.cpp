// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/PropSpawnObject.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 3 of 4 functions matched (75.00%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Proto.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
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

