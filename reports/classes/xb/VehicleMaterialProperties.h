// VehicleMaterialProperties (xb): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class VehicleMaterialProperties
{
public:
    virtual void* vfunc_00();
    virtual VehicleMaterialProperties* vfunc_01(int a1);
};
