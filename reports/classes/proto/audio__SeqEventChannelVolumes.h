// audio::SeqEventChannelVolumes (proto): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace audio {
class SeqEventChannelVolumes
{
public:
    virtual int vfunc_00(int a1);
    virtual int vfunc_01(int a1);
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
    char m_pad04[0x3C];
    int m_Field40; // +0x40
    int m_Field44; // +0x44
    int m_Field48; // +0x48
};
}
