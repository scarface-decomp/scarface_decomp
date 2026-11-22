// bin: proto
// va: 0x00112BF0
// what: 
// tool: the portal's starter code (no AI)

// AICommands::Cmd_PlayAnimation::vfunc_04 (Proto 0x00112BF0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace AICommands {

class Cmd_PlayAnimation
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04(int a1, int a2);
    char m_pad04[0x12];
    unsigned short m_Field16; // +0x16
};

int Cmd_PlayAnimation::vfunc_04(int a1, int a2)
{
    return !m_Field16;
}

}
