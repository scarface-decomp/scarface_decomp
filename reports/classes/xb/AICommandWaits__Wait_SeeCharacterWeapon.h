// AICommandWaits::Wait_SeeCharacterWeapon (xb): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace AICommandWaits {
class Wait_SeeCharacterWeapon
{
public:
    virtual void vfunc_00(int a1, int a2);
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Wait_SeeCharacterWeapon* vfunc_03(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};
}
