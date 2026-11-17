// AICommands::Cmd_Skull (proto): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace AICommands {
class Cmd_Skull
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1, int a2);
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual bool vfunc_04(int a1, int a2);
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08(int a1, int a2, int a3);
    char m_pad04[0x4];
    bool m_Field08; // +0x08
};
}
