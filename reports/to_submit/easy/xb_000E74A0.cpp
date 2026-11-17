// bin: xb
// va: 0x000E74A0
// tool: the portal's starter code (no AI)
// sub_000E74A0 (0x000E74A0, 90 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field1C
{
    void sub_00242DF0(int);
};

extern "C" float DAT_0039D65C;
extern "C" float DAT_0039D664;
extern "C" char DAT_003A7D64[];
extern "C" int DAT_003D4940;
extern "C" void __cdecl sub_00022990(void);

class Class_000E74A0
{
public:
    Class_000E74A0* sub_000E74A0();
    int m_Field00; // +0x00
    char m_pad04[0x18];
    Field1C m_Field1C; // +0x1C
    char m_pad1D[0x3];
    int m_Field20; // +0x20
    float m_Field24; // +0x24
    float m_Field28; // +0x28
    float m_Field2C; // +0x2C
    bool m_Field30; // +0x30
    bool m_Field31; // +0x31
    bool m_Field32; // +0x32
    unsigned char m_Field33; // +0x33
};

Class_000E74A0* Class_000E74A0::sub_000E74A0()
{
    float t3, t5;
    unsigned char t4;

    sub_00022990();
    m_Field00 = (int)DAT_003A7D64;
    m_Field1C.sub_00242DF0(DAT_003D4940);
    t3 = DAT_0039D664;
    t4 = m_Field33;
    m_Field20 = 0;
    m_Field30 = false;
    m_Field31 = false;
    m_Field24 = t3;
    m_Field28 = 0.0f;
    t5 = DAT_0039D65C;
    m_Field32 = true;
    m_Field2C = t5;
    m_Field33 = (unsigned char)(t4 | 1);
    return this;
}
