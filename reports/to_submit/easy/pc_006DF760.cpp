// bin: pc
// va: 0x006DF760
// tool: the portal's starter code (no AI)
// core::MemoryAllocatorMalloc::vfunc_07 (0x006DF760, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006DF780(int, int);

namespace core {

class MemoryAllocatorMalloc
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int a1, int a2);
};

void MemoryAllocatorMalloc::vfunc_07(int a1, int a2)
{
    sub_006DF780(a1, a2);
}

}
