// audio::SeqEventVarPitch (xb): one declaration merged from its matched functions.
// Proven for 4 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace audio {
class SeqEventVarPitch
{
public:
    virtual int vfunc_00(int a1);
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    virtual int vfunc_03();
    virtual SeqEventVarPitch* vfunc_04(int a1);
};
}
