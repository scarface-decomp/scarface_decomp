// audio::SeqEventChannelSendVolumes (proto): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace audio {
class SeqEventChannelSendVolumes
{
public:
    virtual int vfunc_00(int a1);
    virtual int vfunc_01(int a1);
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
    char m_pad04[0x6C];
    int m_Field70; // +0x70
    int m_Field74; // +0x74
    int m_Field78; // +0x78
};
}
