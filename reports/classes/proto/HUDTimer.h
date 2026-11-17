// HUDTimer (proto): one declaration merged from its matched functions.
// Proven for 6 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class HUDTimer
{
public:
    virtual void* vfunc_00();
    virtual HUDTimer* vfunc_01(int a1);
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
    virtual void vfunc_28(int a1);
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual bool vfunc_33(int a1, int a2);
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual bool vfunc_38(int a1);
    void sub_0016E260();
    void sub_0016E5E0(int, int);
    char m_pad04[0x28];
    int m_Field2C; // +0x2C
    char m_pad30[0x10];
    int m_Field40; // +0x40
    char m_pad44[0x4];
    bool m_Field48; // +0x48
    char m_pad49[0x3];
    int m_Field4C; // +0x4C
    int m_Field50; // +0x50
    int m_Field54; // +0x54
    int m_Field58; // +0x58
};
