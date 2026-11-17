// core::ControllerInputPointXBox (proto): one declaration merged from its matched functions.
// Proven for 5 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace core {
class ControllerInputPointXBox
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
    virtual int vfunc_08(int a1, int a2);
    virtual int vfunc_09(int a1);
    virtual void vfunc_10();
    virtual int vfunc_11(int a1, int a2);
    virtual int vfunc_12(int a1, int a2);
    virtual void vfunc_13();
    virtual int vfunc_14(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    char m_pad14[0x4];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    char m_pad20[0xC];
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
};
}
