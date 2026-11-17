// WheeledLocomotion (proto): one declaration merged from its matched functions.
// Proven for 6 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class Field08;
class WheeledLocomotion
{
public:
    virtual WheeledLocomotion* vfunc_00(int a1);
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03(int a1);
    virtual int vfunc_04(int a1);
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual int vfunc_08(int a1);
    virtual int vfunc_09(int a1);
    virtual int vfunc_10();
    void sub_000A47C0();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};
