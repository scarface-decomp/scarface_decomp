// bin: xb
// va: 0x001363B0
// tool: the portal's starter code (no AI)
// CScript::Method2<void, math::Vector, float>::vfunc_00 (0x001363B0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001363D0(int, int, int);

namespace math { class Vector; }

namespace CScript { 
template <class T0, class T1, class T2> class Method2
{
public:
    virtual void vfunc_00(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};
}

template <> void CScript::Method2<void, math::Vector, float>::vfunc_00(int a1, int a2)
{
    sub_001363D0(a1, a2, m_Field0C);
}
