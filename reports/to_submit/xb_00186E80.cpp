// bin: xb
// va: 0x00186E80
// what: Invokes the Animation360Track member-function pointer at +0x08 on the given track.
// tool: Gemini 4 Neon

class Animation360Track {};

namespace fight {

template<class T>
class ParamName
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06(T* target);
    char m_pad04[0x4];
    int (T::*m_Getter)(); // +0x08
};

template<class T>
int ParamName<T>::vfunc_06(T* target)
{
    return (target->*m_Getter)();
}

template class ParamName<Animation360Track>;

}
