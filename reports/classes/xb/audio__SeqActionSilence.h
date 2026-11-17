// audio::SeqActionSilence (xb): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace audio {
class SeqActionSilence
{
public:
    virtual SeqActionSilence* vfunc_00(int a1);
    virtual void vfunc_01(int a1);
    virtual void vfunc_02(int a1, bool a2);
    void sub_002D6A60(int, int);
    char m_pad04[0x10];
    int m_Field14; // +0x14
    char m_pad18[0x4];
    int m_Field1C; // +0x1C
};
}
