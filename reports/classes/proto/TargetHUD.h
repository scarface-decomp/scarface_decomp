// TargetHUD (proto): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class Field44;
class Field48;
class Field50;
class Field5C;
class TargetHUD
{
public:
    virtual void vfunc_00(int a1, int a2);
    virtual void vfunc_01();
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
    virtual void vfunc_29();
    void sub_0016E260();
    void sub_0018D980(int);
    char m_pad04[0x28];
    int m_Field2C; // +0x2C
    char m_pad30[0x14];
    Field44* m_Field44; // +0x44
    Field48* m_Field48; // +0x48
    char m_pad4C[0x4];
    Field50* m_Field50; // +0x50
    char m_pad54[0x8];
    Field5C* m_Field5C; // +0x5C
    char m_pad60[0x30];
    int m_Field90; // +0x90
};
