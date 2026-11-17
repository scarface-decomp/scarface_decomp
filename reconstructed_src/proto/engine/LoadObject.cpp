// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/LoadObject.cpp (3 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 3 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] LoadObject::vfunc_00 (0x00190330, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// LoadObject::vfunc_00 (0x00190330, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0041229C[];

class LoadObject
{
public:
    virtual void* vfunc_00();
};

void* LoadObject::vfunc_00()
{
    return DAT_0041229C;
}

// ============================================================================
// [VERIFIED] LoadObject::vfunc_05 (0x00190340, 38 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// LoadObject::vfunc_05 (Proto 0x00190340, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00028C40(int);
extern "C" int __cdecl sub_00028CF0(int, int);

class LoadObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05(int a1);
    char m_pad04[0x1C];
    int m_Field20; // +0x20
    int m_Field24; // +0x24
};

int LoadObject::vfunc_05(int a1)
{
    int r_eax;

    r_eax = a1;
    sub_00028C40(a1);
    r_eax = m_Field20;
    if (r_eax) {
        r_eax = sub_00028CF0(r_eax, 0);
        m_Field24 = r_eax;
    }
    return r_eax;
}

// ============================================================================
// [VERIFIED] LoadObject::vfunc_01 (0x00190370, 36 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_01 (0x00013840), which was matched first;
// its addresses and names were swapped for this function's.
// LoadObject::vfunc_01 (0x00190370, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039DC74[];
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_00029C00(void);

class LoadObject
{
public:
    virtual void vfunc_00();
    virtual LoadObject* vfunc_01(int a1);
};

LoadObject* LoadObject::vfunc_01(int a1)
{
    *(int*)this = (int)DAT_0039DC74;
    sub_00029C00();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

