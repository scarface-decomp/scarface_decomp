// pure3d::VectorChannel (xb): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class VectorChannel
{
public:
    virtual VectorChannel* vfunc_00(unsigned int flags);
    virtual void vfunc_01();
    virtual int vfunc_02();
    void sub_00288880();
};
}
