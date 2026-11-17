// bin: xb
// va: 0x001527D0
// tool: the portal's starter code (no AI)
// sub_001527D0 (0x001527D0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001527D0
{
public:
    float sub_001527D0();
    char m_pad00[0x84];
    int m_Field84; // +0x84
};

float Class_001527D0::sub_001527D0()
{
    return *(float*)(m_Field84 + 16);
}
