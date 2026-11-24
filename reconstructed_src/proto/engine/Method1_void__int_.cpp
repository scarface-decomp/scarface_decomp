// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/Method1_void__int_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CScript::Method1<void, int>::vfunc_00 (0x00100D90, 20 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CScript::Method1<void, int>::vfunc_00 (0x0011BB60), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x00100D90
// what: Reads an integer argument via sub_0002ABC0 and invokes the void(int) member-function pointer at +0x0C.
// tool: Gemini 4 Neon

class ScriptObject {};

extern "C" int __cdecl sub_0002ABC0();

namespace CScript {

template<class R, class A1>
class Method1;

template<class A1>
class Method1<void, A1>
{
public:
    virtual void vfunc_00(ScriptObject* obj, void* unused);
    char m_pad04[0x8];
    void (ScriptObject::*m_Method)(A1); // +0x0C
};

template<class A1>
void Method1<void, A1>::vfunc_00(ScriptObject* obj, void*)
{
    typedef void (ScriptObject::*Fn)(A1);
    Fn fn = m_Method;
    (obj->*fn)(sub_0002ABC0());
}

template class Method1<void, int>;

}

