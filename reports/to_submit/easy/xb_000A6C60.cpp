// bin: xb
// va: 0x000A6C60
// tool: the portal's starter code (no AI)
// sub_000A6C60 (0x000A6C60, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;
extern "C" float DAT_003D1058;

class Class_000A6C60
{
public:
    Class_000A6C60* sub_000A6C60();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
};

Class_000A6C60* Class_000A6C60::sub_000A6C60()
{
    float t1, t2;

    t1 = DAT_003D1058;
    m_Field00 = t1;
    m_Field04 = t1;
    t2 = DAT_0039D664;
    m_Field08 = t2;
    m_Field0C = t2;
    m_Field10 = t2;
    m_Field14 = t2;
    return this;
}
