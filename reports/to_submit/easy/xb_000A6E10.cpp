// bin: xb
// va: 0x000A6E10
// tool: the portal's starter code (no AI)
// sub_000A6E10 (0x000A6E10, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;
extern "C" void __cdecl sub_000875C0(void);

class Class_000A6E10
{
public:
    Class_000A6E10* sub_000A6E10();
    char m_pad00[0x14];
    int m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
    float m_Field24; // +0x24
};

Class_000A6E10* Class_000A6E10::sub_000A6E10()
{
    sub_000875C0();
    m_Field18 = DAT_0039D65C;
    m_Field14 = 0;
    m_Field1C = 0.0f;
    m_Field20 = 0.0f;
    m_Field24 = 0.0f;
    return this;
}
