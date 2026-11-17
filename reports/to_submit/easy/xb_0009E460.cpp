// bin: xb
// va: 0x0009E460
// tool: the portal's starter code (no AI)
// sub_0009E460 (0x0009E460, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;
extern "C" float DAT_0039D664;
extern "C" float DAT_003A4A08;

class Class_0009E460
{
public:
    Class_0009E460* sub_0009E460();
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
};

Class_0009E460* Class_0009E460::sub_0009E460()
{
    float t1, t2, t3;

    t1 = DAT_003A4A08;
    t2 = DAT_0039D65C;
    m_Field00 = t1;
    m_Field08 = t1;
    t3 = DAT_0039D664;
    m_Field04 = t2;
    m_Field0C = t2;
    m_Field10 = t3;
    m_Field14 = t3;
    m_Field18 = t3;
    m_Field1C = t3;
    return this;
}
