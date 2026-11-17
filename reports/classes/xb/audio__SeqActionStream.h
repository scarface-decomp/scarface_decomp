// audio::SeqActionStream (xb): one declaration merged from its matched functions.
// Proven for 2 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace audio {
class SeqActionStream
{
public:
    virtual SeqActionStream* vfunc_00(int a1);
    virtual void vfunc_01();
    virtual int vfunc_02(int a1, bool a2);
    char m_pad04[0x10];
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    char m_pad20[0x8];
    int m_Field28; // +0x28
};
}
