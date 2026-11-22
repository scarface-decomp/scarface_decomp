// bin: proto
// va: 0x00119670
// what: 
// tool: the portal's starter code (no AI)

// sub_00119670 (Proto 0x00119670, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038FA10[];

class Class_00119670
{
public:
    Class_00119670* sub_00119670(float a1, float a2, float a3, float a4);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
};

Class_00119670* Class_00119670::sub_00119670(float a1, float a2, float a3, float a4)
{
    m_Field08 = a1;
    m_Field0C = a2;
    m_Field10 = a3;
    m_Field04 = 28;
    m_Field00 = (int)DAT_0038FA10;
    m_Field14 = a4;
    return this;
}
