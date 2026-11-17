// pure3d::Sprite (xb): one declaration merged from its matched functions.
// Proven for 5 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class Sprite
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Sprite* vfunc_03(unsigned int flags);
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual int vfunc_09();
    virtual void vfunc_10(int a1);
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17(int a1);
    virtual int vfunc_18(int a1);
    void sub_0026D8D0();
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0x34];
    int m_Field44; // +0x44
    char m_pad48[0x40];
    int m_Field88; // +0x88
    int m_Field8C; // +0x8C
    int m_Field90; // +0x90
    int m_Field94; // +0x94
};
}
