// pure3d::ParticleSphereGenerator (proto): one declaration merged from its matched functions.
// Proven for 4 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class ParticleSphereGenerator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ParticleSphereGenerator* vfunc_03(int a1);
    virtual void vfunc_04();
    virtual int vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual int vfunc_09(int a1, int a2);
    virtual void vfunc_10();
    virtual int vfunc_11();
    char m_pad04[0x34];
    int m_Field38; // +0x38
    int m_Field3C; // +0x3C
};
}
