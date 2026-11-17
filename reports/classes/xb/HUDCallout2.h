// HUDCallout2 (xb): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class HUDCallout2
{
public:
    virtual void* vfunc_00();
    virtual HUDCallout2* vfunc_01(int a1);
    void sub_00193F80();
    char m_pad04[0x64];
    int m_Field68; // +0x68
    int m_Field6C; // +0x6C
};
