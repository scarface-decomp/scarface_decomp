// bin: xb
// va: 0x00267E50
// what: 
// tool: the portal's starter code (no AI)

// pure3d::d3dExtGammaControl::vfunc_02 (0x00267E50, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Field04
{
    void sub_0029ACA0(int);
};

namespace pure3d {

class d3dExtGammaControl
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    Field04* m_Field04; // +0x04
};

void d3dExtGammaControl::vfunc_02(int a1)
{
    m_Field04->sub_0029ACA0(a1);
}

}
