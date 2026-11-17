// DrugWarsHUD::DrugWarsHUDFrontMenuItem (xb): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace DrugWarsHUD {
class DrugWarsHUDFrontMenuItem
{
public:
    virtual DrugWarsHUDFrontMenuItem* vfunc_00(int a1);
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1);
    char m_pad04[0x1];
    unsigned char m_Field05; // +0x05
    char m_pad06[0x2A];
    int m_Field30; // +0x30
    int m_Field34; // +0x34
    int m_Field38; // +0x38
};
}
