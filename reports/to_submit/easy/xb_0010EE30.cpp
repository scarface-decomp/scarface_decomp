// bin: xb
// va: 0x0010EE30
// tool: the portal's starter code (no AI)
// sub_0010EE30 (0x0010EE30, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0010EE30
{
public:
    float sub_0010EE30();
    char m_pad00[0x84];
    int m_Field84; // +0x84
};

float Class_0010EE30::sub_0010EE30()
{
    return *(float*)(m_Field84 + 68);
}
