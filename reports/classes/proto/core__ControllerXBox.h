// core::ControllerXBox (proto): one declaration merged from its matched functions.
// Proven for 7 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace core {
class ControllerXBox
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ControllerXBox* vfunc_03(int a1);
    virtual void vfunc_04();
    virtual void* vfunc_05();
    virtual void* vfunc_06();
    virtual void* vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual int vfunc_12(int a1);
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual int vfunc_17(int a1);
    int m_Field04; // +0x04
    char m_pad08[0xC];
    int m_Field14; // +0x14
    char m_pad18[0x430];
    int m_Field448; // +0x448
};
}
