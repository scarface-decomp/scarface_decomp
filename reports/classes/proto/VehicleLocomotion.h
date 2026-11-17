// VehicleLocomotion (proto): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class VehicleLocomotion
{
public:
    virtual VehicleLocomotion* vfunc_00(int a1);
    virtual void vfunc_01(int a1);
    virtual void vfunc_02();
    int m_Field04; // +0x04
};
