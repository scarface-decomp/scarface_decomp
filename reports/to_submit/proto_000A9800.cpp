// bin: proto
// va: 0x000A9800
// what: 
// tool: the portal's starter code (no AI)

// VehiclePropellerBehaviour::vfunc_02 (Proto 0x000A9800, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_0007DC60(int);
    void sub_0007DFE0(int);
    void sub_0007E8A0(int);
};

class VehiclePropellerBehaviour
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    void sub_000A91D0();
    char m_pad04[0x4];
    Field08 m_Field08; // +0x08
    char m_pad09[0x1F];
    float m_Field28; // +0x28
};

void VehiclePropellerBehaviour::vfunc_02()
{
    m_Field08.sub_0007DC60(1);
    m_Field08.sub_0007DFE0(0);
    m_Field08.sub_0007E8A0(0x3F800000);
    m_Field28 = 0.0f;
    sub_000A91D0();
}
