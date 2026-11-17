// bin: xb
// va: 0x000481A0
// tool: the portal's starter code (no AI)
// sub_000481A0 (0x000481A0, 57 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;
extern "C" float DAT_0039DDE4;

class Class_000481A0
{
public:
    Class_000481A0* sub_000481A0();
    bool m_Field00; // +0x00
    char m_pad01[0x3];
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
};

Class_000481A0* Class_000481A0::sub_000481A0()
{
    m_Field14 = DAT_0039D664;
    m_Field18 = DAT_0039DDE4;
    m_Field04 = 128;
    m_Field08 = 128;
    m_Field0C = 128;
    m_Field10 = 128;
    m_Field00 = false;
    m_Field1C = 0.0f;
    return this;
}
