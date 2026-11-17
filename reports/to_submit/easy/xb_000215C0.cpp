// bin: xb
// va: 0x000215C0
// tool: the portal's starter code (no AI)
// sub_000215C0 (0x000215C0, 95 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    void sub_000873C0();
};

struct Field5C
{
    void sub_00087410();
};

extern "C" float DAT_0039D664;

class Class_000215C0
{
public:
    Class_000215C0* sub_000215C0();
    int m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
    float m_Field0C; // +0x0C
    float m_Field10; // +0x10
    float m_Field14; // +0x14
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
    float m_Field24; // +0x24
    float m_Field28; // +0x28
    float m_Field2C; // +0x2C
    Field30 m_Field30; // +0x30
    char m_pad31[0x2B];
    Field5C m_Field5C; // +0x5C
};

Class_000215C0* Class_000215C0::sub_000215C0()
{
    float t1;

    t1 = DAT_0039D664;
    m_Field00 = 0;
    m_Field04 = 0.0f;
    m_Field08 = t1;
    m_Field0C = t1;
    m_Field10 = t1;
    m_Field14 = t1;
    m_Field18 = 0.0f;
    m_Field1C = t1;
    m_Field20 = 0.0f;
    m_Field24 = 0.0f;
    m_Field28 = 0.0f;
    m_Field2C = t1;
    m_Field30.sub_000873C0();
    m_Field5C.sub_00087410();
    return this;
}
