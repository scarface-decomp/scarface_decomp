// pure3d::Image32 (proto): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class Image32
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual int vfunc_11(int a1, int a2);
    virtual int vfunc_12(int a1, int a2, int a3);
    virtual int vfunc_13(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    char m_pad14[0xC];
    int m_Field20; // +0x20
};
}
