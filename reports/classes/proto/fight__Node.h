// fight::Node (proto): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace fight {
class Node
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual Node* vfunc_03(int a1);
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual bool vfunc_08();
    virtual bool vfunc_09();
    void sub_001F84E0();
    char m_pad04[0x28];
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
};
}
