// bin: xb
// va: 0x0009ACF0
// tool: the portal's starter code (no AI)
// sub_0009ACF0 (0x0009ACF0, 83 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;
extern "C" void __cdecl sub_000A8FB0(void);

class Class_0009ACF0
{
public:
    Class_0009ACF0* sub_0009ACF0();
    char m_pad00[0x14];
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
    float m_Field24; // +0x24
    float m_Field28; // +0x28
    float m_Field2C; // +0x2C
    float m_Field30; // +0x30
    float m_Field34; // +0x34
    float m_Field38; // +0x38
    float m_Field3C; // +0x3C
    float m_Field40; // +0x40
};

Class_0009ACF0* Class_0009ACF0::sub_0009ACF0()
{
    float t2;

    sub_000A8FB0();
    t2 = DAT_0039D664;
    m_Field14 = t2;
    m_Field18 = t2;
    m_Field1C = t2;
    m_Field20 = t2;
    m_Field24 = t2;
    m_Field28 = t2;
    m_Field2C = 0.0f;
    m_Field30 = 0.0f;
    m_Field34 = 0.0f;
    m_Field38 = 0.0f;
    m_Field3C = 0.0f;
    m_Field40 = 0.0f;
    return this;
}
