// bin: xb
// va: 0x001FEDD0
// tool: the portal's starter code (no AI)
// sub_001FEDD0 (0x001FEDD0, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;
extern "C" float DAT_003A49EC;
extern "C" char DAT_003CB4E4[];
extern "C" float DAT_003D111C;

class Class_001FEDD0
{
public:
    Class_001FEDD0* sub_001FEDD0(int a1, int a2);
    void sub_0002BEE0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    float m_Field24; // +0x24
    float m_Field28; // +0x28
    float m_Field2C; // +0x2C
    float m_Field30; // +0x30
};

Class_001FEDD0* Class_001FEDD0::sub_001FEDD0(int a1, int a2)
{
    float t2, t3, t4;

    sub_0002BEE0(a1, a2);
    t2 = DAT_0039D664;
    t3 = DAT_003A49EC;
    m_Field24 = t2;
    m_Field2C = t2;
    t4 = DAT_003D111C;
    m_Field20 = 65535;
    m_Field22 = false;
    m_Field00 = (int)DAT_003CB4E4;
    m_Field28 = t3;
    m_Field30 = t4;
    return this;
}
