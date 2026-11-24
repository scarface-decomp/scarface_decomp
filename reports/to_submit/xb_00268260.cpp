// bin: xb
// va: 0x00268260
// what: Forwards two arguments to sub_0029BDA0 on the object at *(m_Field04 + 0x2D4).
// tool: Gemini 4 Neon

#pragma optimize("y", off)

struct Object_00268260
{
    void sub_0029BDA0(int a1, int a2);
};

namespace pure3d {

class d3dExtVertexProgram
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1, int a2);
    int m_Field04; // +0x04
};

void d3dExtVertexProgram::vfunc_01(int a1, int a2)
{
    ((Object_00268260*)*(int*)(m_Field04 + 0x2D4))->sub_0029BDA0(a1, a2);
}

}
