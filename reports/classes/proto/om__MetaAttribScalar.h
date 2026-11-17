// om::MetaAttribScalar (proto): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace om {
template <class T0> class MetaAttribScalar
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    char m_pad04[0x10];
    int m_Field14; // +0x14
    char m_pad18[0x6];
    bool m_Field1E; // +0x1E
    char m_pad1F[0x5];
    int m_Field24; // +0x24
    char m_pad28[0xC];
    int m_Field34; // +0x34
};
}
