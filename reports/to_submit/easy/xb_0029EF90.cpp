// bin: xb
// va: 0x0029EF90
// tool: the portal's starter code (no AI)
// pure3d::pddiStack<pure3d::pddiFogState>::vfunc_00 (0x0029EF90, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" char DAT_003D9C94[];
extern "C" void __cdecl sub_00027600(int);

namespace pure3d { class pddiFogState; }

namespace pure3d { 
template <class T0> class pddiStack
{
public:
    virtual pddiStack<pure3d::pddiFogState>* vfunc_00(bool a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};
}

template <> pure3d::pddiStack<pure3d::pddiFogState>* pure3d::pddiStack<pure3d::pddiFogState>::vfunc_00(bool a1)
{
    *(int*)this = (int)DAT_003D9C94;
    sub_00027600(m_Field0C);
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}
