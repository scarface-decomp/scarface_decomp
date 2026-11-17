// pure3d::BoolChannel (proto): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class BoolChannel
{
public:
    virtual BoolChannel* vfunc_00(int a1);
    virtual void vfunc_01();
    virtual int vfunc_02();
};
}
