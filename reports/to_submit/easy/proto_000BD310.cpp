// bin: proto
// va: 0x000BD310
// tool: the portal's starter code (no AI)
// NISPackage::vfunc_01 (0x000BD310, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class NISPackage
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void NISPackage::vfunc_01()
{
    int r_eax, r_ecx;

    r_ecx = (int)this;
    r_eax = *(int*)(r_ecx + 176);
    if (r_eax < 2) {
        r_eax = *(int*)r_ecx;
        ((void (__stdcall*)(int))*(int*)(r_eax + 12))(1);
        return;
    }
    r_eax -= 1;
    *(int*)(r_ecx + 176) = r_eax;
}
