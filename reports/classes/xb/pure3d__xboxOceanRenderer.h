// pure3d::xboxOceanRenderer (xb): one declaration merged from its matched functions.
// Proven for 7 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class xboxOceanRenderer
{
public:
    virtual xboxOceanRenderer* vfunc_00(unsigned int flags);
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03(int a1, int a2, int a3);
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual bool vfunc_08(bool a1);
    virtual bool vfunc_09();
    virtual void vfunc_10();
    virtual int vfunc_11(int a1);
    void sub_002967D0(int);
    void sub_00297000();
    void sub_00297130();
    void sub_00297370();
    int m_Field04; // +0x04
    char m_pad08[0x8];
    int m_Field10; // +0x10
    char m_pad14[0x43C];
    bool m_Field450; // +0x450
};
}
