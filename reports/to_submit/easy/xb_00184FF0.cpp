// bin: xb
// va: 0x00184FF0
// tool: the portal's starter code (no AI)
// sub_00184FF0 (0x00184FF0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_00242DF0(int);
};

extern "C" char DAT_0039D520[];
extern "C" char DAT_003B7144[];
extern "C" void __cdecl sub_00022950(void);

class Class_00184FF0
{
public:
    Class_00184FF0* sub_00184FF0();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
    char m_pad15[0x3];
    float m_Field18; // +0x18
};

Class_00184FF0* Class_00184FF0::sub_00184FF0()
{
    sub_00022950();
    m_Field00 = (int)DAT_003B7144;
    m_Field14.sub_00242DF0((int)DAT_0039D520);
    m_Field18 = 0.0f;
    return this;
}
