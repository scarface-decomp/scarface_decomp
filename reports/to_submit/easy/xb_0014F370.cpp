// bin: xb
// va: 0x0014F370
// tool: the portal's starter code (no AI)
// sub_0014F370 (0x0014F370, 84 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldE8
{
    void sub_001522C0();
};

extern "C" char DAT_003B2E44[];

class Class_0014F370
{
public:
    Class_0014F370* sub_0014F370(int a1, int a2);
    void sub_00152810(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x7C];
    int m_Field80; // +0x80
    char m_pad84[0x28];
    int m_FieldAC; // +0xAC
    int m_FieldB0; // +0xB0
    char m_padB4[0x8];
    float m_FieldBC; // +0xBC
    char m_padC0[0x28];
    FieldE8 m_FieldE8; // +0xE8
    char m_padE9[0x3];
    int m_FieldEC; // +0xEC
};

Class_0014F370* Class_0014F370::sub_0014F370(int a1, int a2)
{
    sub_00152810(a1, a2);
    m_Field00 = (int)DAT_003B2E44;
    m_FieldE8.sub_001522C0();
    m_FieldB0 = 0;
    m_FieldAC = 0;
    m_FieldEC = 0;
    m_Field80 = 6;
    m_FieldBC = 0.0f;
    return this;
}
