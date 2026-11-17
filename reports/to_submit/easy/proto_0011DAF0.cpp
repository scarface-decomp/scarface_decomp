// bin: proto
// va: 0x0011DAF0
// tool: the portal's starter code (no AI)
// sub_0011DAF0 (0x0011DAF0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038FF50[];

class Class_0011DAF0
{
public:
    Class_0011DAF0* sub_0011DAF0(int a1, float a2);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    float m_Field0C; // +0x0C
};

Class_0011DAF0* Class_0011DAF0::sub_0011DAF0(int a1, float a2)
{
    m_Field04 = 17;
    m_Field08 = a1;
    m_Field00 = (int)DAT_0038FF50;
    m_Field0C = a2;
    return this;
}
