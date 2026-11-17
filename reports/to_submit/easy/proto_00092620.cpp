// bin: proto
// va: 0x00092620
// tool: the portal's starter code (no AI)
// sub_00092620 (0x00092620, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0009D020(void);

class Class_00092620
{
public:
    Class_00092620* sub_00092620();
    char m_pad00[0x14];
    float m_Field14; // +0x14
    float m_Field18; // +0x18
};

Class_00092620* Class_00092620::sub_00092620()
{
    sub_0009D020();
    m_Field14 = 0.0f;
    m_Field18 = 0.0f;
    return this;
}
