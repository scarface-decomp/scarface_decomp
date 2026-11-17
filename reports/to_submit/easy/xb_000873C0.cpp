// bin: xb
// va: 0x000873C0
// tool: the portal's starter code (no AI)
// sub_000873C0 (0x000873C0, 71 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003A3F00;
extern "C" float DAT_003C792C;

class Class_000873C0
{
public:
    Class_000873C0* sub_000873C0();
    bool m_Field00; // +0x00
    char m_pad01[0x3];
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    unsigned char m_Field28; // +0x28
};

Class_000873C0* Class_000873C0::sub_000873C0()
{
    float t1;
    int t2;

    m_Field00 = false;
    m_Field04 = 0;
    m_Field08 = 0;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field14 = 0.0f;
    t1 = DAT_003A3F00;
    m_Field20 = 0;
    m_Field24 = 0;
    t2 = m_Field28 & 253;
    m_Field18 = t1;
    m_Field1C = DAT_003C792C;
    m_Field28 = (unsigned char)(((unsigned char)t2) | 5);
    return this;
}
