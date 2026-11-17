// bin: xb
// va: 0x0009ACD0
// tool: the portal's starter code (no AI)
// sub_0009ACD0 (0x0009ACD0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003A00FC;

class Class_0009ACD0
{
public:
    void sub_0009ACD0();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
};

void Class_0009ACD0::sub_0009ACD0()
{
    m_Field00 = m_Field04 * DAT_003A00FC;
}
