// content::LoadInventory::DynamicCaster (xb): one declaration merged from its matched functions.
// Proven for 36 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace content {
namespace LoadInventory {
template <class T0> class DynamicCaster
{
public:
    virtual void vfunc_00(int a1);
};
}
}
