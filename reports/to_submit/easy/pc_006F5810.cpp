// bin: pc
// va: 0x006F5810
// tool: the portal's starter code (no AI)
// audio::SeqActionChannelSendVolumes::vfunc_03 (0x006F5810, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class SeqActionChannelSendVolumes
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

int SeqActionChannelSendVolumes::vfunc_03(int a1)
{
    if (m_Field0C != 4) {
        m_Field0C = 4;
    }
    return 4;
}

}
