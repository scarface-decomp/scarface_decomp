// bin: pc
// va: 0x006DF730
// tool: the portal's starter code (no AI)
// core::MemoryAllocatorMalloc::vfunc_04 (0x006DF730, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F158;

namespace core {

class MemoryAllocatorMalloc
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04(int a1);
};

int MemoryAllocatorMalloc::vfunc_04(int a1)
{
    int r_eax;

    r_eax = a1;
    if (!a1) {
        r_eax = 1;
    }
    r_eax = ((int (__cdecl*)(int))DAT_0072F158)(r_eax);
    return r_eax;
}

}
