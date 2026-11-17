// core::ControllerBuffer (xb): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace core {
class ControllerBuffer
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int);
    virtual void vfunc_04(int a1, int a2);
    virtual void vfunc_05(int);
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual int vfunc_09();
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0x8];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    int m_Field20; // +0x20
};
}
