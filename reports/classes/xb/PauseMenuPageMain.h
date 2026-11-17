// PauseMenuPageMain (xb): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class PauseMenuPageMain
{
public:
    virtual void* vfunc_00();
    virtual PauseMenuPageMain* vfunc_01(int a1);
    char m_pad04[0x60];
    int m_Field64; // +0x64
    char m_pad68[0x14];
    int m_Field7C; // +0x7C
};
