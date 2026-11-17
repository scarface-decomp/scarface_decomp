// bin: proto
// va: 0x000D6B90
// tool: the portal's starter code (no AI)
// sub_000D6B90 (0x000D6B90, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    void sub_000AABF0();
};

struct Field3C
{
    void sub_001FCAB0();
};

extern "C" float DAT_0037CE60;
extern "C" char DAT_003878DC[];
extern "C" void __cdecl sub_00020610(void);

class Class_000D6B90
{
public:
    Class_000D6B90* sub_000D6B90();
    int m_Field00; // +0x00
    char m_pad04[0x18];
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
    float m_Field24; // +0x24
    float m_Field28; // +0x28
    float m_Field2C; // +0x2C
    Field30 m_Field30; // +0x30
    char m_pad31[0x7];
    bool m_Field38; // +0x38
    char m_pad39[0x3];
    Field3C m_Field3C; // +0x3C
};

Class_000D6B90* Class_000D6B90::sub_000D6B90()
{
    float t2;

    sub_00020610();
    m_Field1C = 0.0f;
    t2 = DAT_0037CE60;
    m_Field00 = (int)DAT_003878DC;
    m_Field20 = t2;
    m_Field24 = t2;
    m_Field28 = t2;
    m_Field2C = t2;
    m_Field30.sub_000AABF0();
    m_Field38 = false;
    m_Field3C.sub_001FCAB0();
    return this;
}
