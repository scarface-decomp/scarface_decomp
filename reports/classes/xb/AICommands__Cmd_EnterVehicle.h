// AICommands::Cmd_EnterVehicle (xb): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace AICommands {
class Cmd_EnterVehicle
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04(int a1, int a2);
    virtual bool vfunc_05(int a1, int a2, int a3);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    char m_Field0C; // +0x0C
};
}
