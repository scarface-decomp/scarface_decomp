// bin: xb
// va: 0x001862D0
// tool: the portal's starter code (no AI)
// sub_001862D0 (0x001862D0, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_00242DF0(int);
};

extern "C" char DAT_0039D520[];
extern "C" char DAT_003B782C[];
extern "C" void __cdecl sub_00022950(void);

class Class_001862D0
{
public:
    Class_001862D0* sub_001862D0();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
    char m_pad15[0x3];
    float m_Field18; // +0x18
    float m_Field1C; // +0x1C
    float m_Field20; // +0x20
    float m_Field24; // +0x24
};

Class_001862D0* Class_001862D0::sub_001862D0()
{
    sub_00022950();
    m_Field00 = (int)DAT_003B782C;
    m_Field14.sub_00242DF0((int)DAT_0039D520);
    m_Field24 = 0.0f;
    m_Field20 = 0.0f;
    m_Field1C = 0.0f;
    m_Field18 = 0.0f;
    return this;
}
