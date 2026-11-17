// audio::WmaDecoderStream (xb): one declaration merged from its matched functions.
// Proven for 4 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace audio {
class WmaDecoderStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void* vfunc_02();
    virtual int vfunc_03();
    virtual int vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int, int, int);
    virtual int vfunc_07(int a1, int a2, int a3);
    virtual bool vfunc_08(int);
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    char m_pad04[0x5C];
    int m_Field60; // +0x60
    int m_Field64; // +0x64
    char m_pad68[0x4];
    int m_Field6C; // +0x6C
};
}
