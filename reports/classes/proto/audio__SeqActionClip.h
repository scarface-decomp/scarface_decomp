// audio::SeqActionClip (proto): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace audio {
class SeqActionClip
{
public:
    virtual SeqActionClip* vfunc_00(int a1);
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int a1);
    virtual void vfunc_04(int a1);
    void sub_0029E790(int, int);
    char m_pad04[0x14];
    int m_Field18; // +0x18
};
}
