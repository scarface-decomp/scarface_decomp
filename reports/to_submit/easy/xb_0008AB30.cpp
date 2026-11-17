// bin: xb
// va: 0x0008AB30
// tool: the portal's starter code (no AI)
// sub_0008AB30 (0x0008AB30, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004814A8;

class Class_0008AB30
{
public:
    Class_0008AB30* sub_0008AB30();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    float m_Field0C; // +0x0C
    int m_Field10; // +0x10
    bool m_Field14; // +0x14
    char m_pad15[0x3];
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
    float m_Field24; // +0x24
    float m_Field28; // +0x28
    float m_Field2C; // +0x2C
};

Class_0008AB30* Class_0008AB30::sub_0008AB30()
{
    m_Field00 = 0;
    m_Field04 = 0;
    m_Field10 = 0;
    m_Field14 = false;
    m_Field08 = -1;
    m_Field0C = 0.0f;
    m_Field18 = 0.0f;
    m_Field1C = 0.0f;
    m_Field20 = 0.0f;
    m_Field24 = 0.0f;
    m_Field28 = 0.0f;
    m_Field2C = 0.0f;
    DAT_004814A8 += 1;
    return this;
}
