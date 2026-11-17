// pure3d::d3dExtFramebufferEffects (proto): one declaration merged from its matched functions.
// Proven for 12 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class d3dExtFramebufferEffects
{
public:
    virtual d3dExtFramebufferEffects* vfunc_00(int a1);
    virtual int vfunc_01(bool a1, int a2, int a3, bool a4);
    virtual bool vfunc_02(bool a1);
    virtual bool vfunc_03(bool a1);
    virtual void vfunc_04();
    virtual int vfunc_05(int a1, int a2);
    virtual int vfunc_06(int a1, int a2, int a3, int a4);
    virtual int vfunc_07(int a1, int a2, int a3);
    virtual int vfunc_08(int a1, int a2);
    virtual int vfunc_09(int a1, int a2);
    virtual int vfunc_10(int a1, int a2, int a3);
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual bool vfunc_21(bool a1);
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual bool vfunc_24(bool a1);
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    int m_Field28; // +0x28
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
    int m_Field34; // +0x34
    bool m_Field38; // +0x38
    char m_pad39[0x1];
    bool m_Field3A; // +0x3A
    char m_pad3B[0x1];
    int m_Field3C; // +0x3C
    int m_Field40; // +0x40
    int m_Field44; // +0x44
    char m_pad48[0x14];
    bool m_Field5C; // +0x5C
    char m_pad5D[0x3];
    int m_Field60; // +0x60
    int m_Field64; // +0x64
    bool m_Field68; // +0x68
    char m_pad69[0x74];
    bool m_FieldDD; // +0xDD
    char m_padDE[0x6E];
    bool m_Field14C; // +0x14C
};
}
