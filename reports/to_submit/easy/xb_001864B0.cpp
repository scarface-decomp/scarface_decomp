// bin: xb
// va: 0x001864B0
// tool: the portal's starter code (no AI)
// sub_001864B0 (0x001864B0, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_00242DF0(int);
};

extern "C" char DAT_0039D520[];
extern "C" char DAT_003B7C6C[];
extern "C" void __cdecl sub_00022950(void);

class Class_001864B0
{
public:
    Class_001864B0* sub_001864B0();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
    char m_pad15[0xF];
    float m_Field24; // +0x24
    int m_Field28; // +0x28
};

Class_001864B0* Class_001864B0::sub_001864B0()
{
    sub_00022950();
    m_Field00 = (int)DAT_003B7C6C;
    m_Field14.sub_00242DF0((int)DAT_0039D520);
    m_Field24 = 0.0f;
    m_Field28 = -1;
    return this;
}
