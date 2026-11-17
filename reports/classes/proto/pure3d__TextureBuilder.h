// pure3d::TextureBuilder (proto): one declaration merged from its matched functions.
// Proven for 4 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class TextureBuilder
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual int vfunc_08();
    virtual int vfunc_09(int a1);
    virtual int vfunc_10();
    int m_Field04; // +0x04
    char m_pad08[0x4];
    int m_Field0C; // +0x0C
    char m_pad10[0x4];
    int m_Field14; // +0x14
    char m_pad18[0x4];
    int m_Field1C; // +0x1C
    char m_pad20[0x8];
    int m_Field28; // +0x28
};
}
