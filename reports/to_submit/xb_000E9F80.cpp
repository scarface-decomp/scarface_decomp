// bin: xb
// va: 0x000E9F80
// what: Invokes the SoundPlayTrack member-function pointer at +0x0C on the given track.
// tool: Gemini 4 Neon

class SoundPlayTrack {};

namespace fight {

template<class T>
class ParamEnum
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06(T* target);
    char m_pad04[0x8];
    int (T::*m_Getter)(); // +0x0C
};

template<class T>
int ParamEnum<T>::vfunc_06(T* target)
{
    return (target->*m_Getter)();
}

template class ParamEnum<SoundPlayTrack>;

}
