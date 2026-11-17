// SniperState (proto): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class SniperState
{
public:
    virtual void* vfunc_00();
    virtual SniperState* vfunc_01(int a1);
    char m_pad04[0x30];
    int m_Field34; // +0x34
};
