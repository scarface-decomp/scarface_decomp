// StatePropAttachmentObject (xb): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class StatePropAttachmentObject
{
public:
    virtual void* vfunc_00();
    virtual void vfunc_01(int a1, int a2);
    int m_Field04; // +0x04
    int m_Field08; // +0x08
};
