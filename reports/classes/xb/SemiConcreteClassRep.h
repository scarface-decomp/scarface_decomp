// SemiConcreteClassRep (xb): one declaration merged from its matched functions.
// Proven for 5 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

template <class T0> class SemiConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    virtual void vfunc_02();
    char m_pad04[0x10];
    int m_Field14; // +0x14
};
