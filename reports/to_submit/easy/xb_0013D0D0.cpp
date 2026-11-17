// bin: xb
// va: 0x0013D0D0
// tool: the portal's starter code (no AI)
// sub_0013D0D0 (0x0013D0D0, 91 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldCC
{
    void sub_00098B90(int);
};

class Class_0013D0D0
{
public:
    void sub_0013D0D0(int a1, int a2, int a3, float a4);
    char m_pad00[0xCC];
    FieldCC m_FieldCC; // +0xCC
    char m_padCD[0x3];
    int m_FieldD0; // +0xD0
    int m_FieldD4; // +0xD4
    int m_FieldD8; // +0xD8
    int m_FieldDC; // +0xDC
    float m_FieldE0; // +0xE0
    char m_padE4[0x8D];
    unsigned char m_Field171; // +0x171
};

void Class_0013D0D0::sub_0013D0D0(int a1, int a2, int a3, float a4)
{
    int t2;

    m_FieldCC.sub_00098B90(a1);
    t2 = m_Field171 & 159;
    m_FieldD0 = a2;
    m_FieldD4 = a3;
    m_FieldD8 = 1;
    m_FieldDC = 0;
    m_FieldE0 = a4;
    m_Field171 = (unsigned char)t2;
}
