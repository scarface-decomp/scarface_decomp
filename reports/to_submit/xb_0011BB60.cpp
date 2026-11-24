// bin: xb
// va: 0x0011BB60
// what: Reads an integer argument via sub_00119C40 and invokes the void(int) member-function pointer at +0x0C.
// tool: Gemini 4 Neon

class ScriptObject {};

extern "C" int __cdecl sub_00119C40();

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
    (obj->*fn)(sub_00119C40());
}

template class Method1<void, int>;

}
