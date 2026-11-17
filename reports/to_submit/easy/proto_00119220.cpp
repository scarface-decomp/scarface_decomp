// bin: proto
// va: 0x00119220
// tool: the portal's starter code (no AI)
// sub_00119220 (0x00119220, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038F83C[];

class Class_00119220
{
public:
    Class_00119220* sub_00119220(float a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
};

Class_00119220* Class_00119220::sub_00119220(float a1)
{
    m_Field08 = a1;
    m_Field04 = 15;
    m_Field00 = (int)DAT_0038F83C;
    m_Field0C = 0.0f;
    return this;
}
