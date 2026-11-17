// pure3d::d3dExtVertexProgram (xb): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class d3dExtVertexProgram
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05(int a1, int a2);
    virtual int vfunc_06(int a1);
    virtual void vfunc_07();
    virtual void vfunc_08(int a1, int a2);
    int m_Field04; // +0x04
};
}
