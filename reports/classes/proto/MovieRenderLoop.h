// MovieRenderLoop (proto): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class MovieRenderLoop
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int);
    virtual void vfunc_04(int a1);
    unsigned char m_Field04; // +0x04
    char m_pad05[0x3];
    int m_Field08; // +0x08
};
