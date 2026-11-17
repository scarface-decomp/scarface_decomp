// ErrorHandlerHUD (xb): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class ErrorHandlerHUD
{
public:
    virtual void* vfunc_00();
    virtual ErrorHandlerHUD* vfunc_01(int a1);
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    char m_pad04[0x60];
    int m_Field64; // +0x64
    int m_Field68; // +0x68
};
