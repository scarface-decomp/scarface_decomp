// bin: proto
// va: 0x0019FFF0
// tool: the portal's starter code (no AI)
// sub_0019FFF0 (0x0019FFF0, 75 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE60;
extern "C" char DAT_003A0E5C[];

class Class_0019FFF0
{
public:
    Class_0019FFF0* sub_0019FFF0(int a1, int a2);
    void sub_00028470(int, int);
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

Class_0019FFF0* Class_0019FFF0::sub_0019FFF0(int a1, int a2)
{
    float t2;

    sub_00028470(a1, a2);
    t2 = DAT_0037CE60;
    m_Field22 = false;
    m_Field2C = 0;
    m_Field30 = 0;
    m_Field34 = 0;
    m_Field38 = 0;
    m_Field20 = 65535;
    m_Field00 = (int)DAT_003A0E5C;
    m_Field24 = 5;
    m_Field28 = t2;
    return this;
}
