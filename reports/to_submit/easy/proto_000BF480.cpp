// bin: proto
// va: 0x000BF480
// tool: the portal's starter code (no AI)
// sub_000BF480 (0x000BF480, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CD90;

class Class_000BF480
{
public:
    Class_000BF480* sub_000BF480();
    bool m_Field00; // +0x00
    char m_pad01[0x3];
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

Class_000BF480* Class_000BF480::sub_000BF480()
{
    m_Field04 = DAT_0037CD90;
    m_Field00 = false;
    m_Field08 = 0.0f;
    m_Field0C = 0.0f;
    m_Field10 = 0.0f;
    return this;
}
