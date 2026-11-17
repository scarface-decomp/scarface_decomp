// ravenphysics::BroadPhaseDetectorSweepAndPrune (proto): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace ravenphysics {
class BroadPhaseDetectorSweepAndPrune
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual BroadPhaseDetectorSweepAndPrune* vfunc_03(int a1);
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void* vfunc_07();
    virtual void* vfunc_08();
    char m_pad04[0x9C];
    int m_FieldA0; // +0xA0
    char m_padA4[0xC];
    int m_FieldB0; // +0xB0
};
}
