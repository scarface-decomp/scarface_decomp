// bin: xb
// va: 0x001AD600
// tool: the portal's starter code (no AI)
// sub_001AD600 (0x001AD600, 93 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BF34C[];

class Class_001AD600
{
public:
    Class_001AD600* sub_001AD600(int a1, int a2);
    void sub_001930D0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x60];
    int m_Field64; // +0x64
    int m_Field68; // +0x68
    int m_Field6C; // +0x6C
    int m_Field70; // +0x70
    int m_Field74; // +0x74
    int m_Field78; // +0x78
    float m_Field7C; // +0x7C
    int m_Field80; // +0x80
    int m_Field84; // +0x84
    int m_Field88; // +0x88
    int m_Field8C; // +0x8C
};

Class_001AD600* Class_001AD600::sub_001AD600(int a1, int a2)
{
    sub_001930D0(a1, a2);
    m_Field64 = 0;
    m_Field68 = 0;
    m_Field6C = 0;
    m_Field70 = 0;
    m_Field74 = 0;
    m_Field80 = 0;
    m_Field84 = 0;
    m_Field88 = 500;
    m_Field8C = 500;
    m_Field00 = (int)DAT_003BF34C;
    m_Field78 = 5;
    m_Field7C = 0.0f;
    return this;
}
