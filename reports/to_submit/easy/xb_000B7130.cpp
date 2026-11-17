// bin: xb
// va: 0x000B7130
// tool: the portal's starter code (no AI)
// VehiclePropellerBehaviour::vfunc_02 (0x000B7130, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_000880C0(int);
    void sub_00088420(int);
    void sub_00088C60(int);
};

class VehiclePropellerBehaviour
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    void sub_000B6940();
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
    char m_pad09[0x1F];
    float m_Field28; // +0x28
};

void VehiclePropellerBehaviour::vfunc_02()
{
    m_Field08.sub_000880C0(1);
    m_Field08.sub_00088420(0);
    m_Field08.sub_00088C60(0x3F800000);
    m_Field28 = 0.0f;
    sub_000B6940();
}
