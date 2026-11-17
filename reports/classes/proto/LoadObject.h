// LoadObject (proto): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class LoadObject
{
public:
    virtual void* vfunc_00();
    virtual LoadObject* vfunc_01(int a1);
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05(int a1);
    char m_pad04[0x1C];
    int m_Field20; // +0x20
    int m_Field24; // +0x24
};
