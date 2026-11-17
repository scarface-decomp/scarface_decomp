// bin: proto
// va: 0x00112740
// tool: the portal's starter code (no AI)
// AICommands::Cmd_EnterVehicle::vfunc_05 (0x00112740, 77 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000F6300(int);
    void sub_000F6420(int);
    bool sub_000F6970();
};

extern "C" char DAT_00402654[];
extern "C" char DAT_00403010[];
extern "C" int __cdecl sub_002C92F8(int, int, int, int, int);

namespace AICommands {

class Cmd_EnterVehicle
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual bool vfunc_05(int a1, int a2, int a3);
    char m_pad04[0x4];
    int m_Field08; // +0x08
    char m_Field0C; // +0x0C
};

bool Cmd_EnterVehicle::vfunc_05(int a1, int a2, int a3)
{
    if (sub_002C92F8(a3, 0, (int)DAT_00402654, (int)DAT_00403010, 0)) {
        ((Object*)a3)->sub_000F6420(m_Field08);
        ((Object*)a3)->sub_000F6300(m_Field0C);
        return ((Object*)a3)->sub_000F6970();
    }
    return true;
}

}
