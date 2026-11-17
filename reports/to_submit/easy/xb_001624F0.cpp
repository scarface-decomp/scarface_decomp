// bin: xb
// va: 0x001624F0
// tool: the portal's starter code (no AI)
// sub_001624F0 (0x001624F0, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001624F0
{
public:
    int sub_001624F0();
    char m_pad00[0x90];
    int m_Field90; // +0x90
};

int Class_001624F0::sub_001624F0()
{
    return m_Field90 != 0;
}
