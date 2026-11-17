// bin: xb
// va: 0x000C22B0
// tool: the portal's starter code (no AI)
// sub_000C22B0 (0x000C22B0, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_000C2AE0();
};

struct Field5C
{
    void sub_000C2B20();
};

struct Field64
{
    void sub_000B91C0();
};

struct FieldA0
{
    void sub_000B8CE0();
};

struct FieldF8
{
    void sub_000C2BC0();
};

class Class_000C22B0
{
public:
    void sub_000C22B0();
    char m_pad00[0x8];
    Field08 m_Field08; // +0x08
    char m_pad09[0x1B];
    bool m_Field24; // +0x24
    char m_pad25[0x8];
    bool m_Field2D; // +0x2D
    char m_pad2E[0x2];
    float m_Field30; // +0x30
    char m_pad34[0x28];
    Field5C m_Field5C; // +0x5C
    char m_pad5D[0x7];
    Field64 m_Field64; // +0x64
    char m_pad65[0x3B];
    FieldA0 m_FieldA0; // +0xA0
    char m_padA1[0x57];
    FieldF8 m_FieldF8; // +0xF8
};

void Class_000C22B0::sub_000C22B0()
{
    m_Field08.sub_000C2AE0();
    m_Field24 = false;
    m_Field2D = false;
    m_Field30 = 0.0f;
    m_Field5C.sub_000C2B20();
    m_Field64.sub_000B91C0();
    m_FieldA0.sub_000B8CE0();
    m_FieldF8.sub_000C2BC0();
}
