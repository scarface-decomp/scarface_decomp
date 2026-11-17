// pure3d::ParticlePlaneGenerator (proto): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class ParticlePlaneGenerator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ParticlePlaneGenerator* vfunc_03(int a1);
    virtual void vfunc_04();
    virtual int vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual int vfunc_11();
    char m_pad04[0x40];
    int m_Field44; // +0x44
    int m_Field48; // +0x48
    int m_Field4C; // +0x4C
    int m_Field50; // +0x50
    int m_Field54; // +0x54
};
}
