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
