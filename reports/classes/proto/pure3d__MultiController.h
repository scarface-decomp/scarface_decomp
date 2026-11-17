// pure3d::MultiController (proto): one declaration merged from its matched functions.
// Proven for 7 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class MultiController
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual MultiController* vfunc_03(int a1);
    virtual void vfunc_04();
    virtual int vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual int vfunc_10(int a1);
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual float vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual int vfunc_17(int a1, int a2);
    virtual void vfunc_18();
    virtual int vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual float vfunc_23();
    char m_pad04[0x10];
    float m_Field14; // +0x14
    int m_Field18; // +0x18
    char m_pad1C[0x4];
    float m_Field20; // +0x20
    float m_Field24; // +0x24
    float m_Field28; // +0x28
    float m_Field2C; // +0x2C
    char m_pad30[0x4];
    int m_Field34; // +0x34
};
}
