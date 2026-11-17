// bin: proto
// va: 0x00224080
// tool: the portal's starter code (no AI)
// pure3d::MultiController::vfunc_08 (0x00224080, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class MultiController
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
    virtual void vfunc_08(float a1, bool a2);
    virtual void vfunc_09();
    char m_pad04[0xC];
    float m_Field10; // +0x10
    char m_pad14[0x4];
    float m_Field18; // +0x18
};

void MultiController::vfunc_08(float a1, bool a2)
{
    m_Field10 = (a1 * m_Field18) + m_Field10;
    if (a2 == 1) {
        vfunc_09();
    }
}

}
