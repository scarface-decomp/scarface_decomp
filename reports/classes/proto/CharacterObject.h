// CharacterObject (proto): one declaration merged from its matched functions.
// Proven for 10 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class CharacterObject
{
public:
    virtual void* vfunc_00();
    virtual CharacterObject* vfunc_01(int a1);
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    virtual void vfunc_06(int a1);
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
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual int vfunc_33(int a1);
    virtual void vfunc_34();
    virtual int vfunc_35();
    virtual int vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46(int a1, int a2);
    virtual bool vfunc_47(bool a1);
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual bool vfunc_53();
    void sub_00027B40(int);
    void sub_00149680(int);
    void sub_001497F0();
    void sub_00149EC0();
    void sub_0014B140(int, int);
    void sub_0014BF70();
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    char m_pad14[0x88];
    unsigned char m_Field9C; // +0x9C
    char m_pad9D[0x6A];
    unsigned char m_Field107; // +0x107
    char m_pad108[0x45];
    bool m_Field14D; // +0x14D
    char m_pad14E[0x3A];
    int m_Field188; // +0x188
    int m_Field18C; // +0x18C
    char m_pad190[0x254];
    bool m_Field3E4; // +0x3E4
    char m_pad3E5[0x4];
    bool m_Field3E9; // +0x3E9
};
