// bin: proto
// va: 0x000AAA00
// tool: the portal's starter code (no AI)
// sub_000AAA00 (0x000AAA00, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;
extern "C" float DAT_003845A4;

class Class_000AAA00
{
public:
    Class_000AAA00* sub_000AAA00();
    float m_Field00; // +0x00
    bool m_Field04; // +0x04
    char m_pad05[0x3];
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    int m_Field20; // +0x20
};

Class_000AAA00* Class_000AAA00::sub_000AAA00()
{
    float t2;

    m_Field00 = DAT_003845A4;
    m_Field08 = 0.0f;
    m_Field0C = 0.0f;
    t2 = DAT_0037CE50;
    m_Field04 = false;
    m_Field10 = t2;
    m_Field14 = 0;
    m_Field18 = 0;
    m_Field1C = 0;
    m_Field20 = 0;
    return this;
}
