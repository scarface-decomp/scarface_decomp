// bin: xb
// va: 0x00248190
// tool: the portal's starter code (no AI)
// core::ControllerInputPointXBox::vfunc_10 (0x00248190, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace core {

class ControllerInputPointXBox
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
    virtual float vfunc_10(int a1);
    char m_pad04[0x4];
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    char m_pad14[0x4];
    int m_Field18; // +0x18
};

float ControllerInputPointXBox::vfunc_10(int a1)
{
    if (a1) {
        *(int*)a1 = m_Field18;
    }
    return ((m_Field10 - m_Field0C) * m_Field08) + m_Field0C;
}

}
