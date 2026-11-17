// renderer::PropRenderable (proto): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace renderer {
class PropRenderable
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual PropRenderable* vfunc_03(int a1);
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09(int a1);
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual bool vfunc_15(int a1);
    void sub_0004F610();
    char m_pad04[0x7C];
    int m_Field80; // +0x80
    int m_Field84; // +0x84
    int m_Field88; // +0x88
    bool m_Field8C; // +0x8C
};
}
