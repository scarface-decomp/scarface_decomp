// bin: xb
// va: 0x001CB780
// tool: the portal's starter code (no AI)
// sub_001CB780 (0x001CB780, 83 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C4634[];
extern "C" char DAT_003C464C[];
extern "C" unsigned char DAT_00492006;

class Class_001CB780
{
public:
    int sub_001CB780(int a1, int a2);
    void sub_001CA680(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x60];
    int m_Field64; // +0x64
    char m_pad68[0x14];
    int m_Field7C; // +0x7C
    int m_Field80; // +0x80
    int m_Field84; // +0x84
    int m_Field88; // +0x88
    int m_Field8C; // +0x8C
};

int Class_001CB780::sub_001CB780(int a1, int a2)
{
    int r_eax;

    r_eax = a2;
    sub_001CA680(a1, a2);
    r_eax = 0;
    m_Field7C = 0;
    m_Field80 = 0;
    m_Field84 = 0;
    m_Field88 = 0;
    m_Field8C = 0;
    m_Field00 = (int)DAT_003C464C;
    m_Field64 = (int)DAT_003C4634;
    r_eax = (int)this;
    if (DAT_00492006) {
        m_Field7C = 3;
    }
    return r_eax;
}
