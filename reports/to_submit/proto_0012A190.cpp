// bin: proto
// va: 0x0012A190
// what: 
// tool: the portal's starter code (no AI)

// sub_0012A190 (Proto 0x0012A190, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00121DA0(float);
};

class Class_0012A190
{
public:
    void sub_0012A190(float a1);
    char m_pad00[0x28];
    int m_Field28; // +0x28
    char m_pad2C[0x18];
    float m_Field44; // +0x44
};

void Class_0012A190::sub_0012A190(float a1)
{
    int t1;

    m_Field44 = a1;
    t1 = m_Field28;
    if (m_Field28) {
        ((Object*)t1)->sub_00121DA0(a1);
        return;
    }
}
