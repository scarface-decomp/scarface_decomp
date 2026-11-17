// pure3d::d3dExtAntialiasControl (proto): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class d3dExtAntialiasControl
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02(bool a1);
    virtual void vfunc_03();
    virtual int vfunc_04();
    int m_Field04; // +0x04
};
}
