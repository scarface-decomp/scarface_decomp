// bin: proto
// va: 0x000663A0
// what: 
// tool: the portal's starter code (no AI)

// CScript::Function0<void>::vfunc_00 (Proto 0x000663A0, 6 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace CScript { 
template <class T0> class Function0
{
public:
    virtual void vfunc_00(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};
}

template <> void CScript::Function0<void>::vfunc_00(int a1, int a2)
{
    ((void (__cdecl*)(void))m_Field0C)();
}
