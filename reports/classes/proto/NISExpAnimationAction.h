// NISExpAnimationAction (proto): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class NISExpAnimationAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual NISExpAnimationAction* vfunc_03(int a1);
    virtual bool vfunc_04();
    char m_pad04[0x14];
    bool m_Field18; // +0x18
};
