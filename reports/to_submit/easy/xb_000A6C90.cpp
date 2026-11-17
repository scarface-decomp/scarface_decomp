// bin: xb
// va: 0x000A6C90
// tool: the portal's starter code (no AI)
// sub_000A6C90 (0x000A6C90, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039DD44;
extern "C" float DAT_003D1C94;

class Class_000A6C90
{
public:
    Class_000A6C90* sub_000A6C90();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
};

Class_000A6C90* Class_000A6C90::sub_000A6C90()
{
    float t2;

    m_Field08 = DAT_0039DD44;
    t2 = DAT_003D1C94;
    m_Field00 = 0;
    m_Field04 = 0;
    m_Field0C = t2;
    return this;
}
