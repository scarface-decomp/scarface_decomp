// pure3d::SpriteParticleEmitter (xb): one declaration merged from its matched functions.
// Proven for 8 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class SpriteParticleEmitter
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual SpriteParticleEmitter* vfunc_03(unsigned int flags);
    virtual void vfunc_04();
    virtual int vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual int vfunc_09();
    virtual void vfunc_10(int a1);
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual int vfunc_17();
    virtual void vfunc_18();
    virtual int vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual bool vfunc_27();
    void sub_0025FBB0();
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0x70];
    int m_Field80; // +0x80
    char m_pad84[0x1C];
    int m_FieldA0; // +0xA0
    char m_padA4[0x8C];
    bool m_Field130; // +0x130
    char m_pad131[0x13];
    int m_Field144; // +0x144
    int m_Field148; // +0x148
    char m_pad14C[0x8];
    int m_Field154; // +0x154
    char m_pad158[0xC];
    int m_Field164; // +0x164
    char m_pad168[0x8];
    int m_Field170; // +0x170
    char m_pad174[0x8];
    int m_Field17C; // +0x17C
    char m_pad180[0x10];
    int m_Field190; // +0x190
    char m_pad194[0x8];
    int m_Field19C; // +0x19C
    char m_pad1A0[0x4];
    int m_Field1A4; // +0x1A4
    char m_pad1A8[0x4];
    int m_Field1AC; // +0x1AC
};
}
