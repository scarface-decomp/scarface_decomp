// bin: xb
// va: 0x00285060
// what: Forwards its argument to virtual method slot 14 on the embedded member object at +0x28.
// tool: Gemini 4 Neon

#pragma optimize("y", off)

struct Field28
{
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
    virtual void vfunc_14(int a1);
    void Call14(int a1) { vfunc_14(a1); }
};

namespace pure3d {

class CharacterAnimationLayer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    char m_pad04[0x24];
    Field28 m_Field28; // +0x28
};

void CharacterAnimationLayer::vfunc_04(int a1)
{
    m_Field28.Call14(a1);
}

}
