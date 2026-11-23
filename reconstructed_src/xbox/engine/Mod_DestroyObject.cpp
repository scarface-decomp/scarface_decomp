// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Mod_DestroyObject.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: 1 of 3 functions matched (33.33%). NOT COMPLETE YET.
// The 2 still to do are listed in their place in Original_Binary_Order_Xbox.cpp as "// [TODO] address name (size)"
// lines, so you can see what is missing and where; matched ones are the C++ itself.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] AICommandMods::Mod_DestroyObject::vfunc_01 (0x00135010, 44 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as AICommandMods::Mod_DestroyObject::vfunc_01 (Proto 0x00119E10), which was matched first;
// its addresses and names were swapped for this function's.
// bin: proto
// va: 0x00135010
// what: 
// tool: the portal's starter code (no AI)

// AICommandMods::Mod_DestroyObject::vfunc_01 (Proto 0x00135010, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000F2AF0();
    int sub_001655C0();
};

namespace AICommandMods {

class Mod_DestroyObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1, int a2);
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

void Mod_DestroyObject::vfunc_01(int a1, int a2)
{
    int t2;

    t2 = ((Object*)((Object*)a2)->sub_001655C0())->sub_000F2AF0();
    if (t2) {
        m_Field10 = *(int*)(t2 + 16);
        return;
    }
    m_Field10 = 0;
}

}

