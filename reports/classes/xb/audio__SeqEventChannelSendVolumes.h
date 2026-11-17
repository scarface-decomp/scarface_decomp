// audio::SeqEventChannelSendVolumes (xb): one declaration merged from its matched functions.
// Proven for 4 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace audio {
class SeqEventChannelSendVolumes
{
public:
    virtual int vfunc_00(int a1);
    virtual void vfunc_01();
    virtual void vfunc_02(int a1);
    virtual int vfunc_03();
    virtual SeqEventChannelSendVolumes* vfunc_04(int a1);
    char m_pad04[0x44];
    int m_Field48; // +0x48
    int m_Field4C; // +0x4C
};
}
