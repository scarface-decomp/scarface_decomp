// bin: pc
// va: 0x006DF7C0
// tool: the portal's starter code (no AI)
// core::MemoryAllocatorMalloc::vfunc_08 (0x006DF7C0, 22 bytes)
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
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08(int a1);
};

void MemoryAllocatorMalloc::vfunc_08(int a1)
{
    if (a1) {
        ((void (__cdecl*)(int))DAT_0072F15C)(*(int*)(a1 + -4));
    }
}

}
