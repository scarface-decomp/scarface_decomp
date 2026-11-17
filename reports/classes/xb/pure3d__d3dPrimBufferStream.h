// pure3d::d3dPrimBufferStream (xb): one declaration merged from its matched functions.
// Proven for 8 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class d3dPrimBufferStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int, int, int);
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual int vfunc_09(int a1, int a2, int a3);
    virtual int vfunc_10(int a1, int a2, int a3);
    virtual int vfunc_11(int a1, int a2);
    virtual void vfunc_12();
    virtual int vfunc_13(float a1, float a2, int a3);
    virtual void vfunc_14();
    virtual void vfunc_15(int a1, int a2, int a3, int a4, int a5);
    virtual int vfunc_16(int a1);
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22(int a1, int a2);
    virtual void vfunc_23();
    virtual void vfunc_24();
    void sub_002AD4B0();
    char m_pad04[0x20];
    int m_Field24; // +0x24
    char m_pad28[0x8];
    int m_Field30; // +0x30
    int m_Field34; // +0x34
    int m_Field38; // +0x38
    char m_pad3C[0x8];
    int m_Field44; // +0x44
    int m_Field48; // +0x48
};
}
