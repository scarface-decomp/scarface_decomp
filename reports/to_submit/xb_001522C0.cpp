// bin: xb
// va: 0x001522C0
// what: Builds a camera transition: two values cleared and a third set to one.
// tool: Claude Opus 5.5 (symcov hint: fcGlowPixelShader::fcGlowPixelShader)
// sub_001522C0 (0x001522C0, 30 bytes)
// The vtable it installs (0x003B3080) is CameraTransition's: CameraTransition::vfunc_00
// (0x00152530, its deleting destructor) installs the same one, so this is CameraTransition's
// constructor. Slot 0 keeps the shape of the matched CameraTransition::vfunc_00.

class CameraTransition
{
public:
    CameraTransition();
    virtual CameraTransition* vfunc_00(int a1);
    virtual void vfunc_01();
    virtual void vfunc_02();

    int m_Field04;   // +0x04
    int m_Field08;   // +0x08
    float m_Field0C; // +0x0C
};

// Clears the first two values and sets the third to one.
CameraTransition::CameraTransition()
{
    m_Field04 = 0;
    m_Field08 = 0;
    m_Field0C = 1.0f;
}
