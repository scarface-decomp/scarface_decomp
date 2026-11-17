// BehaviourAnimPulse (xb): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class BehaviourAnimPulse
{
public:
    virtual bool vfunc_00(int a1);
    virtual bool vfunc_01();
    virtual bool vfunc_02(bool a1);
    virtual int vfunc_03();
    virtual void vfunc_04(int);
    virtual void vfunc_05();
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    char m_pad0C[0xC];
    int m_Field18; // +0x18
    char m_pad1C[0x10];
    bool m_Field2C; // +0x2C
    char m_pad2D[0x3];
    int m_Field30; // +0x30
};
