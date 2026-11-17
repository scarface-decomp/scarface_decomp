// bin: proto
// va: 0x0008F7C0
// tool: the portal's starter code (no AI)
// sub_0008F7C0 (0x0008F7C0, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003850E8;
extern "C" void __cdecl sub_0008F580(void);

class Class_0008F7C0
{
public:
    Class_0008F7C0* sub_0008F7C0();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    int m_Field28; // +0x28
    char m_pad2C[0xC];
    float m_Field38; // +0x38
    float m_Field3C; // +0x3C
    float m_Field40; // +0x40
};

Class_0008F7C0* Class_0008F7C0::sub_0008F7C0()
{
    float t1;

    t1 = DAT_003850E8;
    m_Field00 = 0;
    m_Field04 = 0;
    m_Field08 = 0;
    m_Field0C = 0;
    m_Field10 = 0;
    m_Field28 = 0;
    m_Field38 = t1;
    m_Field3C = t1;
    m_Field40 = t1;
    m_Field14 = 0 | -1;
    m_Field18 = 0 | -1;
    m_Field1C = 0 | -1;
    m_Field20 = 0 | -1;
    m_Field24 = 0 | -1;
    sub_0008F580();
    return this;
}
