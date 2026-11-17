// bin: proto
// va: 0x0009AD70
// tool: the portal's starter code (no AI)
// sub_0009AD70 (0x0009AD70, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_00384640;

class Class_0009AD70
{
public:
    void sub_0009AD70();
    char m_pad00[0x4];
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

void Class_0009AD70::sub_0009AD70()
{
    m_Field08 = m_Field04 * DAT_00384640;
}
