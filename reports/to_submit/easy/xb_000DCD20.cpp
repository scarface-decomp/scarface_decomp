// bin: xb
// va: 0x000DCD20
// tool: the portal's starter code (no AI)
// sub_000DCD20 (0x000DCD20, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;
extern "C" float DAT_003A645C;
extern "C" float DAT_003CA880;

class Class_000DCD20
{
public:
    Class_000DCD20* sub_000DCD20();
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
    int m_Field28; // +0x28
};

Class_000DCD20* Class_000DCD20::sub_000DCD20()
{
    float t2;

    m_Field00 = 0.0f;
    m_Field04 = 0.0f;
    m_Field08 = 0.0f;
    m_Field28 = 0;
    m_Field0C = 0.0f;
    m_Field10 = 0.0f;
    m_Field14 = 0.0f;
    m_Field18 = DAT_0039D664;
    t2 = DAT_003CA880;
    m_Field1C = t2;
    m_Field20 = t2;
    m_Field24 = DAT_003A645C;
    return this;
}
