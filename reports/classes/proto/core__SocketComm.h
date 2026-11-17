// core::SocketComm (proto): one declaration merged from its matched functions.
// Proven for 4 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace core {
class SocketComm
{
public:
    virtual void vfunc_00(int a1, int a2);
    virtual bool vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void* vfunc_05();
    void sub_00280C50();
    char m_pad04[0xC];
    int m_Field10; // +0x10
    char m_pad14[0x10870];
    bool m_Field10884; // +0x10884
    char m_pad10885[0x3];
    int m_Field10888; // +0x10888
    int m_Field1088C; // +0x1088C
    unsigned short m_Field10890; // +0x10890
    bool m_Field10892; // +0x10892
    char m_pad10893[0x15];
    int m_Field108A8; // +0x108A8
};
}
