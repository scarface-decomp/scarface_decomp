// bin: pc
// va: 0x006F2EF0
// tool: the portal's starter code (no AI)
// om::SparksHeap::vfunc_00 (0x006F2EF0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006F2C90(void);

namespace om {

class SparksHeap
{
public:
    virtual SparksHeap* vfunc_00(int a1);
};

SparksHeap* SparksHeap::vfunc_00(int a1)
{
    sub_006F2C90();
    return this;
}

}
