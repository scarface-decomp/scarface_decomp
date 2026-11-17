// pure3d::d3dExtStaticShadowGen (xb): one declaration merged from its matched functions.
// Proven for 6 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class d3dExtStaticShadowGen
{
public:
    virtual d3dExtStaticShadowGen* vfunc_00(unsigned int flags);
    virtual void vfunc_01();
    virtual int vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual int vfunc_12(int a1);
    void sub_002A2AA0();
    void sub_002A30A0();
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    char m_pad0C[0x8];
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    char m_pad1C[0x20];
    int m_Field3C; // +0x3C
};
}
