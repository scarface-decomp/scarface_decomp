// bin: xb
// va: 0x000E91C0
// tool: the portal's starter code (no AI)
// sub_000E91C0 (0x000E91C0, 78 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field30
{
    void sub_000C3030();
};

struct Field3C
{
    void sub_00241970();
};

extern "C" float DAT_0039D65C;
extern "C" char DAT_003A89B4[];
extern "C" void __cdecl sub_00022990(void);

class Class_000E91C0
{
public:
    Class_000E91C0* sub_000E91C0();
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
    bool m_Field39; // +0x39
    char m_pad3A[0x2];
    Field3C m_Field3C; // +0x3C
};

Class_000E91C0* Class_000E91C0::sub_000E91C0()
{
    float t2;

    sub_00022990();
    m_Field1C = 0.0f;
    t2 = DAT_0039D65C;
    m_Field00 = (int)DAT_003A89B4;
    m_Field20 = t2;
    m_Field24 = t2;
    m_Field28 = t2;
    m_Field2C = t2;
    m_Field30.sub_000C3030();
    m_Field38 = false;
    m_Field39 = false;
    m_Field3C.sub_00241970();
    return this;
}
