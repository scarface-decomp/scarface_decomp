// bin: xb
// va: 0x0009E9B0
// tool: the portal's starter code (no AI)
// sub_0009E9B0 (0x0009E9B0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003A00FC;

class Class_0009E9B0
{
public:
    void sub_0009E9B0();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    char m_pad08[0x4];
    float m_Field0C; // +0x0C
};

void Class_0009E9B0::sub_0009E9B0()
{
    float t1;

    t1 = DAT_003A00FC;
    m_Field04 = m_Field00 * t1;
    m_Field0C = m_Field0C * t1;
}
