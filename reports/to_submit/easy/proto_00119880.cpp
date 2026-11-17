// bin: proto
// va: 0x00119880
// tool: the portal's starter code (no AI)
// sub_00119880 (0x00119880, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038FB0C[];

class Class_00119880
{
public:
    Class_00119880* sub_00119880(float a1, float a2);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

Class_00119880* Class_00119880::sub_00119880(float a1, float a2)
{
    m_Field08 = a1;
    m_Field0C = a2;
    m_Field04 = 35;
    m_Field00 = (int)DAT_0038FB0C;
    m_Field10 = 0.0f;
    return this;
}
