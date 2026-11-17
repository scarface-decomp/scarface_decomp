// SubtitleManager::SubtitleFlowClient (xb): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace SubtitleManager {
class SubtitleFlowClient
{
public:
    virtual SubtitleFlowClient* vfunc_00(int a1);
    virtual int vfunc_01(int a1, int a2);
    virtual void vfunc_02();
    virtual int vfunc_03(int a1, int a2);
    void sub_000CA860();
    void sub_000CAB70(int, int);
    void sub_000EA330();
};
}
