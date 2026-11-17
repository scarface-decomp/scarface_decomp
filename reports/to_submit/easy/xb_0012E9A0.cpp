// bin: xb
// va: 0x0012E9A0
// tool: the portal's starter code (no AI)
// AICommands::Cmd_FollowActor::vfunc_07 (0x0012E9A0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

namespace AICommands {

class Cmd_FollowActor
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07(int a1, int a2, int a3);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

int Cmd_FollowActor::vfunc_07(int a1, int a2, int a3)
{
    return sub_0002AC90(m_Field08) != 0;
}

}
