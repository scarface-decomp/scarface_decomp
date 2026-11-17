// bin: xb
// va: 0x00120EA0
// tool: the portal's starter code (no AI)
// AIActionSetVehicleSpeedCap::vfunc_08 (0x00120EA0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_001655C0();
};

extern "C" int __cdecl sub_00106640(int);

class AIActionSetVehicleSpeedCap
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
    virtual int vfunc_08();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
};

int AIActionSetVehicleSpeedCap::vfunc_08()
{
    return sub_00106640(m_Field08->sub_001655C0());
}
