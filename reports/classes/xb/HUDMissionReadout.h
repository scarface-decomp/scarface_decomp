// HUDMissionReadout (xb): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class HUDMissionReadout
{
public:
    virtual int vfunc_00(int a1, int a2);
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
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
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    int m_Field04; // +0x04
    char m_pad08[0x14];
    int m_Field1C; // +0x1C
    int m_Field20; // +0x20
    char m_pad24[0x8];
    int m_Field2C; // +0x2C
    char m_pad30[0x50];
    int m_Field80; // +0x80
    char m_pad84[0x1C];
    int m_FieldA0; // +0xA0
};
