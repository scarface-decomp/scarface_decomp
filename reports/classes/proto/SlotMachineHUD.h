// SlotMachineHUD (proto): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

class SlotMachineHUD
{
public:
    virtual void vfunc_00(int a1, int a2);
    virtual SlotMachineHUD* vfunc_01(int a1);
    void sub_00181390();
    char m_pad04[0x30];
    int m_Field34; // +0x34
    char m_pad38[0x20];
    int m_Field58; // +0x58
};
