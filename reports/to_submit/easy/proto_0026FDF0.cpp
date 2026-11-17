// bin: proto
// va: 0x0026FDF0
// tool: the portal's starter code (no AI)
// pure3d::d3dPrimBuffer::vfunc_05 (0x0026FDF0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class d3dPrimBuffer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual bool vfunc_05(int a1);
    char m_pad04[0x30];
    bool m_Field34; // +0x34
};

bool d3dPrimBuffer::vfunc_05(int a1)
{
    m_Field34 = false;
    *(bool*)(a1 + 4) = false;
    return false;
}

}
