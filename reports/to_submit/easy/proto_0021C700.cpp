// bin: proto
// va: 0x0021C700
// tool: the portal's starter code (no AI)
// pure3d::Image8::vfunc_12 (0x0021C700, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class Image8
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
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12(int a1, int a2, bool a3);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0x10];
    int m_Field20; // +0x20
};

void Image8::vfunc_12(int a1, int a2, bool a3)
{
    *(bool*)((m_Field0C * a2) + m_Field20 + a1) = a3;
}

}
