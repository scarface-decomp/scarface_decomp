// bin: xb
// va: 0x000F1470
// tool: the portal's starter code (no AI)
// sub_000F1470 (0x000F1470, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field17C
{
    void sub_00087290(int);
    void sub_00087300();
    int sub_000CE360();
};

class Class_000F1470
{
public:
    void sub_000F1470();
    char m_pad00[0x104];
    float m_Field104; // +0x104
    float m_Field108; // +0x108
    float m_Field10C; // +0x10C
    char m_pad110[0x6C];
    Field17C m_Field17C; // +0x17C
};

void Class_000F1470::sub_000F1470()
{
    if (m_Field17C.sub_000CE360()) {
        m_Field17C.sub_00087290(0);
        m_Field17C.sub_00087300();
    }
    m_Field10C = 0.0f;
    m_Field108 = 0.0f;
    m_Field104 = 0.0f;
}
