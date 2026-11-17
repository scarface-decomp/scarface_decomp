// bin: xb
// va: 0x001D7F80
// tool: the portal's starter code (no AI)
// sub_001D7F80 (0x001D7F80, 75 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;
extern "C" char DAT_003C6E9C[];

class Class_001D7F80
{
public:
    Class_001D7F80* sub_001D7F80(int a1, int a2);
    void sub_0002BEE0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    int m_Field24; // +0x24
    float m_Field28; // +0x28
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
    int m_Field34; // +0x34
    int m_Field38; // +0x38
};

Class_001D7F80* Class_001D7F80::sub_001D7F80(int a1, int a2)
{
    float t2;

    sub_0002BEE0(a1, a2);
    t2 = DAT_0039D65C;
    m_Field22 = false;
    m_Field2C = 0;
    m_Field30 = 0;
    m_Field34 = 0;
    m_Field38 = 0;
    m_Field20 = 65535;
    m_Field00 = (int)DAT_003C6E9C;
    m_Field24 = 5;
    m_Field28 = t2;
    return this;
}
