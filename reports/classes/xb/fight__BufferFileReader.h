// fight::BufferFileReader (xb): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace fight {
class BufferFileReader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
    virtual int vfunc_06(int a1);
    virtual bool vfunc_07();
    void sub_0023D8A0();
    char m_pad04[0xC];
    int m_Field10; // +0x10
    char m_pad14[0x4];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    int m_Field20; // +0x20
};
}
