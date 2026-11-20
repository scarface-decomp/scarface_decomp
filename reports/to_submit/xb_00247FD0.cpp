// bin: xb
// va: 0x00247FD0
// what: Stores a number in the controller output, kept between zero and one.
// tool: Claude Opus 5.5 (symcov hint: Reward::SetScale)
// core::ControllerOutputPointXBox::vfunc_07 (0x00247FD0, 64 bytes)

namespace core {

class ControllerOutputPointXBox
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void* vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(float value);

    char m_pad04[0x8];
    float m_Field0C; // +0x0C
};

// Clamps the value to [0, 1] and stores it.
void ControllerOutputPointXBox::vfunc_07(float value)
{
    if (value < 0.0f)
    {
        m_Field0C = 0.0f;
    }
    else if (value > 1.0f)
    {
        m_Field0C = 1.0f;
    }
    else
    {
        m_Field0C = value;
    }
}

}
