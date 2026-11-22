// bin: pc
// va: 0x006F57E0
// what: 
// tool: the portal's starter code (no AI)

// audio::SeqActionChannelSendVolumes::vfunc_02 (PC 0x006F57E0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class SeqActionChannelSendVolumes
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual int vfunc_02(int a1, int a2);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

int SeqActionChannelSendVolumes::vfunc_02(int a1, int a2)
{
    if (m_Field0C != 1) {
        m_Field0C = 1;
    }
    return 1;
}

}
