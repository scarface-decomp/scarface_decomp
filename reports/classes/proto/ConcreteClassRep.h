// ConcreteClassRep (proto): one declaration merged from its matched functions.
// Proven for 733 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

template <class T0> class ConcreteClassRep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    virtual void vfunc_02();
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};
