// bin: proto
// va: 0x00119300
// tool: the portal's starter code (no AI)
// sub_00119300 (0x00119300, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038F884[];

class Class_00119300
{
public:
    Class_00119300* sub_00119300(float a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
};

Class_00119300* Class_00119300::sub_00119300(float a1)
{
    m_Field08 = a1;
    m_Field04 = 17;
    m_Field00 = (int)DAT_0038F884;
    m_Field0C = 0.0f;
    return this;
}
