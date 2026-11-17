// pure3d::d3dDevice (xb): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class d3dDevice
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual d3dDevice* vfunc_03(int a1);
    virtual void vfunc_04();
    virtual int vfunc_05(int a1);
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};
}
