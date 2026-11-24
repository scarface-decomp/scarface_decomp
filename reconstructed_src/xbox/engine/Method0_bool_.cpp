// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, engine/Method0_bool_.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] CScript::Method0<bool>::vfunc_00 (0x00179150, 18 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4
// What it does: Invokes the zero-argument bool member-function pointer at +0x0C on the script object and stores the result.
// ============================================================================
// bin: xb
// va: 0x00179150
// what: Invokes the zero-argument bool member-function pointer at +0x0C on the script object and stores the result.
// tool: Gemini 4 Neon

class ScriptObject {};

namespace CScript {

template<class R>
class Method0
{
public:
    virtual void vfunc_00(ScriptObject* obj, R* out);
    char m_pad04[0x8];
    R (ScriptObject::*m_Method)(); // +0x0C
};

template<class R>
void Method0<R>::vfunc_00(ScriptObject* obj, R* out)
{
    typedef R (ScriptObject::*Fn)();
    Fn fn = m_Method;
    *out = (obj->*fn)();
}

template class Method0<bool>;

}

