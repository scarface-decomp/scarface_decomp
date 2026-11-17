// pure3d::Pose (proto): one declaration merged from its matched functions.
// Proven for 4 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class Pose
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04(int a1);
    virtual int vfunc_05(int a1, int a2);
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual bool vfunc_09(bool a1);
    virtual void vfunc_10();
    char m_pad04[0x14];
    int m_Field18; // +0x18
    char m_pad1C[0x1];
    unsigned char m_Field1D; // +0x1D
};
}
