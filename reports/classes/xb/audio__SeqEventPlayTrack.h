// audio::SeqEventPlayTrack (xb): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace audio {
class SeqEventPlayTrack
{
public:
    virtual int vfunc_00(int a1);
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    virtual int vfunc_03();
    virtual SeqEventPlayTrack* vfunc_04(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};
}
