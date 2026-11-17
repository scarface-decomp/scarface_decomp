// pure3d::ShadowMeshImpl (xb): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class ShadowMeshImpl
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ShadowMeshImpl* vfunc_03(unsigned int flags);
    virtual void vfunc_04();
    virtual int vfunc_05();
    void sub_00257CD0();
};
}
