// bin: xb
// va: 0x000B9670
// tool: the portal's starter code (no AI)
// sub_000B9670 (0x000B9670, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D664;

class Class_000B9670
{
public:
    Class_000B9670* sub_000B9670();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    bool m_Field0C; // +0x0C
    char m_pad0D[0x3];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
    float m_Field24; // +0x24
    float m_Field28; // +0x28
    float m_Field2C; // +0x2C
    float m_Field30; // +0x30
    bool m_Field34; // +0x34
};

Class_000B9670* Class_000B9670::sub_000B9670()
{
    float t1;

    t1 = DAT_0039D664;
    m_Field00 = 0;
    m_Field04 = 0;
    m_Field08 = 0;
    m_Field0C = false;
    m_Field10 = 0;
    m_Field14 = 0;
    m_Field18 = t1;
    m_Field1C = t1;
    m_Field20 = t1;
    m_Field24 = t1;
    m_Field28 = t1;
    m_Field2C = t1;
    m_Field30 = t1;
    m_Field34 = false;
    return this;
}
