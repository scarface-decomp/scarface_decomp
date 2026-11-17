// bin: proto
// va: 0x000B5830
// tool: the portal's starter code (no AI)
// sub_000B5830 (0x000B5830, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037F534;
extern "C" float DAT_00384640;

class Class_000B5830
{
public:
    void sub_000B5830();
    char m_pad00[0x4];
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

void Class_000B5830::sub_000B5830()
{
    m_Field08 = m_Field04 * DAT_0037F534;
    m_Field10 = m_Field0C * DAT_00384640;
}
