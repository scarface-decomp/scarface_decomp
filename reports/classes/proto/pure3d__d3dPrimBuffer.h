// pure3d::d3dPrimBuffer (proto): one declaration merged from its matched functions.
// Proven for 6 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class d3dPrimBuffer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual d3dPrimBuffer* vfunc_03(int a1);
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07();
    virtual int vfunc_08(int a1);
    virtual void vfunc_09();
    virtual bool vfunc_10(int a1);
    virtual int vfunc_11(int a1);
    virtual void vfunc_12();
    void sub_00264490();
    char m_pad04[0x20];
    int m_Field24; // +0x24
    char m_pad28[0x4];
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
    char m_pad34[0x1];
    bool m_Field35; // +0x35
    bool m_Field36; // +0x36
};
}
