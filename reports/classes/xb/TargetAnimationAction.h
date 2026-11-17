// TargetAnimationAction (xb): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class Field08;
class Field0C;
class Field14;
class Field18;
class TargetAnimationAction
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
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    Field0C* m_Field0C; // +0x0C
    char m_pad10[0x4];
    Field14* m_Field14; // +0x14
    Field18* m_Field18; // +0x18
};
