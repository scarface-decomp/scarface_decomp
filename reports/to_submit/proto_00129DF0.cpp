// bin: proto
// va: 0x00129DF0
// what: 
// tool: the portal's starter code (no AI)

// sub_00129DF0 (Proto 0x00129DF0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00129DF0
{
public:
    int sub_00129DF0(float a1);
    char m_pad00[0x28];
    int m_Field28; // +0x28
    char m_pad2C[0x4];
    float m_Field30; // +0x30
};

int Class_00129DF0::sub_00129DF0(float a1)
{
    int t1;

    t1 = m_Field28;
    m_Field30 = a1;
    *(float*)(t1 + 40) = a1;
    return t1;
}
