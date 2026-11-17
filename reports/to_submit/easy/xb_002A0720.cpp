// bin: xb
// va: 0x002A0720
// tool: the portal's starter code (no AI)
// pure3d::d3dExtXboxControl::vfunc_04 (0x002A0720, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0045F7EC;
extern "C" void __stdcall sub_0032DDB0(int);
extern "C" void __stdcall sub_0032DE10(int);

namespace pure3d {

class d3dExtXboxControl
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
};

void d3dExtXboxControl::vfunc_04()
{
    sub_0032DE10(0);
    if (DAT_0045F7EC) {
        sub_0032DDB0(2);
    }
}

}
