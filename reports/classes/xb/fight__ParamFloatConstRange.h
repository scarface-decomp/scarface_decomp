// fight::ParamFloatConstRange (xb): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace fight {
template <class T0> class ParamFloatConstRange
{
public:
    virtual ParamFloatConstRange<TimedFightTrack>* vfunc_00(int a1);
    virtual int vfunc_01();
    virtual bool vfunc_02(int a1, int a2);
};
}
