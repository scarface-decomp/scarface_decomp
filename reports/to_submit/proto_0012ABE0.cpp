// bin: proto
// va: 0x0012ABE0
// what: 
// tool: the portal's starter code (no AI)

// sub_0012ABE0 (Proto 0x0012ABE0, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00390604[];

class Class_0012ABE0
{
public:
    Class_0012ABE0* sub_0012ABE0(int a1, int a2);
    void sub_00129E80(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x34];
    int m_Field38; // +0x38
    int m_Field3C; // +0x3C
    char m_pad40[0x4];
    float m_Field44; // +0x44
};

Class_0012ABE0* Class_0012ABE0::sub_0012ABE0(int a1, int a2)
{
    sub_00129E80(a1, a2);
    m_Field38 = 0;
    m_Field3C = 0;
    m_Field00 = (int)DAT_00390604;
    m_Field44 = 0.0f;
    return this;
}
