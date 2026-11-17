// NISCharacterAttachAction (xb): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class NISCharacterAttachAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual NISCharacterAttachAction* vfunc_03(int a1);
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int a1);
    void sub_000217F0();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};
