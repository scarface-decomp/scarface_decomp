// bin: pc
// va: 0x006F57F0
// tool: the portal's starter code (no AI)
// audio::SeqActionChannelSendVolumes::vfunc_01 (0x006F57F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class SeqActionChannelSendVolumes
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(int a1);
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

void SeqActionChannelSendVolumes::vfunc_01(int a1)
{
    vfunc_06(a1);
    if (m_Field0C) {
        m_Field0C = 0;
    }
}

}
