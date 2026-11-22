// bin: proto
// va: 0x000B5BD0
// what: 
// tool: the portal's starter code (no AI)

// sub_000B5BD0 (Proto 0x000B5BD0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE60;

class Class_000B5BD0
{
public:
    Class_000B5BD0* sub_000B5BD0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
    int m_Field18; // +0x18
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
};

Class_000B5BD0* Class_000B5BD0::sub_000B5BD0()
{
    float t1;

    t1 = DAT_0037CE60;
    m_Field00 = 0;
    m_Field04 = 0;
    m_Field08 = 0;
    m_Field0C = 0;
    m_Field10 = t1;
    m_Field14 = 0.0f;
    m_Field18 = 0;
    m_Field1C = t1;
    m_Field20 = 0.0f;
    return this;
}
