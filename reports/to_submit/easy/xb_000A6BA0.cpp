// bin: xb
// va: 0x000A6BA0
// tool: the portal's starter code (no AI)
// sub_000A6BA0 (0x000A6BA0, 84 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_002EEB20();
};

extern "C" float DAT_0039D664;
extern "C" float DAT_0039D684;
extern "C" float DAT_003A4C6C;
extern "C" float DAT_003A4C70;
extern "C" int DAT_003E1B08;
extern "C" int __stdcall sub_002EE720(int);

class Class_000A6BA0
{
public:
    Class_000A6BA0* sub_000A6BA0();
    int m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
};

Class_000A6BA0* Class_000A6BA0::sub_000A6BA0()
{
    float t4;

    m_Field04 = DAT_0039D684;
    m_Field08 = DAT_003A4C70;
    m_Field0C = DAT_003A4C6C;
    t4 = DAT_0039D664;
    m_Field10 = t4;
    m_Field14 = t4;
    m_Field00 = ((Object*)sub_002EE720(DAT_003E1B08))->sub_002EEB20();
    return this;
}
