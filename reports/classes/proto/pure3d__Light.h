// pure3d::Light (proto): one declaration merged from its matched functions.
// Proven for 5 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class Light
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Light* vfunc_03(int a1);
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int a1);
    virtual int vfunc_08();
    virtual int vfunc_09(int a1, int a2, int a3);
    virtual void vfunc_10(int a1);
    virtual void vfunc_11(int);
    char m_pad04[0x8];
    bool m_Field0C; // +0x0C
    char m_pad0D[0xB];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    int m_Field20; // +0x20
    int m_Field24; // +0x24
};
}
