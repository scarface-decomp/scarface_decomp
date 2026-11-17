// bin: xb
// va: 0x000A58E0
// tool: the portal's starter code (no AI)
// sub_000A58E0 (0x000A58E0, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;
extern "C" char DAT_003A4AF4[];

class Class_000A58E0
{
public:
    Class_000A58E0* sub_000A58E0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    bool m_Field08; // +0x08
    char m_pad09[0x3];
    int m_Field0C; // +0x0C
    bool m_Field10; // +0x10
    bool m_Field11; // +0x11
    char m_pad12[0x2];
    float m_Field14; // +0x14
    bool m_Field18; // +0x18
};

Class_000A58E0* Class_000A58E0::sub_000A58E0()
{
    float t1;

    t1 = DAT_0039D65C;
    m_Field04 = 0;
    m_Field08 = false;
    m_Field00 = (int)DAT_003A4AF4;
    m_Field0C = 0;
    m_Field10 = false;
    m_Field11 = false;
    m_Field14 = t1;
    m_Field18 = true;
    return this;
}
