// bin: proto
// va: 0x00264540
// tool: the portal's starter code (no AI)
// pure3d::d3dExtXboxControl::vfunc_03 (0x00264540, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_0043064C;
extern "C" void __stdcall sub_00318C00(int);
extern "C" void __stdcall sub_00318C60(int);

namespace pure3d {

class d3dExtXboxControl
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
};

void d3dExtXboxControl::vfunc_03()
{
    sub_00318C60(0);
    if (DAT_0043064C) {
        sub_00318C00(2);
    }
}

}
