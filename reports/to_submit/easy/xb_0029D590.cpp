// bin: xb
// va: 0x0029D590
// tool: the portal's starter code (no AI)
// pure3d::d3dContext::vfunc_09 (0x0029D590, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class d3dContext
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
    virtual float vfunc_09();
    char m_pad04[0x148];
    int m_Field14C; // +0x14C
};

float d3dContext::vfunc_09()
{
    return *(float*)(m_Field14C + 8);
}

}
