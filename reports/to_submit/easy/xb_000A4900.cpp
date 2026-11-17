// bin: xb
// va: 0x000A4900
// tool: the portal's starter code (no AI)
// sub_000A4900 (0x000A4900, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003A00FC;

class Class_000A4900
{
public:
    void sub_000A4900();
    char m_pad00[0xC];
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

void Class_000A4900::sub_000A4900()
{
    m_Field10 = m_Field0C * DAT_003A00FC;
}
