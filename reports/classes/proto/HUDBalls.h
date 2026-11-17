// HUDBalls (proto): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class HUDBalls
{
public:
    virtual void* vfunc_00();
    virtual HUDBalls* vfunc_01(int a1);
    void sub_0016E130();
    char m_pad04[0x3C];
    int m_Field40; // +0x40
    int m_Field44; // +0x44
    char m_pad48[0x30];
    int m_Field78; // +0x78
};
