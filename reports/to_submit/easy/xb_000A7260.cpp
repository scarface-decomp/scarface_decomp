// bin: xb
// va: 0x000A7260
// tool: the portal's starter code (no AI)
// sub_000A7260 (0x000A7260, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003C7E40;

class Class_000A7260
{
public:
    Class_000A7260* sub_000A7260();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

Class_000A7260* Class_000A7260::sub_000A7260()
{
    float t1;

    t1 = DAT_003C7E40;
    m_Field0C = 0;
    m_Field10 = t1;
    m_Field00 = 0;
    m_Field04 = 0;
    m_Field08 = 0;
    return this;
}
