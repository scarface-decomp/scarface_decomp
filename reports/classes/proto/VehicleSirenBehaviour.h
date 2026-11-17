// VehicleSirenBehaviour (proto): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class VehicleSirenBehaviour
{
public:
    virtual VehicleSirenBehaviour* vfunc_00(int a1);
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1);
    void sub_0009EC50();
    int m_Field04; // +0x04
    char m_pad08[0x10];
    int m_Field18; // +0x18
    bool m_Field1C; // +0x1C
};
