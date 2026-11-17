// audio::OmHalStream (proto): one declaration merged from its matched functions.
// Proven for 3 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace audio {
class OmHalStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual bool vfunc_08(int a1);
    virtual int vfunc_09(int a1);
    virtual void vfunc_10();
    char m_pad04[0x4];
    int m_Field08; // +0x08
    char m_pad0C[0x1A8];
    int m_Field1B4; // +0x1B4
};
}
