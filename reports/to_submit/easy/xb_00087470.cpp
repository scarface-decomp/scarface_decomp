// bin: xb
// va: 0x00087470
// tool: the portal's starter code (no AI)
// sub_00087470 (0x00087470, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003A3F00;
extern "C" float DAT_003D1058;

class Class_00087470
{
public:
    Class_00087470* sub_00087470();
    bool m_Field00; // +0x00
    char m_pad01[0x3];
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
    unsigned short m_Field20; // +0x20
};

Class_00087470* Class_00087470::sub_00087470()
{
    m_Field14 = 0.0f;
    m_Field00 = false;
    m_Field04 = 0;
    m_Field08 = 0;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field18 = DAT_003A3F00;
    m_Field1C = DAT_003D1058;
    m_Field20 = 65535;
    return this;
}
