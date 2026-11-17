// bin: proto
// va: 0x00135AE0
// tool: the portal's starter code (no AI)
// sub_00135AE0 (0x00135AE0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;
extern "C" char DAT_0039102C[];

class Class_00135AE0
{
public:
    Class_00135AE0* sub_00135AE0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    float m_Field0C; // +0x0C
};

Class_00135AE0* Class_00135AE0::sub_00135AE0()
{
    float t1;

    t1 = DAT_0037CE50;
    m_Field00 = (int)DAT_0039102C;
    m_Field04 = 0;
    m_Field08 = 0;
    m_Field0C = t1;
    return this;
}
