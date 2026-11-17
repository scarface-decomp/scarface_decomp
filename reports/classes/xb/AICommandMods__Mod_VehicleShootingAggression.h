// AICommandMods::Mod_VehicleShootingAggression (xb): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace AICommandMods {
class Mod_VehicleShootingAggression
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1, int a2);
    virtual void vfunc_02();
    virtual void vfunc_03(int a1, int a2);
    char m_pad04[0xC];
    int m_Field10; // +0x10
};
}
