// bin: proto
// va: 0x001633B0
// tool: the portal's starter code (no AI)
// sub_001633B0 (0x001633B0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    void sub_00200310(int);
};

extern "C" char DAT_0037CD30[];
extern "C" char DAT_00394B8C[];
extern "C" void __cdecl sub_000205E0(void);

class Class_001633B0
{
public:
    Class_001633B0* sub_001633B0();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    Field14 m_Field14; // +0x14
    char m_pad15[0x3];
    float m_Field18; // +0x18
};

Class_001633B0* Class_001633B0::sub_001633B0()
{
    sub_000205E0();
    m_Field00 = (int)DAT_00394B8C;
    m_Field14.sub_00200310((int)DAT_0037CD30);
    m_Field18 = 0.0f;
    return this;
}
