// AIConditionAnd (proto): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class Field08;
class Field0C;
class AIConditionAnd
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual AIConditionAnd* vfunc_03(int a1);
    virtual int vfunc_04();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    Field0C* m_Field0C; // +0x0C
};
