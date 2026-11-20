// bin: xb
// va: 0x00292230
// what: Passes its one argument on to the function at 0x002A9290 (an adapter slot that forwards a call).
// tool: Claude Opus 5.5

// This part of the program was built with frame pointers.
#pragma optimize("y", off)

extern "C" void __cdecl sub_002A9290(int);

namespace pure3d {

class AdaptPDDI
{
public:
    virtual void vfunc_00(int a1);
    virtual void vfunc_01();
    virtual void vfunc_02(int a1, int a2, int a3);
};

void AdaptPDDI::vfunc_00(int a1)
{
    sub_002A9290(a1);
}

}
