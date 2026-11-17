// pure3d::Image8 (xb): one declaration merged from its matched functions.
// Proven for 8 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class Image8
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
    virtual void vfunc_12(int a1, int a2, bool a3);
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual int vfunc_15(int a1);
    virtual int vfunc_16();
    virtual int vfunc_17(int a1, int a2);
    virtual void vfunc_18();
    virtual int vfunc_19(int a1);
    virtual void* vfunc_20();
    virtual void vfunc_21();
    virtual int vfunc_22(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0x10];
    int m_Field20; // +0x20
    char m_pad24[0x4];
    int m_Field28; // +0x28
    char m_pad2C[0x3FC];
    int m_Field428; // +0x428
};
}
