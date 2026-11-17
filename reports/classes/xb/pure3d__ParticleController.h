// pure3d::ParticleController (xb): one declaration merged from its matched functions.
// Proven for 5 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class ParticleController
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ParticleController* vfunc_03(unsigned int flags);
    virtual void vfunc_04();
    virtual int vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08(float a1, int a2);
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual float vfunc_12();
    virtual float vfunc_13();
    void sub_00291FD0();
    char m_pad04[0xC];
    float m_Field10; // +0x10
    char m_pad14[0x24];
    float m_Field38; // +0x38
    float m_Field3C; // +0x3C
    float m_Field40; // +0x40
};
}
