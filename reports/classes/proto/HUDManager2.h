// HUDManager2 (proto): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class HUDManager2
{
public:
    virtual HUDManager2* vfunc_00(int a1);
    virtual int vfunc_01(int a1, int a2);
    virtual void vfunc_02();
    char m_pad04[0x14];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};
