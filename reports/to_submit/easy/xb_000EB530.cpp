// bin: xb
// va: 0x000EB530
// tool: the portal's starter code (no AI)
// sub_000EB530 (0x000EB530, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000EB530
{
public:
    Class_000EB530* sub_000EB530(int a1, int a2);
    void sub_000EB430(int, int);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
    int m_Field20; // +0x20
    int m_Field24; // +0x24
};

Class_000EB530* Class_000EB530::sub_000EB530(int a1, int a2)
{
    m_Field00 = 0;
    m_Field04 = 0;
    m_Field08 = 0.0f;
    m_Field0C = 0.0f;
    m_Field10 = 0;
    m_Field14 = 0;
    m_Field18 = 0.0f;
    m_Field1C = 0.0f;
    m_Field20 = 0;
    m_Field24 = 0;
    if (a1) {
        sub_000EB430(a1, a2);
    }
    return this;
}
