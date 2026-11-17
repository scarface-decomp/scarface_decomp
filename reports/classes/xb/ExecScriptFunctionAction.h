// ExecScriptFunctionAction (xb): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class Child;
class ExecScriptFunctionAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ExecScriptFunctionAction* vfunc_03(unsigned int flags);
    virtual bool vfunc_04();
    void sub_000217F0();
    void* m_vtable_unused; // +0x04
    Child* m_child; // +0x08
    char m_pad0C[0x4];
    bool m_Field10; // +0x10
};
