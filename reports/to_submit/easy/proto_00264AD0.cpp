// bin: proto
// va: 0x00264AD0
// tool: the portal's starter code (no AI)
// pure3d::d3dExtXboxControl::vfunc_02 (0x00264AD0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07();
};

namespace pure3d {

class d3dExtXboxControl
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

int d3dExtXboxControl::vfunc_02()
{
    return ((Object*)*(int*)(m_Field0C + 536))->vfunc_07() == 720;
}

}
