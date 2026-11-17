// CVManager (proto): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class CVManager
{
public:
    virtual CVManager* vfunc_00(int a1);
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03(int a1, int a2);
    char m_pad04[0x3B4];
    int m_Field3B8; // +0x3B8
};
