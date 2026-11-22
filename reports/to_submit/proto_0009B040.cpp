// bin: proto
// va: 0x0009B040
// what: 
// tool: the portal's starter code (no AI)

// sub_0009B040 (Proto 0x0009B040, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;
extern "C" float DAT_0037CE60;

class Class_0009B040
{
public:
    Class_0009B040* sub_0009B040();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

Class_0009B040* Class_0009B040::sub_0009B040()
{
    m_Field00 = DAT_0037CE60;
    m_Field04 = DAT_0037CE50;
    m_Field08 = 0.0f;
    m_Field0C = 0;
    return this;
}
