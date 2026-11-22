// bin: proto
// va: 0x000B26C0
// what: 
// tool: the portal's starter code (no AI)

// sub_000B26C0 (Proto 0x000B26C0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;

class Class_000B26C0
{
public:
    Class_000B26C0* sub_000B26C0();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

Class_000B26C0* Class_000B26C0::sub_000B26C0()
{
    float t1;

    t1 = DAT_0037CE50;
    m_Field00 = t1;
    m_Field04 = t1;
    m_Field08 = t1;
    m_Field0C = t1;
    m_Field10 = t1;
    return this;
}
