// bin: proto
// va: 0x002A28A0
// tool: the portal's starter code (no AI)
// audio::SeqActionChannelSends::vfunc_06 (0x002A28A0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00296A60(int);
};

namespace audio {

class SeqActionChannelSends
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06(int a1);
    int m_Field04; // +0x04
};

int SeqActionChannelSends::vfunc_06(int a1)
{
    int t2;

    t2 = ((Object*)*(int*)(a1 + 20))->sub_00296A60(m_Field04 + 304);
    *(int*)(t2 + 80) = m_Field04 + 48;
    return t2;
}

}
