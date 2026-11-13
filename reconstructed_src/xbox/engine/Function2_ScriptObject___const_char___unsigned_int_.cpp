// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Function2_ScriptObject___const_char___unsigned_int_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CScript::Function2<ScriptObject*, const char*, unsigned int>::vfunc_00 (0x0002E140, 35 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// CScript::Function2<ScriptObject*, const char*, unsigned int>::vfunc_00 (0x0002E140, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00025300(void);
extern "C" int __cdecl sub_0002E170(void);

namespace CScript {

class Function2_ScriptObject___const_char___unsigned_int_
{
public:
    virtual void vfunc_00(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

void Function2_ScriptObject___const_char___unsigned_int_::vfunc_00(int a1, int a2)
{
    int t1, t2;

    t1 = m_Field0C;
    t2 = sub_00025300();
    *(int*)a2 = ((int (__cdecl*)(int, int))t1)(t2, sub_0002E170());
}

}

