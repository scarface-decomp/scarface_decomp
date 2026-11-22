// bin: proto
// va: 0x000AAAF0
// what: 
// tool: the portal's starter code (no AI)

// sub_000AAAF0 (Proto 0x000AAAF0, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003845A4;

class Class_000AAAF0
{
public:
    Class_000AAAF0* sub_000AAAF0();
    float m_Field00; // +0x00
    int m_Field04; // +0x04
    bool m_Field08; // +0x08
    char m_pad09[0x3];
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    int m_Field28; // +0x28
};

Class_000AAAF0* Class_000AAAF0::sub_000AAAF0()
{
    m_Field00 = DAT_003845A4;
    m_Field04 = -1;
    m_Field08 = false;
    m_Field0C = 0.0f;
    m_Field10 = 0.0f;
    m_Field14 = 0;
    m_Field18 = 0;
    m_Field1C = 0;
    m_Field20 = 0;
    m_Field24 = 0;
    m_Field28 = 0;
    return this;
}
