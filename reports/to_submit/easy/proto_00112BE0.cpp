// bin: proto
// va: 0x00112BE0
// tool: the portal's starter code (no AI)
// AICommands::Cmd_PlayAnimation::vfunc_01 (0x00112BE0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace AICommands {

class Cmd_PlayAnimation
{
public:
    virtual void vfunc_00();
    virtual unsigned short vfunc_01(int a1, int a2);
    char m_pad04[0x10];
    unsigned short m_Field14; // +0x14
    unsigned short m_Field16; // +0x16
};

unsigned short Cmd_PlayAnimation::vfunc_01(int a1, int a2)
{
    unsigned short t1;

    t1 = m_Field14;
    m_Field16 = m_Field14;
    return t1;
}

}
