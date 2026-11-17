// bin: proto
// va: 0x000AB9E0
// tool: the portal's starter code (no AI)
// sub_000AB9E0 (0x000AB9E0, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE60;

class Class_000AB9E0
{
public:
    Class_000AB9E0* sub_000AB9E0();
    bool m_Field00; // +0x00
    char m_pad01[0x3];
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    bool m_Field0C; // +0x0C
};

Class_000AB9E0* Class_000AB9E0::sub_000AB9E0()
{
    float t1;

    m_Field04 = 0.0f;
    t1 = DAT_0037CE60;
    m_Field00 = false;
    m_Field08 = t1;
    m_Field0C = false;
    return this;
}
