// pure3d::SimpleFrameController (xb): one declaration merged from its matched functions.
// Proven for 4 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class SimpleFrameController
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
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual int vfunc_17(int a1, int a2);
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual int vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual int vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual int vfunc_27();
    char m_pad04[0x18];
    float m_Field1C; // +0x1C
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    char m_pad28[0x8];
    int m_Field30; // +0x30
};
}
