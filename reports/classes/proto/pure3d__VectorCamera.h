// pure3d::VectorCamera (proto): one declaration merged from its matched functions.
// Proven for 5 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class VectorCamera
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual VectorCamera* vfunc_03(int a1);
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual int vfunc_08(int a1, int a2);
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void* vfunc_15();
    virtual void* vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual int vfunc_22(int a1);
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    char m_pad04[0xC];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    char m_pad18[0x34];
    int m_Field4C; // +0x4C
    char m_pad50[0x3C];
    int m_Field8C; // +0x8C
    char m_pad90[0x2C];
    int m_FieldBC; // +0xBC
    int m_FieldC0; // +0xC0
    int m_FieldC4; // +0xC4
    char m_padC8[0x4];
    bool m_FieldCC; // +0xCC
};
}
