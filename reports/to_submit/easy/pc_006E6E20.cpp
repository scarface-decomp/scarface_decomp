// bin: pc
// va: 0x006E6E20
// tool: the portal's starter code (no AI)
// sub_006E6E20 (0x006E6E20, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006DEC00(void);
extern "C" void __cdecl sub_006DF050(int);

class Class_006E6E20
{
public:
    Class_006E6E20* sub_006E6E20();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    char m_pad18[0x14];
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
    int m_Field34; // +0x34
    int m_Field38; // +0x38
};

Class_006E6E20* Class_006E6E20::sub_006E6E20()
{
    m_Field10 = 0;
    m_Field2C = 0;
    m_Field30 = 0;
    m_Field34 = 0;
    m_Field38 = 0;
    sub_006DEC00();
    m_Field00 = 0;
    m_Field08 = 0;
    m_Field04 = 0;
    m_Field0C = 0;
    sub_006DF050((int)(&m_Field14));
    return this;
}
