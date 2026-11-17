// LoadSet (xb): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class LoadSet
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual LoadSet* vfunc_03(int a1);
    char m_pad04[0x10];
    int m_Field14; // +0x14
    char m_pad18[0x4];
    int m_Field1C; // +0x1C
    char m_pad20[0x10];
    int m_Field30; // +0x30
};
