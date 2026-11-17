// fight::ConditionFactoryTemplate (proto): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace fight {
template <class T0> class ConditionFactoryTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ConditionFactoryTemplate<AlertStatusCondition>* vfunc_03(int a1);
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07();
    void sub_001F7900();
};
}
