// bin: xb
// va: 0x000A33D0
// tool: the portal's starter code (no AI)
// sub_000A33D0 (0x000A33D0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;

class Class_000A33D0
{
public:
    Class_000A33D0* sub_000A33D0();
    bool m_Field00; // +0x00
    bool m_Field01; // +0x01
    char m_pad02[0x2];
    float m_Field04; // +0x04
};

Class_000A33D0* Class_000A33D0::sub_000A33D0()
{
    float t1;

    t1 = DAT_0039D65C;
    m_Field00 = true;
    m_Field01 = true;
    m_Field04 = t1;
    return this;
}
