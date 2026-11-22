// bin: proto
// va: 0x00119350
// what: 
// tool: the portal's starter code (no AI)

// sub_00119350 (Proto 0x00119350, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038F8A8[];

class Class_00119350
{
public:
    Class_00119350* sub_00119350(int a1, float a2, float a3);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
};

Class_00119350* Class_00119350::sub_00119350(int a1, float a2, float a3)
{
    m_Field0C = a2;
    m_Field04 = 18;
    m_Field00 = (int)DAT_0038F8A8;
    m_Field08 = a1;
    m_Field10 = a3;
    return this;
}
