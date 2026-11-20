// bin: xb
// va: 0x00167CF0
// what: Stores one number in a character object.
// tool: Claude Opus 5.5 (symcov hint: EARS::Framework::Projectile::SetFullSplashDamageRadius(float))
// CharacterObject::vfunc_44 (0x00167CF0)
// Class shape from reports/classes/xb/CharacterObject.h.

class CharacterObject
{
public:
    virtual void* vfunc_00();
    virtual CharacterObject* vfunc_01(int a1);
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
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
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29(int a1);
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual int vfunc_35(int a1);
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual int vfunc_39();
    virtual int vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44(float a1);
    virtual float vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual float vfunc_48();
    virtual void vfunc_49();
    virtual bool vfunc_50();
    virtual bool vfunc_51(bool a1);
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64(int a1, int a2);
    virtual void vfunc_65();
    virtual void vfunc_66();
    virtual void vfunc_67();
    virtual void vfunc_68();
    virtual int vfunc_69();
    void sub_00166150(int);
    void sub_00166250();
    void sub_00168AA0();
    void sub_00169F00(int, int);
    char m_pad04[0x60];
    int m_Field64; // +0x64
    int m_Field68; // +0x68
    int m_Field6C; // +0x6C
    char m_pad70[0x35];
    unsigned char m_FieldA5; // +0xA5
    char m_padA6[0x66];
    float m_Field10C; // +0x10C
    char m_pad110[0x94];
    float m_Field1A4; // +0x1A4
    char m_pad1A8[0x4];
    int m_Field1AC; // +0x1AC
    int m_Field1B0; // +0x1B0
    char m_pad1B4[0x26D];
    bool m_Field421; // +0x421
};

// Sets the value at +0x1A4.
void CharacterObject::vfunc_44(float a1)
{
    m_Field1A4 = a1;
}
