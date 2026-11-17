// audio::SeqEventCondition (xb): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace audio {
class SeqEventCondition
{
public:
    virtual int vfunc_00(int a1);
    virtual int vfunc_01(int a1);
    virtual void vfunc_02();
    virtual int vfunc_03();
    bool sub_002D6D30(int);
    bool sub_002D6DA0(int);
};
}
