// bin: xb
// va: 0x00273420
// tool: the portal's starter code (no AI)
// pure3d::SimpleFrameController::vfunc_13 (0x00273420, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D584;

namespace pure3d {

class SimpleFrameController
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
    virtual void vfunc_12();
    virtual float vfunc_13();
    char m_pad04[0x2C];
    int m_Field30; // +0x30
};

float SimpleFrameController::vfunc_13()
{
    int r_eax;

    r_eax = m_Field30;
    if (r_eax) {
        return *(float*)(r_eax + 12);
    }
    return DAT_0039D584;
}

}
