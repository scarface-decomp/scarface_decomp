// bin: xb
// va: 0x0014BC00
// tool: the portal's starter code (no AI)
// sub_0014BC00 (0x0014BC00, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003A6124;
extern "C" float DAT_003AB334;

class Class_0014BC00
{
public:
    Class_0014BC00* sub_0014BC00();
    int m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    bool m_Field1C; // +0x1C
};

Class_0014BC00* Class_0014BC00::sub_0014BC00()
{
    float t1, t2;

    t1 = DAT_003AB334;
    m_Field00 = 0;
    m_Field04 = t1;
    m_Field08 = t1;
    t2 = DAT_003A6124;
    m_Field0C = t2;
    m_Field10 = t2;
    m_Field14 = 0;
    m_Field18 = 0;
    m_Field1C = false;
    return this;
}
