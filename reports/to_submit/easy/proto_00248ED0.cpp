// bin: proto
// va: 0x00248ED0
// tool: the portal's starter code (no AI)
// core::MemoryAllocatorMalloc::vfunc_04 (0x00248ED0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_002CB418(int);

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
    r_eax = sub_002CB418(r_eax);
    return r_eax;
}

}
