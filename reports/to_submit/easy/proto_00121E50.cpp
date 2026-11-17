// bin: proto
// va: 0x00121E50
// tool: the portal's starter code (no AI)
// sub_00121E50 (0x00121E50, 91 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldE0
{
    void sub_0008D4C0(int);
};

class Class_00121E50
{
public:
    void sub_00121E50(int a1, int a2, int a3, float a4);
    char m_pad00[0xE0];
    FieldE0 m_FieldE0; // +0xE0
    char m_padE1[0x3];
    int m_FieldE4; // +0xE4
    int m_FieldE8; // +0xE8
    int m_FieldEC; // +0xEC
    int m_FieldF0; // +0xF0
    float m_FieldF4; // +0xF4
    char m_padF8[0x79];
    unsigned char m_Field171; // +0x171
};

void Class_00121E50::sub_00121E50(int a1, int a2, int a3, float a4)
{
    int t2;

    m_FieldE0.sub_0008D4C0(a1);
    t2 = m_Field171 & 159;
    m_FieldE4 = a2;
    m_FieldE8 = a3;
    m_FieldEC = 1;
    m_FieldF0 = 0;
    m_FieldF4 = a4;
    m_Field171 = (unsigned char)t2;
}
