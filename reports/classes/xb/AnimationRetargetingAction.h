// AnimationRetargetingAction (xb): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class Field0C;
class AnimationRetargetingAction
{
public:
    virtual void vfunc_00();
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
    virtual int vfunc_14();
    virtual int vfunc_15(int a1);
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
    int m_Field10; // +0x10
    char m_pad14[0x8];
    int m_Field1C; // +0x1C
    char m_pad20[0x1C];
    int m_Field3C; // +0x3C
    char m_pad40[0x20];
    int m_Field60; // +0x60
    char m_pad64[0x9];
    bool m_Field6D; // +0x6D
    char m_pad6E[0x1];
    bool m_Field6F; // +0x6F
};
