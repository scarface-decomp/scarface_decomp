// bin: xb
// va: 0x000B7E90
// tool: the portal's starter code (no AI)
// sub_000B7E90 (0x000B7E90, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;

class Class_000B7E90
{
public:
    void sub_000B7E90();
    bool m_Field00; // +0x00
    char m_pad01[0x3];
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    bool m_Field0C; // +0x0C
};

void Class_000B7E90::sub_000B7E90()
{
    float t1;

    m_Field04 = 0.0f;
    t1 = DAT_0039D65C;
    m_Field00 = false;
    m_Field08 = t1;
    m_Field0C = false;
}
