// bin: proto
// va: 0x0008F630
// tool: the portal's starter code (no AI)
// sub_0008F630 (0x0008F630, 73 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;

class Class_0008F630
{
public:
    Class_0008F630* sub_0008F630();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
    float m_Field24; // +0x24
    float m_Field28; // +0x28
    float m_Field2C; // +0x2C
};

Class_0008F630* Class_0008F630::sub_0008F630()
{
    float t1;

    t1 = DAT_0037CE50;
    m_Field00 = t1;
    m_Field04 = t1;
    m_Field08 = t1;
    m_Field0C = t1;
    m_Field10 = t1;
    m_Field14 = t1;
    m_Field18 = 0.0f;
    m_Field1C = 0.0f;
    m_Field20 = 0.0f;
    m_Field24 = 0.0f;
    m_Field28 = 0.0f;
    m_Field2C = 0.0f;
    return this;
}
