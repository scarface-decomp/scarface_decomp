// bin: xb
// va: 0x001866D0
// tool: the portal's starter code (no AI)
// sub_001866D0 (0x001866D0, 72 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_00242DF0(int);
};

extern "C" char DAT_0039D520[];
extern "C" char DAT_003B7E04[];
extern "C" void __cdecl sub_00022950(void);

class Class_001866D0
{
public:
    Class_001866D0* sub_001866D0();
    int m_Field00; // +0x00
    char m_pad04[0x8];
    float m_Field0C; // +0x0C
    char m_pad10[0x4];
    Field14 m_Field14; // +0x14
    char m_pad15[0x3];
    Field14 m_Field18; // +0x18
    char m_pad19[0x3];
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
    float m_Field24; // +0x24
    float m_Field28; // +0x28
};

Class_001866D0* Class_001866D0::sub_001866D0()
{
    sub_00022950();
    m_Field00 = (int)DAT_003B7E04;
    m_Field14.sub_00242DF0((int)DAT_0039D520);
    m_Field18.sub_00242DF0((int)DAT_0039D520);
    m_Field28 = 0.0f;
    m_Field0C = 0.0f;
    m_Field24 = 0.0f;
    m_Field20 = 0.0f;
    m_Field1C = 0.0f;
    return this;
}
