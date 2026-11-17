// Collidable (xb): one declaration merged from its matched functions.
// Proven for 6 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class Collidable
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    virtual Collidable* vfunc_03(int a1);
    virtual bool vfunc_04();
    virtual Collidable* vfunc_05();
    virtual void vfunc_06();
    int m_Field04; // +0x04
};
