// BehaviourAnimPulse (proto): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class Field04;
class BehaviourAnimPulse
{
public:
    virtual bool vfunc_00(int a1);
    virtual bool vfunc_01();
    virtual bool vfunc_02(bool a1);
    virtual void vfunc_03(int);
    virtual void vfunc_04();
    Field04* m_Field04; // +0x04
    char m_pad08[0x18];
    bool m_Field20; // +0x20
    char m_pad21[0x3];
    unsigned char m_Field24; // +0x24
};
