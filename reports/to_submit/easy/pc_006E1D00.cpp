// bin: pc
// va: 0x006E1D00
// tool: the portal's starter code (no AI)
// core::MemorySmallDlAllocator::vfunc_10 (0x006E1D00, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class MemorySmallDlAllocator
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
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual bool vfunc_10(int a1, int a2, int a3, int a4);
};

bool MemorySmallDlAllocator::vfunc_10(int a1, int a2, int a3, int a4)
{
    int r_ecx;

    r_ecx = (int)this;
    if (a1) {
        *(int*)a1 = *(int*)(r_ecx + 24) - *(int*)(r_ecx + 44);
    }
    if (a2) {
        *(int*)a2 = 0;
    }
    if (a3) {
        *(int*)a3 = *(int*)(r_ecx + 40);
    }
    if (a4) {
        r_ecx = *(int*)(r_ecx + 48);
        *(int*)a4 = r_ecx;
    }
    return true;
}

}
