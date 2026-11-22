// bin: proto
// va: 0x0009B360
// what: 
// tool: the portal's starter code (no AI)

// sub_0009B360 (Proto 0x0009B360, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003AB1D0;

class Class_0009B360
{
public:
    Class_0009B360* sub_0009B360();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

Class_0009B360* Class_0009B360::sub_0009B360()
{
    float t1;

    t1 = DAT_003AB1D0;
    m_Field0C = 0;
    m_Field10 = t1;
    m_Field00 = 0;
    m_Field04 = 0;
    m_Field08 = 0;
    return this;
}
