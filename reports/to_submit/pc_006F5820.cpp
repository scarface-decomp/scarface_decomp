// bin: pc
// va: 0x006F5820
// what: 
// tool: the portal's starter code (no AI)

// audio::SeqActionChannelSendVolumes::vfunc_04 (PC 0x006F5820, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace audio {

class SeqActionChannelSendVolumes
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04(int a1);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
};

int SeqActionChannelSendVolumes::vfunc_04(int a1)
{
    if (m_Field0C != 5) {
        m_Field0C = 5;
    }
    return 5;
}

}
