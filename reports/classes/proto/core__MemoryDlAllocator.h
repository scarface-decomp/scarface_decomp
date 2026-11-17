// core::MemoryDlAllocator (proto): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace core {
class MemoryDlAllocator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02();
    virtual MemoryDlAllocator* vfunc_03(int a1);
    char m_pad04[0x38];
    int m_Field3C; // +0x3C
};
}
