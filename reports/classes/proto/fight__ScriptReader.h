// fight::ScriptReader (proto): one declaration merged from its matched functions.
// Proven for 5 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace fight {
class ScriptReader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ScriptReader* vfunc_03(int a1);
    virtual bool vfunc_04();
    virtual int vfunc_05();
    virtual int vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    char m_pad04[0x4];
    int m_Field08; // +0x08
    char m_pad0C[0x4];
    bool m_Field10; // +0x10
    char m_pad11[0x107];
    int m_Field118; // +0x118
    int m_Field11C; // +0x11C
    char m_pad120[0xFC];
    int m_Field21C; // +0x21C
    char m_pad220[0x100];
    bool m_Field320; // +0x320
};
}
