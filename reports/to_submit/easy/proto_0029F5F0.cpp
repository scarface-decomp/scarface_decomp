// bin: proto
// va: 0x0029F5F0
// tool: the portal's starter code (no AI)
// om::Command0<void>::vfunc_00 (0x0029F5F0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B9B28[];
extern "C" void __cdecl sub_00025160(int);

namespace om { 
template <class T0> class Command0
{
public:
    virtual Command0<void>* vfunc_00(int a1);
};
}

template <> om::Command0<void>* om::Command0<void>::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_003B9B28;
    if (a1 & 1) {
        sub_00025160((int)this);
    }
    return this;
}
