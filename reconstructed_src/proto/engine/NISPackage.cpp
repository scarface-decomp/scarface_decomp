// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/NISPackage.cpp (4 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 4 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] NISPackage::vfunc_00 (0x000BD300, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// NISPackage::vfunc_00 (Proto 0x000BD300, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class NISPackage
{
public:
    virtual void vfunc_00();
    char m_pad04[0xAC];
    int m_FieldB0; // +0xB0
};

void NISPackage::vfunc_00()
{
    m_FieldB0 += 1;
}

// ============================================================================
// [VERIFIED] NISPackage::vfunc_01 (0x000BD310, 27 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Drops one use of an NIS package; on the last one it calls the object's own release with 1.
// ============================================================================
// bin: proto
// va: 0x000BD310
// what: Drops one use of an NIS package; on the last one it calls the object's own release with 1.
// tool: Claude Opus 5.5 (transplanted from xb:0x000CD8D0, nearest by portal/tools/similar.py)
// NISPackage::vfunc_01 (0x000BD310, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class NISPackage
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void NISPackage::vfunc_01()
{
    int r_eax, r_ecx;

    r_ecx = (int)this;
    r_eax = *(int*)(r_ecx + 176);
    if (r_eax < 2) {
        r_eax = *(int*)r_ecx;
        r_eax = ((int (__stdcall*)(int))*(int*)(r_eax + 12))(1);
        return;
    }
    r_eax -= 1;
    *(int*)(r_ecx + 176) = r_eax;
}

// ============================================================================
// [VERIFIED] NISPackage::vfunc_03 (0x000BD960, 30 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as Collidable::vfunc_03 (0x00011F20), which was matched first;
// its addresses and names were swapped for this function's.
// NISPackage::vfunc_03 (0x000BD960, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000BD7C0(void);
extern "C" void __cdecl sub_00025160(int);

class NISPackage
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual NISPackage* vfunc_03(int a1);
};

NISPackage* NISPackage::vfunc_03(int a1)
{
    sub_000BD7C0();
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}

// ============================================================================
// [VERIFIED] NISPackage::vfunc_02 (0x0019C190, 7 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// NISPackage::vfunc_02 (Proto 0x0019C190, 7 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class NISPackage
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    char m_pad04[0xAC];
    int m_FieldB0; // +0xB0
};

int NISPackage::vfunc_02()
{
    return m_FieldB0;
}

