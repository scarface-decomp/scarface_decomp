// bin: xb
// va: 0x00273720
// what: Returns the float at the start of the last active blend entry when the entry count at +0x1C is positive, or the default float at DAT_0039D584.
// tool: Gemini 4 Neon

extern "C" const float DAT_0039D584;

namespace pure3d {

struct BlendEntry_00273720
{
    float m_Field00;
    char m_pad04[0x28];
};

class BlendFrameController
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
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual float vfunc_15();
    char m_pad04[0x18];
    unsigned int m_Count; // +0x1C
    BlendEntry_00273720 m_Entries[4]; // +0x20
};

float BlendFrameController::vfunc_15()
{
    if (m_Count > 0)
        return m_Entries[m_Count - 1].m_Field00;
    return DAT_0039D584;
}

}
