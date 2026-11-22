// bin: proto
// va: 0x0007DC00
// what: 
// tool: the portal's starter code (no AI)

// sub_0007DC00 (Proto 0x0007DC00, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003834FC;

class Class_0007DC00
{
public:
    Class_0007DC00* sub_0007DC00();
    int m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

Class_0007DC00* Class_0007DC00::sub_0007DC00()
{
    m_Field04 = DAT_003834FC;
    m_Field00 = 0;
    m_Field08 = 0.0f;
    return this;
}
