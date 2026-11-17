// pure3d::xboxOceanRenderer (proto): one declaration merged from its matched functions.
// Proven for 7 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class xboxOceanRenderer
{
public:
    virtual xboxOceanRenderer* vfunc_00(int a1);
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03(int a1, int a2, int a3);
    virtual void vfunc_04(int a1, int a2, int a3);
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual bool vfunc_08(bool a1);
    virtual bool vfunc_09();
    virtual int vfunc_10(int a1);
    void sub_00252C80();
    void sub_00252E10(int);
    void sub_00253120();
    int m_Field04; // +0x04
    char m_pad08[0x218];
    int m_Field220; // +0x220
    int m_Field224; // +0x224
    int m_Field228; // +0x228
    char m_pad22C[0x228];
    bool m_Field454; // +0x454
};
}
