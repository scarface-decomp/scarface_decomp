// bin: proto
// va: 0x0008F500
// tool: the portal's starter code (no AI)
// sub_0008F500 (0x0008F500, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037F534;

class Class_0008F500
{
public:
    void sub_0008F500();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
};

void Class_0008F500::sub_0008F500()
{
    m_Field00 = m_Field04 * DAT_0037F534;
}
