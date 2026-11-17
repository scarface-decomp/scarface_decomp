// FightContext (proto): one declaration merged from its matched functions.
// Proven for 6 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class Field0C;
class Field10;
class FightContext
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual FightContext* vfunc_03(int a1);
    virtual int vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual int vfunc_08(int);
    virtual void vfunc_09(int a1);
    virtual void vfunc_10(int a1);
    virtual void vfunc_11(int a1);
    void sub_001F7E30();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
    Field10* m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};
