// bin: proto
// va: 0x0009B070
// what: 
// tool: the portal's starter code (no AI)

// sub_0009B070 (Proto 0x0009B070, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE60;
extern "C" float DAT_00383ED4;

class Class_0009B070
{
public:
    Class_0009B070* sub_0009B070();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

Class_0009B070* Class_0009B070::sub_0009B070()
{
    float t2;

    m_Field00 = DAT_00383ED4;
    t2 = DAT_0037CE60;
    m_Field04 = t2;
    m_Field08 = 0.0f;
    m_Field0C = 0.0f;
    m_Field10 = t2;
    return this;
}
