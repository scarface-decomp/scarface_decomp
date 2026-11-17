// bin: xb
// va: 0x000A6CC0
// tool: the portal's starter code (no AI)
// sub_000A6CC0 (0x000A6CC0, 75 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;
extern "C" float DAT_0039D664;

class Class_000A6CC0
{
public:
    Class_000A6CC0* sub_000A6CC0();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
    float m_Field24; // +0x24
    int m_Field28; // +0x28
};

Class_000A6CC0* Class_000A6CC0::sub_000A6CC0()
{
    float t1, t2;

    t1 = DAT_0039D664;
    t2 = DAT_0039D65C;
    m_Field00 = t1;
    m_Field04 = t1;
    m_Field08 = t1;
    m_Field0C = t1;
    m_Field10 = t1;
    m_Field14 = t1;
    m_Field18 = t1;
    m_Field1C = t1;
    m_Field20 = t2;
    m_Field24 = t1;
    m_Field28 = 0;
    return this;
}
