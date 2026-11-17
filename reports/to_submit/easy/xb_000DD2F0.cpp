// bin: xb
// va: 0x000DD2F0
// tool: the portal's starter code (no AI)
// sub_000DD2F0 (0x000DD2F0, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A68E4[];
extern "C" void __cdecl sub_00021850(void);

class Class_000DD2F0
{
public:
    Class_000DD2F0* sub_000DD2F0();
    int m_Field00; // +0x00
    char m_pad04[0xC];
    int m_Field10; // +0x10
    float m_Field14; // +0x14
};

Class_000DD2F0* Class_000DD2F0::sub_000DD2F0()
{
    sub_00021850();
    m_Field00 = (int)DAT_003A68E4;
    m_Field10 = 5;
    m_Field14 = 0.0f;
    return this;
}
