// bin: proto
// va: 0x00119080
// what: 
// tool: the portal's starter code (no AI)

// sub_00119080 (Proto 0x00119080, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038F788[];

class Class_00119080
{
public:
    Class_00119080* sub_00119080(int a1, float a2, bool a3);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    float m_Field0C; // +0x0C
    int m_Field10; // +0x10
    bool m_Field14; // +0x14
};

Class_00119080* Class_00119080::sub_00119080(int a1, float a2, bool a3)
{
    m_Field04 = 10;
    m_Field00 = (int)DAT_0038F788;
    m_Field08 = a1;
    m_Field0C = a2;
    m_Field10 = 0;
    m_Field14 = a3;
    return this;
}
