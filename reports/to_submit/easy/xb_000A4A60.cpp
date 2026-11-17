// bin: xb
// va: 0x000A4A60
// tool: the portal's starter code (no AI)
// sub_000A4A60 (0x000A4A60, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003A033C;
extern "C" float DAT_003A48F8;
extern "C" float DAT_003C7E40;
extern "C" float DAT_003CA880;

class Class_000A4A60
{
public:
    Class_000A4A60* sub_000A4A60();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

Class_000A4A60* Class_000A4A60::sub_000A4A60()
{
    float t1, t2, t4;

    t1 = DAT_003A033C;
    t2 = DAT_003C7E40;
    m_Field00 = t1;
    m_Field08 = t1;
    m_Field0C = DAT_003CA880;
    t4 = DAT_003A48F8;
    m_Field04 = t2;
    m_Field10 = t4;
    return this;
}
