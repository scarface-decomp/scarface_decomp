// TapeMixTape (proto): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class TapeMixTape
{
public:
    virtual void* vfunc_00();
    virtual TapeMixTape* vfunc_01(int a1);
    virtual void vfunc_02();
    virtual int vfunc_03();
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};
