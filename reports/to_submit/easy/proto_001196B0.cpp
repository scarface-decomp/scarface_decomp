// bin: proto
// va: 0x001196B0
// tool: the portal's starter code (no AI)
// sub_001196B0 (0x001196B0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038FA34[];

class Class_001196B0
{
public:
    Class_001196B0* sub_001196B0(float a1, float a2);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
};

Class_001196B0* Class_001196B0::sub_001196B0(float a1, float a2)
{
    m_Field08 = a1;
    m_Field04 = 29;
    m_Field00 = (int)DAT_0038FA34;
    m_Field0C = a2;
    return this;
}
