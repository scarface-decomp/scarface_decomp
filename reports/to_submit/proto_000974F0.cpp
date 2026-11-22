// bin: proto
// va: 0x000974F0
// what: 
// tool: the portal's starter code (no AI)

// sub_000974F0 (Proto 0x000974F0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;

class Class_000974F0
{
public:
    Class_000974F0* sub_000974F0();
    float m_Field00; // +0x00
    bool m_Field04; // +0x04
    char m_pad05[0x3];
    float m_Field08; // +0x08
};

Class_000974F0* Class_000974F0::sub_000974F0()
{
    m_Field00 = DAT_0037CE50;
    m_Field04 = false;
    m_Field08 = 0.0f;
    return this;
}
