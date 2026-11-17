// bin: proto
// va: 0x0002BB80
// tool: the portal's starter code (no AI)
// sub_0002BB80 (0x0002BB80, 63 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037F31C[];

class Class_0002BB80
{
public:
    Class_0002BB80* sub_0002BB80(int a1, int a2);
    void sub_00028470(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    char m_pad22[0x2];
    int m_Field24; // +0x24
    int m_Field28; // +0x28
    float m_Field2C; // +0x2C
    bool m_Field30; // +0x30
    bool m_Field31; // +0x31
    bool m_Field32; // +0x32
};

Class_0002BB80* Class_0002BB80::sub_0002BB80(int a1, int a2)
{
    sub_00028470(a1, a2);
    m_Field24 = 0;
    m_Field28 = 0;
    m_Field30 = false;
    m_Field31 = false;
    m_Field32 = false;
    m_Field00 = (int)DAT_0037F31C;
    m_Field20 = 65535;
    m_Field2C = 0.0f;
    return this;
}
