// bin: xb
// va: 0x000A6C40
// tool: the portal's starter code (no AI)
// sub_000A6C40 (0x000A6C40, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003A48F4;

class Class_000A6C40
{
public:
    void sub_000A6C40();
    char m_pad00[0x4];
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

void Class_000A6C40::sub_000A6C40()
{
    m_Field08 = m_Field04 * DAT_003A48F4;
}
