// bin: xb
// va: 0x00268280
// tool: the portal's starter code (no AI)
// pure3d::d3dExtVertexProgram::vfunc_03 (0x00268280, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    void sub_0029BAC0(int);
};

namespace pure3d {

class d3dExtVertexProgram
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1);
    int m_Field04; // +0x04
};

void d3dExtVertexProgram::vfunc_03(int a1)
{
    ((Object*)*(int*)(m_Field04 + 724))->sub_0029BAC0(a1);
}

}
