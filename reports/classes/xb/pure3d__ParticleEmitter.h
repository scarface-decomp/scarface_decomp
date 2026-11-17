// pure3d::ParticleEmitter (xb): one declaration merged from its matched functions.
// Proven for 9 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class ParticleEmitter
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ParticleEmitter* vfunc_03(unsigned int flags);
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
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual float vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29(int a1);
    virtual int vfunc_30();
    virtual void vfunc_31();
    virtual int vfunc_32();
    virtual void vfunc_33(int a1);
    virtual int vfunc_34();
    virtual void vfunc_35();
    virtual int vfunc_36();
    virtual void vfunc_37();
    virtual int vfunc_38();
    void sub_0025E120();
    char m_pad04[0x74];
    int m_Field78; // +0x78
    int m_Field7C; // +0x7C
    int m_Field80; // +0x80
    int m_Field84; // +0x84
    int m_Field88; // +0x88
    char m_pad8C[0xC];
    float m_Field98; // +0x98
};
}
