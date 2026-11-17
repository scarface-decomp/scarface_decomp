// bin: xb
// va: 0x001F8580
// tool: the portal's starter code (no AI)
// sub_001F8580 (0x001F8580, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;
extern "C" float DAT_003A49EC;

class Class_001F8580
{
public:
    Class_001F8580* sub_001F8580();
    char m_pad00[0x10];
    float m_Field10; // +0x10
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
};

Class_001F8580* Class_001F8580::sub_001F8580()
{
    float t1;

    t1 = DAT_0039D664;
    m_Field10 = t1;
    m_Field14 = t1;
    m_Field18 = t1;
    m_Field1C = DAT_003A49EC;
    return this;
}
