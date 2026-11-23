// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/EffectsTemplate.cpp (2 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 2 of 3 functions matched (66.67%). NOT COMPLETE YET.
// The 1 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] EffectsTemplate::vfunc_00 (0x001FB720, 6 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Returns EffectsTemplate's static class record (ConcreteClassRep<EffectsTemplate>), the object's run-time type.
// ============================================================================
// Same machine code as CollisionBehaviourTypeGroup::vfunc_00 (0x000123B0), which was matched first;
// its addresses and names were swapped for this function's.
// EffectsTemplate::vfunc_00 (0x001FB720, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043FCE8[];

class EffectsTemplate
{
public:
    virtual void* vfunc_00();
};

void* EffectsTemplate::vfunc_00()
{
    return DAT_0043FCE8;
}

// ============================================================================
// [VERIFIED] EffectsTemplate::vfunc_11 (0x001FB950, 279 B)
// By: NoahBPeterson | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as EffectsTemplate::vfunc_12 (Proto 0x001C0460), which was matched first;
// its addresses and names were swapped for this function's.
// EffectsTemplate::vfunc_11 (Proto 0x001FB950, 279 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00048680(int);
extern "C" void __cdecl sub_00049A50(int, int);

class EffectsTemplate
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
    virtual int vfunc_11();
};

int EffectsTemplate::vfunc_11()
{
    int r_eax, r_esi;

    r_esi = (int)this;
    r_eax = *(int*)(r_esi + 96);
    *(bool*)(r_esi + 34) = false;
    if (r_eax) {
        sub_00048680(r_esi + 96);
        *(int*)(r_esi + 96) = 0;
    }
    r_eax = *(int*)(r_esi + 100);
    if (r_eax) {
        sub_00048680(r_esi + 100);
        *(int*)(r_esi + 100) = 0;
    }
    r_eax = *(int*)(r_esi + 104);
    if (r_eax) {
        sub_00048680(r_esi + 104);
        *(int*)(r_esi + 104) = 0;
    }
    r_eax = *(int*)(r_esi + 108);
    if (r_eax) {
        sub_00048680(r_esi + 108);
        *(int*)(r_esi + 108) = 0;
    }
    r_eax = *(int*)(r_esi + 112);
    if (r_eax) {
        sub_00048680(r_esi + 112);
        *(int*)(r_esi + 112) = 0;
    }
    r_eax = *(int*)(r_esi + 76);
    if (r_eax) {
        sub_00049A50(0, r_eax);
    }
    r_eax = *(int*)(r_esi + 80);
    if (r_eax) {
        sub_00049A50(1, r_eax);
    }
    r_eax = *(int*)(r_esi + 84);
    if (r_eax) {
        sub_00049A50(2, r_eax);
    }
    r_eax = *(int*)(r_esi + 88);
    if (r_eax) {
        sub_00049A50(3, r_eax);
    }
    r_eax = *(int*)(r_esi + 92);
    if (r_eax) {
        sub_00049A50(4, r_eax);
    }
    r_eax = *(int*)(r_esi + 64);
    if (r_eax) {
        sub_00048680(r_esi + 124);
        *(int*)(r_esi + 124) = 0;
    }
    r_eax = *(int*)(r_esi + 72);
    if (r_eax) {
        r_esi += 132;
        r_eax = sub_00048680(r_esi);
        *(int*)r_esi = 0;
    }
    return r_eax;
}

