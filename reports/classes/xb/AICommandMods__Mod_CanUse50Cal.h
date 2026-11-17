// AICommandMods::Mod_CanUse50Cal (xb): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace AICommandMods {
class Mod_CanUse50Cal
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1, int a2);
    virtual void vfunc_02();
    virtual void vfunc_03(int a1, int a2);
    char m_pad04[0x4];
    bool m_Field08; // +0x08
};
}
