// bin: xb
// va: 0x000C30C0
// tool: the portal's starter code (no AI)
// sub_000C30C0 (0x000C30C0, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D580;
extern "C" float DAT_0039D664;
extern "C" float DAT_003A007C;
extern "C" float DAT_003CA880;

class Class_000C30C0
{
public:
    Class_000C30C0* sub_000C30C0();
    int m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
};

Class_000C30C0* Class_000C30C0::sub_000C30C0()
{
    float t2, t4;

    m_Field04 = DAT_0039D664;
    t2 = DAT_0039D580;
    m_Field08 = t2;
    m_Field0C = t2;
    m_Field10 = DAT_003A007C;
    t4 = DAT_003CA880;
    m_Field00 = 0;
    m_Field14 = t4;
    return this;
}
