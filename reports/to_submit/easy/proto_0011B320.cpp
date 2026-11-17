// bin: proto
// va: 0x0011B320
// tool: the portal's starter code (no AI)
// CScript::Method5<void, float, float, float, float, float>::vfunc_00 (0x0011B320, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0011B340(int, int, int);

namespace CScript { 
template <class T0, class T1, class T2, class T3, class T4, class T5> class Method5
{
public:
    virtual void vfunc_00(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};
}

template <> void CScript::Method5<void, float, float, float, float, float>::vfunc_00(int a1, int a2)
{
    sub_0011B340(a1, a2, m_Field0C);
}
