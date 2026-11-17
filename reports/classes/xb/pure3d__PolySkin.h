// pure3d::PolySkin (xb): one declaration merged from its matched functions.
// Proven for 8 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class PolySkin
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual PolySkin* vfunc_03(unsigned int flags);
    virtual void vfunc_04();
    virtual int vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12(int a1);
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual bool vfunc_17(bool a1);
    virtual void vfunc_18();
    virtual bool vfunc_19();
    virtual float vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual int vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual int vfunc_30(int a1);
    void sub_00277D90();
    char m_pad04[0x4C];
    bool m_Field50; // +0x50
    char m_pad51[0x3];
    float m_Field54; // +0x54
    char m_pad58[0x8];
    int m_Field60; // +0x60
    char m_pad64[0x8];
    int m_Field6C; // +0x6C
};
}
