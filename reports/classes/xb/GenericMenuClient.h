// GenericMenuClient (xb): one declaration merged from its matched functions.
// Proven for 5 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class GenericMenuClient
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(bool a1, int a2);
    virtual void vfunc_03(bool a1, int a2);
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(bool a1, int a2);
    virtual int vfunc_07();
    virtual int vfunc_08(int a1);
    int m_Field04; // +0x04
    char m_pad08[0x20];
    int m_Field28; // +0x28
    char m_pad2C[0xC];
    int m_Field38; // +0x38
};
