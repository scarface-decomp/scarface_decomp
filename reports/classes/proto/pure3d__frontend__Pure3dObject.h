// pure3d::frontend::Pure3dObject (proto): one declaration merged from its matched functions.
// Proven for 4 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
namespace frontend {
class Pure3dObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Pure3dObject* vfunc_03(int a1);
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    void sub_00205D60();
    char m_pad04[0x40];
    int m_Field44; // +0x44
    char m_pad48[0x4C];
    int m_Field94; // +0x94
};
}
}
