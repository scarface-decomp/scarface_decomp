// bin: xb
// va: 0x0009E400
// tool: the portal's starter code (no AI)
// sub_0009E400 (0x0009E400, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000A8FB0(void);

class Class_0009E400
{
public:
    Class_0009E400* sub_0009E400();
    char m_pad00[0x14];
    float m_Field14; // +0x14
    float m_Field18; // +0x18
};

Class_0009E400* Class_0009E400::sub_0009E400()
{
    sub_000A8FB0();
    m_Field14 = 0.0f;
    m_Field18 = 0.0f;
    return this;
}
