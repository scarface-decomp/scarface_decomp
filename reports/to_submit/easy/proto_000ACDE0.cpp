// bin: proto
// va: 0x000ACDE0
// tool: the portal's starter code (no AI)
// sub_000ACDE0 (0x000ACDE0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE60;

class Class_000ACDE0
{
public:
    Class_000ACDE0* sub_000ACDE0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    float m_Field08; // +0x08
};

Class_000ACDE0* Class_000ACDE0::sub_000ACDE0()
{
    float t1;

    t1 = DAT_0037CE60;
    m_Field00 = 0;
    m_Field04 = 0;
    m_Field08 = t1;
    return this;
}
