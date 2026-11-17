// FEP3DObject (xb): one declaration merged from its matched functions.
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
    virtual void vfunc_04(unsigned char mode);
    void sub_0002B700(int a1);
    void sub_0002C720();
    char m_pad04[0x28];
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
};
