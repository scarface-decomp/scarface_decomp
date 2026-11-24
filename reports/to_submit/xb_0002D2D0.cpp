// bin: xb
// va: 0x0002D2D0
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
