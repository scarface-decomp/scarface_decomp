// WheeledLocomotion (xb): one declaration merged from its matched functions.
// Proven for 5 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class WheeledLocomotion
{
public:
    virtual WheeledLocomotion* vfunc_00(int a1);
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    virtual int vfunc_06(int a1);
    virtual int vfunc_07(int a1);
    virtual int vfunc_08();
    void sub_000B1CA0();
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    char m_pad14[0x5];
    bool m_Field19; // +0x19
};
