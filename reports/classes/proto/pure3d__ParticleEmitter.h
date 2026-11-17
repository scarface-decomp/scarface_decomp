// pure3d::ParticleEmitter (proto): one declaration merged from its matched functions.
// Proven for 8 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class ParticleEmitter
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ParticleEmitter* vfunc_03(int a1);
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
    virtual float vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28(int a1);
    virtual int vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32(int a1);
    virtual int vfunc_33();
    virtual void vfunc_34();
    virtual int vfunc_35();
    virtual void vfunc_36();
    virtual int vfunc_37();
    char m_pad04[0x74];
    int m_Field78; // +0x78
    char m_pad7C[0x4];
    int m_Field80; // +0x80
    int m_Field84; // +0x84
    int m_Field88; // +0x88
    char m_pad8C[0xC];
    float m_Field98; // +0x98
};
}
