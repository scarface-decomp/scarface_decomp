// audio::SeqEventVarVolumeRand (proto): one declaration merged from its matched functions.
// Proven for 4 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace audio {
class SeqEventVarVolumeRand
{
public:
    virtual int vfunc_00(int a1);
    virtual void vfunc_01(int a1);
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual int vfunc_05();
    virtual SeqEventVarVolumeRand* vfunc_06(int a1);
    char m_pad04[0x2C];
    int m_Field30; // +0x30
    int m_Field34; // +0x34
};
}
