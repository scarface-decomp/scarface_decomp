// pure3d::OptimizedSpriteParticleEmitterHandler (proto): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class OptimizedSpriteParticleEmitterHandler
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual OptimizedSpriteParticleEmitterHandler* vfunc_03(int a1);
    virtual void vfunc_04();
    virtual void vfunc_05(int a1, int a2, int a3, int a4);
    void sub_00223A40(int, int, int, int);
};
}
