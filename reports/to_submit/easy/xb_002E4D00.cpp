// bin: xb
// va: 0x002E4D00
// tool: the portal's starter code (no AI)
// sub_002E4D00 (0x002E4D00, 82 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_002E4D00
{
public:
    void sub_002E4D00();
    int sub_002E44C0(int, int);
    void sub_002E4900();
    char m_pad00[0x24];
    int m_Field24; // +0x24
    char m_pad28[0x4];
    int m_Field2C; // +0x2C
    unsigned short m_Field30; // +0x30
    unsigned short m_Field32; // +0x32
    unsigned char m_Field34; // +0x34
};

void Class_002E4D00::sub_002E4D00()
{
    int r_eax, r_edi;
    unsigned short t2;

    r_eax = 0;
    m_Field34 = (unsigned char)(m_Field34 | 6);
    if (m_Field32) {
        r_edi = 0;
        if (m_Field30) {
            do {
                r_eax = m_Field24;
                r_eax = *(int*)(r_eax + (r_edi * 4));
                r_eax = sub_002E44C0(r_eax, (*(unsigned short*)(r_eax + 2) * 284) + m_Field2C + 12);
                t2 = m_Field30;
                r_edi += 1;
            } while (r_edi != t2);
        }
    }
    sub_002E4900();
}
