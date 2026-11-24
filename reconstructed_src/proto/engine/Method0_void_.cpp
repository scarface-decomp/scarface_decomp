// ============================================================================
// SCARFACE: THE WORLD IS YOURS — April 2006 prototype game.xbe, engine/Method0_void_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CScript::Method0<void>::vfunc_00 (0x0002A7D0, 12 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// ============================================================================
// Same machine code as CScript::Method0<void>::vfunc_00 (0x0002D2D0), which was matched first;
// its addresses and names were swapped for this function's.
// bin: xb
// va: 0x0002A7D0
// what: Invokes the zero-argument void member-function pointer at +0x0C on the given script object.
// tool: Gemini 4 Neon

class ScriptObject {};

namespace CScript {

template<class R>
class Method0;

template<>
class Method0<void>
{
public:
    virtual void vfunc_00(ScriptObject* obj, void* unused);
    char m_pad04[0x8];
    void (ScriptObject::*m_Method)(); // +0x0C
};

void Method0<void>::vfunc_00(ScriptObject* obj, void*)
{
    (obj->*m_Method)();
}

}

