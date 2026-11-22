// bin: proto
// va: 0x000B51D0
// what: 
// tool: the portal's starter code (no AI)

// sub_000B51D0 (Proto 0x000B51D0, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000B51D0
{
public:
    Class_000B51D0* sub_000B51D0();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    bool m_Field0C; // +0x0C
    bool m_Field0D; // +0x0D
    char m_pad0E[0x6];
    float m_Field14; // +0x14
};

Class_000B51D0* Class_000B51D0::sub_000B51D0()
{
    m_Field00 = 0.0f;
    m_Field04 = 0.0f;
    m_Field08 = 0.0f;
    m_Field0C = false;
    m_Field0D = false;
    m_Field14 = 0.0f;
    return this;
}
