// core::FileRequest (xb): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace core {
class FileRequest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual bool vfunc_02(int a1);
    virtual int vfunc_03();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};
}
