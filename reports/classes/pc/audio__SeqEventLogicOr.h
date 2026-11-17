// audio::SeqEventLogicOr (pc): one declaration merged from its matched functions.
// Proven for 4 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace audio {
class SeqEventLogicOr
{
public:
    virtual int vfunc_00(int a1);
    virtual int vfunc_01(int a1);
    virtual void vfunc_02();
    virtual int vfunc_03();
    virtual SeqEventLogicOr* vfunc_04(int a1);
    bool sub_006F5A60(int);
    bool sub_006F5AC0(int);
    char m_pad04[0xC];
    int m_Field10; // +0x10
};
}
