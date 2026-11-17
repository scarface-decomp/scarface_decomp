// bin: proto
// va: 0x0009AF60
// tool: the portal's starter code (no AI)
// sub_0009AF60 (0x0009AF60, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE60;
extern "C" void __cdecl sub_0007D0F0(void);

class Class_0009AF60
{
public:
    Class_0009AF60* sub_0009AF60();
    char m_pad00[0x14];
    int m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
    float m_Field24; // +0x24
};

Class_0009AF60* Class_0009AF60::sub_0009AF60()
{
    sub_0007D0F0();
    m_Field18 = DAT_0037CE60;
    m_Field14 = 0;
    m_Field1C = 0.0f;
    m_Field20 = 0.0f;
    m_Field24 = 0.0f;
    return this;
}
