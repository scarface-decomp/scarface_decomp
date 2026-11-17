// om::EntityType (proto): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace om {
template <class T0> class EntityType
{
public:
    virtual EntityType<GlobalVehicleSound>* vfunc_00(int a1);
    virtual void vfunc_01();
    virtual int vfunc_02();
    virtual void* vfunc_03();
};
}
