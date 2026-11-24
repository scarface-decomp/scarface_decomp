// bin: xb
// va: 0x002850C0
// what: Calls virtual method slot 9 on the embedded member object at +0x28.
// tool: Gemini 4 Neon

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
    void Call09() { vfunc_09(); }
};

namespace pure3d {

class CharacterAnimationLayer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int a1, int a2);
    char m_pad04[0x24];
    Field28 m_Field28; // +0x28
};

void CharacterAnimationLayer::vfunc_06(int, int)
{
    m_Field28.Call09();
}

}
