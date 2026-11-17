// bin: xb
// va: 0x002ED530
// tool: the portal's starter code (no AI)
// sub_002ED530 (0x002ED530, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" unsigned short DAT_00465168;

class Class_002ED530
{
public:
    void sub_002ED530(int a1);
    unsigned char m_Field00; // +0x00
    char m_pad01[0x7];
    unsigned short m_Field08; // +0x08
    char m_pad0A[0x42];
    int m_Field4C; // +0x4C
    int m_Field50; // +0x50
    int m_Field54; // +0x54
    char m_pad58[0x84];
    int m_FieldDC; // +0xDC
    char m_padE0[0x4];
    int m_FieldE4; // +0xE4
};

void Class_002ED530::sub_002ED530(int a1)
{
    unsigned char t1;
    unsigned short t2;

    m_Field4C = *(int*)a1;
    m_Field50 = *(int*)(a1 + 4);
    m_Field54 = *(int*)(a1 + 8);
    t1 = m_Field00;
    if (m_Field00 & 1) {
        t2 = DAT_00465168;
        m_Field00 = (unsigned char)(t1 & 254);
        m_FieldDC = 0;
        m_FieldE4 = 0;
        m_Field08 = t2;
    }
}
