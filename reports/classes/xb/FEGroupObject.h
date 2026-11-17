// FEGroupObject (xb): one declaration merged from its matched functions.
// Proven for 15 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class Field40;
class FEGroupObject
{
public:
    virtual void* vfunc_00();
    virtual FEGroupObject* vfunc_01(int a1);
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
    virtual void vfunc_12(int a1);
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17(bool a1);
    virtual void vfunc_18();
    virtual bool vfunc_19(int a1);
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23(int a1);
    virtual void vfunc_24(int a1);
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual int vfunc_28(int a1);
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32(bool a1);
    virtual void vfunc_33(int a1);
    char m_pad04[0x1C];
    int m_Field20; // +0x20
    char m_pad24[0xC];
    int m_Field30; // +0x30
    char m_pad34[0x4];
    short m_Field38; // +0x38
    char m_pad3A[0x6];
    Field40* m_Field40; // +0x40
};
