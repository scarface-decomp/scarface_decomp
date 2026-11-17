// bin: xb
// va: 0x0014A210
// tool: the portal's starter code (no AI)
// sub_0014A210 (0x0014A210, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003B2040;
extern "C" char DAT_003B2A0C[];

class Class_0014A210
{
public:
    Class_0014A210* sub_0014A210(int a1, int a2);
    void sub_0002BEE0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    float m_Field28; // +0x28
    int m_Field2C; // +0x2C
};

Class_0014A210* Class_0014A210::sub_0014A210(int a1, int a2)
{
    float t2;

    sub_0002BEE0(a1, a2);
    t2 = DAT_003B2040;
    m_Field20 = 0;
    m_Field24 = 0;
    m_Field00 = (int)DAT_003B2A0C;
    m_Field28 = t2;
    m_Field2C = 2;
    return this;
}
