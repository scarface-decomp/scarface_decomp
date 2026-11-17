// FEP3DObject (proto): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class FEP3DObject
{
public:
    virtual void* vfunc_00();
    virtual FEP3DObject* vfunc_01(int a1);
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(unsigned char mode);
    void sub_00028C40(int a1);
    void sub_00029C00();
    char m_pad04[0x24];
    int m_Field28; // +0x28
    int m_Field2C; // +0x2C
};
