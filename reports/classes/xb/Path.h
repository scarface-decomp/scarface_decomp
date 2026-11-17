// Path (xb): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class Path
{
public:
    virtual Path* vfunc_00(int a1);
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1, int a2, int a3);
    virtual bool vfunc_04(bool a1);
    void sub_00034730(int, int, int, int);
    char m_pad04[0x8];
    short m_Field0C; // +0x0C
    char m_pad0E[0x6];
    unsigned char m_Field14; // +0x14
    char m_pad15[0x3];
    bool m_Field18; // +0x18
};
