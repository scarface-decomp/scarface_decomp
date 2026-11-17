// bin: xb
// va: 0x000C3150
// tool: the portal's starter code (no AI)
// sub_000C3150 (0x000C3150, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003A00FC;
extern "C" float DAT_003A48F4;

class Class_000C3150
{
public:
    void sub_000C3150();
    char m_pad00[0x4];
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

void Class_000C3150::sub_000C3150()
{
    m_Field08 = m_Field04 * DAT_003A00FC;
    m_Field10 = m_Field0C * DAT_003A48F4;
}
