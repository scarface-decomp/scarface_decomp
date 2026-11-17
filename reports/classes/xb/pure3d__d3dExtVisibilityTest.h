// pure3d::d3dExtVisibilityTest (xb): one declaration merged from its matched functions.
// Proven for 5 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class d3dExtVisibilityTest
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04(int a1);
    virtual int vfunc_05(int a1);
    virtual void vfunc_06();
    virtual int vfunc_07(int a1);
    char m_pad04[0x5C];
    int m_Field60; // +0x60
};
}
