// bin: xb
// va: 0x001AA990
// tool: the portal's starter code (no AI)
// sub_001AA990 (0x001AA990, 89 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    void sub_00098B90(int);
};

class Class_001AA990
{
public:
    void sub_001AA990(int a1, int a2, int a3, int a4, bool a5, bool a6, bool a7, int a8);
    char m_pad00[0x30];
    Field30 m_Field30; // +0x30
    char m_pad31[0xB];
    int m_Field3C; // +0x3C
    int m_Field40; // +0x40
    bool m_Field44; // +0x44
    unsigned char m_Field45; // +0x45
};

void Class_001AA990::sub_001AA990(int a1, int a2, int a3, int a4, bool a5, bool a6, bool a7, int a8)
{
    unsigned char t1;

    t1 = m_Field45;
    m_Field3C = a2;
    m_Field45 = (unsigned char)(m_Field45 ^ ((unsigned char)(((unsigned char)(t1 ^ a4)) & 1)));
    m_Field44 = a5;
    m_Field30.sub_00098B90(a1);
    m_Field40 = a8;
    m_Field45 = (unsigned char)(((unsigned char)(((unsigned char)(((unsigned char)(((unsigned char)(a7 & 1)) << 1)) | ((unsigned char)(a6 & 1)))) << 1)) | ((unsigned char)(m_Field45 & 249)));
}
