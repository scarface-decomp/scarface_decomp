// bin: proto
// va: 0x00119750
// what: 
// tool: the portal's starter code (no AI)

// sub_00119750 (Proto 0x00119750, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038FA7C[];

class Class_00119750
{
public:
    Class_00119750* sub_00119750(float a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    float m_Field08; // +0x08
};

Class_00119750* Class_00119750::sub_00119750(float a1)
{
    m_Field04 = 31;
    m_Field00 = (int)DAT_0038FA7C;
    m_Field08 = a1;
    return this;
}
