// bin: proto
// va: 0x0012CED0
// tool: the portal's starter code (no AI)
// sub_0012CED0 (0x0012CED0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0012CED0
{
public:
    void sub_0012CED0(float a1);
    char m_pad00[0x2C];
    int m_Field2C; // +0x2C
    char m_pad30[0xC];
    float m_Field3C; // +0x3C
};

void Class_0012CED0::sub_0012CED0(float a1)
{
    int t1;

    m_Field3C = a1;
    t1 = m_Field2C;
    if (m_Field2C) {
        *(float*)(t1 + 40) = a1;
    }
}
