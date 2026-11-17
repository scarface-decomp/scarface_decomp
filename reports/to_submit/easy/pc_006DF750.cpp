// bin: pc
// va: 0x006DF750
// tool: the portal's starter code (no AI)
// core::MemoryAllocatorMalloc::vfunc_05 (0x006DF750, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F15C;

namespace core {

class MemoryAllocatorMalloc
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
};

void MemoryAllocatorMalloc::vfunc_05(int a1)
{
    ((void (__cdecl*)(int))DAT_0072F15C)(a1);
}

}
