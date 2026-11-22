// bin: proto
// va: 0x0012A170
// what: 
// tool: the portal's starter code (no AI)

// sub_0012A170 (Proto 0x0012A170, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0012A170
{
public:
    void sub_0012A170(float a1);
    char m_pad00[0x28];
    int m_Field28; // +0x28
    char m_pad2C[0x14];
    float m_Field40; // +0x40
};

void Class_0012A170::sub_0012A170(float a1)
{
    int t1;

    m_Field40 = a1;
    t1 = m_Field28;
    if (m_Field28) {
        *(float*)(t1 + 40) = a1;
    }
}
