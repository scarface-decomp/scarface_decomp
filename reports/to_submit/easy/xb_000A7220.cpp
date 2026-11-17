// bin: xb
// va: 0x000A7220
// tool: the portal's starter code (no AI)
// sub_000A7220 (0x000A7220, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003A4AC8;
extern "C" float DAT_003A4C7C;
extern "C" float DAT_003D1C98;

class Class_000A7220
{
public:
    Class_000A7220* sub_000A7220();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

Class_000A7220* Class_000A7220::sub_000A7220()
{
    m_Field00 = DAT_003A4AC8;
    m_Field04 = DAT_003D1C98;
    m_Field08 = DAT_003A4C7C;
    return this;
}
