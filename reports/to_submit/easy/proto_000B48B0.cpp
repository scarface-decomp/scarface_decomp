// bin: proto
// va: 0x000B48B0
// tool: the portal's starter code (no AI)
// sub_000B48B0 (0x000B48B0, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_000B5200();
};

struct Field54
{
    void sub_000B5240();
};

struct Field60
{
    void sub_000ABA80();
};

struct Field9C
{
    void sub_000AB5A0();
};

struct FieldF4
{
    void sub_000B52F0();
};

class Class_000B48B0
{
public:
    void sub_000B48B0();
    char m_pad00[0x8];
    Field08 m_Field08; // +0x08
    char m_pad09[0x1B];
    bool m_Field24; // +0x24
    char m_pad25[0x1];
    bool m_Field26; // +0x26
    char m_pad27[0x1];
    float m_Field28; // +0x28
    char m_pad2C[0x28];
    Field54 m_Field54; // +0x54
    char m_pad55[0xB];
    Field60 m_Field60; // +0x60
    char m_pad61[0x3B];
    Field9C m_Field9C; // +0x9C
    char m_pad9D[0x57];
    FieldF4 m_FieldF4; // +0xF4
};

void Class_000B48B0::sub_000B48B0()
{
    m_Field08.sub_000B5200();
    m_Field24 = false;
    m_Field26 = false;
    m_Field28 = 0.0f;
    m_Field54.sub_000B5240();
    m_Field60.sub_000ABA80();
    m_Field9C.sub_000AB5A0();
    m_FieldF4.sub_000B52F0();
}
