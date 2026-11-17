// core::CementLibrary (proto): one declaration merged from its matched functions.
// Proven for 6 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace core {
class CementLibrary
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual CementLibrary* vfunc_03(int a1);
    virtual void vfunc_04();
    virtual int vfunc_05();
    virtual void vfunc_06(int a1, int a2);
    virtual bool vfunc_07();
    virtual void vfunc_08(int, int, int, int, int, int);
    virtual void vfunc_09(int a1, int a2, int a3, int a4, int a5, int a6);
    char m_pad04[0x1C];
    int m_Field20; // +0x20
    char m_pad24[0x48];
    int m_Field6C; // +0x6C
    int m_Field70; // +0x70
};
}
