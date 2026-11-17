// core::CompletionEventRequest (xb): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace core {
class CompletionEventRequest
{
public:
    virtual CompletionEventRequest* vfunc_00(int a1);
    virtual int vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06();
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};
}
