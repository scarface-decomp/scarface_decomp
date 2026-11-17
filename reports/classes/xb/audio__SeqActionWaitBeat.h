// audio::SeqActionWaitBeat (xb): one declaration merged from its matched functions.
// Proven for 4 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace audio {
class SeqActionWaitBeat
{
public:
    virtual SeqActionWaitBeat* vfunc_00(int a1);
    virtual void vfunc_01();
    virtual void vfunc_02(int a1, int a2);
    virtual void vfunc_03(int a1);
    virtual void vfunc_04(int a1);
    void sub_002D6A60(int, int);
    int m_Field04; // +0x04
    char m_pad08[0xC];
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};
}
