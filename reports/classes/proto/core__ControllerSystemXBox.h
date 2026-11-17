// core::ControllerSystemXBox (proto): one declaration merged from its matched functions.
// Proven for 7 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace core {
class ControllerSystemXBox
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ControllerSystemXBox* vfunc_03(int a1);
    virtual int vfunc_04();
    virtual int vfunc_05(int a1);
    virtual void vfunc_06();
    virtual void vfunc_07(int);
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10(int a1);
    virtual int vfunc_11(int a1);
    virtual int vfunc_12(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0x8];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    int m_Field20; // +0x20
    char m_pad24[0x127C];
    int m_Field12A0; // +0x12A0
};
}
